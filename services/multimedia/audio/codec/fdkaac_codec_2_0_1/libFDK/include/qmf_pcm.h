/* -----------------------------------------------------------------------------
Software License for The Third-Party Modified Version of the Fraunhofer FDK AAC Codec Library for Android

© Copyright  1995 - 2018 Fraunhofer-Gesellschaft zur Förderung der angewandten
Forschung e.V. All rights reserved.

 1.    INTRODUCTION
The Third-Party Modified Version of the Fraunhofer FDK AAC Codec Library for Android ("FDK AAC Codec") is software
that implements the MPEG Advanced Audio Coding ("AAC") encoding and decoding
scheme for digital audio. This FDK AAC Codec software is intended to be used on
a wide variety of Android devices.

AAC's HE-AAC and HE-AAC v2 versions are regarded as today's most efficient
general perceptual audio codecs. AAC-ELD is considered the best-performing
full-bandwidth communications codec by independent studies and is widely
deployed. AAC has been standardized by ISO and IEC as part of the MPEG
specifications.

Patent licenses for necessary patent claims for the FDK AAC Codec (including
those of Fraunhofer) may be obtained through Via Licensing
(www.vialicensing.com) or through the respective patent owners individually for
the purpose of encoding or decoding bit streams in products that are compliant
with the ISO/IEC MPEG audio standards. Please note that most manufacturers of
Android devices already license these patent claims through Via Licensing or
directly from the patent owners, and therefore FDK AAC Codec software may
already be covered under those patent licenses when it is used for those
licensed purposes only.

Commercially-licensed AAC software libraries, including floating-point versions
with enhanced sound quality, are also available from Fraunhofer. Users are
encouraged to check the Fraunhofer website for additional applications
information and documentation.

2.    COPYRIGHT LICENSE

Redistribution and use in source and binary forms, with or without modification,
are permitted without payment of copyright license fees provided that you
satisfy the following conditions:

You must retain the complete text of this software license in redistributions of
the FDK AAC Codec or your modifications thereto in source code form.

You must retain the complete text of this software license in the documentation
and/or other materials provided with redistributions of the FDK AAC Codec or
your modifications thereto in binary form. You must make available free of
charge copies of the complete source code of the FDK AAC Codec and your
modifications thereto to recipients of copies in binary form.

The name of Fraunhofer may not be used to endorse or promote products derived
from this library without prior written permission.

You may not charge copyright license fees for anyone to use, copy or distribute
the FDK AAC Codec software or your modifications thereto.

Your modified versions of the FDK AAC Codec must carry prominent notices stating
that you changed the software and the date of any change. For modified versions
of the FDK AAC Codec, the term "Fraunhofer FDK AAC Codec Library for Android"
must be replaced by the term "Third-Party Modified Version of the Fraunhofer FDK
AAC Codec Library for Android."

3.    NO PATENT LICENSE

NO EXPRESS OR IMPLIED LICENSES TO ANY PATENT CLAIMS, including without
limitation the patents of Fraunhofer, ARE GRANTED BY THIS SOFTWARE LICENSE.
Fraunhofer provides no warranty of patent non-infringement with respect to this
software.

You may use this FDK AAC Codec software or modifications thereto only for
purposes that are authorized by appropriate patent licenses.

4.    DISCLAIMER

This FDK AAC Codec software is provided by Fraunhofer on behalf of the copyright
holders and contributors "AS IS" and WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES,
including but not limited to the implied warranties of merchantability and
fitness for a particular purpose. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
CONTRIBUTORS BE LIABLE for any direct, indirect, incidental, special, exemplary,
or consequential damages, including but not limited to procurement of substitute
goods or services; loss of use, data, or profits, or business interruption,
however caused and on any theory of liability, whether in contract, strict
liability, or tort (including negligence), arising in any way out of the use of
this software, even if advised of the possibility of such damage.

5.    CONTACT INFORMATION

Fraunhofer Institute for Integrated Circuits IIS
Attention: Audio and Multimedia Departments - FDK AAC LL
Am Wolfsmantel 33
91058 Erlangen, Germany

www.iis.fraunhofer.de/amm
amm-info@iis.fraunhofer.de
----------------------------------------------------------------------------- */

/******************* Library for basic calculation routines ********************

   Author(s):   Markus Lohwasser, Josef Hoepfl, Manuel Jander

   Description: QMF filterbank

*******************************************************************************/

#ifndef QMF_PCM_H
#define QMF_PCM_H

/*
   All Synthesis functions dependent on datatype INT_PCM_QMFOUT
   Should only be included by qmf.cpp, but not compiled separately, please
   exclude compilation from project, if done otherwise. Is optional included
   twice to duplicate all functions with two different pre-definitions, as:
        #define INT_PCM_QMFOUT LONG
    and ...
        #define INT_PCM_QMFOUT SHORT
    needed to run QMF synthesis in both 16bit and 32bit sample output format.
*/

#define QSSCALE (0)
#define FX_DBL2FX_QSS(x) (x)
#define FX_QSS2FX_DBL(x) (x)

/*!
  \brief Perform Synthesis Prototype Filtering on a single slot of input data.

  The filter takes 2 * qmf->no_channels of input data and
  generates qmf->no_channels time domain output samples.
*/
/* static */
#ifndef FUNCTION_qmfSynPrototypeFirSlot
void qmfSynPrototypeFirSlot(
#else
void qmfSynPrototypeFirSlot_fallback(
#endif
    HANDLE_QMF_FILTER_BANK qmf,
    FIXP_DBL *RESTRICT realSlot,      /*!< Input: Pointer to real Slot */
    FIXP_DBL *RESTRICT imagSlot,      /*!< Input: Pointer to imag Slot */
    INT_PCM_QMFOUT *RESTRICT timeOut, /*!< Time domain data */
    int stride) {
  FIXP_QSS *FilterStates = (FIXP_QSS *)qmf->FilterStates;
  int no_channels = qmf->no_channels;
  const FIXP_PFT *p_Filter = qmf->p_filter;
  int p_stride = qmf->p_stride;
  int j;
  FIXP_QSS *RESTRICT sta = FilterStates;
  const FIXP_PFT *RESTRICT p_flt, *RESTRICT p_fltm;
  int scale = (DFRACT_BITS - SAMPLE_BITS_QMFOUT) - 1 - qmf->outScalefactor -
              qmf->outGain_e;

  p_flt =
      p_Filter + p_stride * QMF_NO_POLY; /*                     5th of 330 */
  p_fltm = p_Filter + (qmf->FilterSize / 2) -
           p_stride * QMF_NO_POLY; /* 5 + (320 - 2*5) = 315th of 330 */

  FIXP_SGL gain = FX_DBL2FX_SGL(qmf->outGain_m);

  FIXP_DBL rnd_val = 0;

  if (scale > 0) {
    if (scale < (DFRACT_BITS - 1))
      rnd_val = FIXP_DBL(1 << (scale - 1));
    else
      scale = (DFRACT_BITS - 1);
  } else {
    scale = fMax(scale, -(DFRACT_BITS - 1));
  }

  for (j = no_channels - 1; j >= 0; j--) {
    FIXP_DBL imag = imagSlot[j]; /* no_channels-1 .. 0 */
    FIXP_DBL real = realSlot[j]; /* no_channels-1 .. 0 */
    {
      INT_PCM_QMFOUT tmp;
      FIXP_DBL Are = fMultAddDiv2(FX_QSS2FX_DBL(sta[0]), p_fltm[0], real);

      /* This PCM formatting performs:
         - multiplication with 16-bit gain, if not -1.0f
         - rounding, if shift right is applied
         - apply shift left (or right) with saturation to 32 (or 16) bits
         - store output with --stride in 32 (or 16) bit format
      */
      if (gain != (FIXP_SGL)(-32768)) /* -1.0f */
      {
        Are = fMult(Are, gain);
      }
      if (scale >= 0) {
        FDK_ASSERT(
            Are <=
            (Are + rnd_val)); /* Round-addition must not overflow, might be
                                 equal for rnd_val=0 */
        tmp = (INT_PCM_QMFOUT)(
            SATURATE_RIGHT_SHIFT(Are + rnd_val, scale, SAMPLE_BITS_QMFOUT));
      } else {
        tmp = (INT_PCM_QMFOUT)(
            SATURATE_LEFT_SHIFT(Are, -scale, SAMPLE_BITS_QMFOUT));
      }

      { timeOut[(j)*stride] = tmp; }
    }

    sta[0] = FX_DBL2FX_QSS(fMultAddDiv2(FX_QSS2FX_DBL(sta[1]), p_flt[4], imag));
    sta[1] =
        FX_DBL2FX_QSS(fMultAddDiv2(FX_QSS2FX_DBL(sta[2]), p_fltm[1], real));
    sta[2] = FX_DBL2FX_QSS(fMultAddDiv2(FX_QSS2FX_DBL(sta[3]), p_flt[3], imag));
    sta[3] =
        FX_DBL2FX_QSS(fMultAddDiv2(FX_QSS2FX_DBL(sta[4]), p_fltm[2], real));
    sta[4] = FX_DBL2FX_QSS(fMultAddDiv2(FX_QSS2FX_DBL(sta[5]), p_flt[2], imag));
    sta[5] =
        FX_DBL2FX_QSS(fMultAddDiv2(FX_QSS2FX_DBL(sta[6]), p_fltm[3], real));
    sta[6] = FX_DBL2FX_QSS(fMultAddDiv2(FX_QSS2FX_DBL(sta[7]), p_flt[1], imag));
    sta[7] =
        FX_DBL2FX_QSS(fMultAddDiv2(FX_QSS2FX_DBL(sta[8]), p_fltm[4], real));
    sta[8] = FX_DBL2FX_QSS(fMultDiv2(p_flt[0], imag));
    p_flt += (p_stride * QMF_NO_POLY);
    p_fltm -= (p_stride * QMF_NO_POLY);
    sta += 9;  // = (2*QMF_NO_POLY-1);
  }
}

#ifndef FUNCTION_qmfSynPrototypeFirSlot_NonSymmetric
/*!
  \brief Perform Synthesis Prototype Filtering on a single slot of input data.

  The filter takes 2 * qmf->no_channels of input data and
  generates qmf->no_channels time domain output samples.
*/
static void qmfSynPrototypeFirSlot_NonSymmetric(
    HANDLE_QMF_FILTER_BANK qmf,
    FIXP_DBL *RESTRICT realSlot,      /*!< Input: Pointer to real Slot */
    FIXP_DBL *RESTRICT imagSlot,      /*!< Input: Pointer to imag Slot */
    INT_PCM_QMFOUT *RESTRICT timeOut, /*!< Time domain data */
    int stride) {
  FIXP_QSS *FilterStates = (FIXP_QSS *)qmf->FilterStates;
  int no_channels = qmf->no_channels;
  const FIXP_PFT *p_Filter = qmf->p_filter;
  int p_stride = qmf->p_stride;
  int j;
  FIXP_QSS *RESTRICT sta = FilterStates;
  const FIXP_PFT *RESTRICT p_flt, *RESTRICT p_fltm;
  int scale = (DFRACT_BITS - SAMPLE_BITS_QMFOUT) - 1 - qmf->outScalefactor -
              qmf->outGain_e;

  p_flt = p_Filter; /*!< Pointer to first half of filter coefficients */
  p_fltm =
      &p_flt[qmf->FilterSize / 2]; /* at index 320, overall 640 coefficients */

  FIXP_SGL gain = FX_DBL2FX_SGL(qmf->outGain_m);

  FIXP_DBL rnd_val = (FIXP_DBL)0;

  if (scale > 0) {
    if (scale < (DFRACT_BITS - 1))
      rnd_val = FIXP_DBL(1 << (scale - 1));
    else
      scale = (DFRACT_BITS - 1);
  } else {
    scale = fMax(scale, -(DFRACT_BITS - 1));
  }

  for (j = no_channels - 1; j >= 0; j--) {
    FIXP_DBL imag = imagSlot[j]; /* no_channels-1 .. 0 */
    FIXP_DBL real = realSlot[j]; /* no_channels-1 .. 0 */
    {
      INT_PCM_QMFOUT tmp;
      FIXP_DBL Are = sta[0] + FX_DBL2FX_QSS(fMultDiv2(p_fltm[4], real));

      /* This PCM formatting performs:
         - multiplication with 16-bit gain, if not -1.0f
         - rounding, if shift right is applied
         - apply shift left (or right) with saturation to 32 (or 16) bits
         - store output with --stride in 32 (or 16) bit format
      */
      if (gain != (FIXP_SGL)(-32768)) /* -1.0f */
      {
        Are = fMult(Are, gain);
      }
      if (scale > 0) {
        FDK_ASSERT(Are <
                   (Are + rnd_val)); /* Round-addition must not overflow */
        tmp = (INT_PCM_QMFOUT)(
            SATURATE_RIGHT_SHIFT(Are + rnd_val, scale, SAMPLE_BITS_QMFOUT));
      } else {
        tmp = (INT_PCM_QMFOUT)(
            SATURATE_LEFT_SHIFT(Are, -scale, SAMPLE_BITS_QMFOUT));
      }
      timeOut[j * stride] = tmp;
    }

    sta[0] = sta[1] + FX_DBL2FX_QSS(fMultDiv2(p_flt[4], imag));
    sta[1] = sta[2] + FX_DBL2FX_QSS(fMultDiv2(p_fltm[3], real));
    sta[2] = sta[3] + FX_DBL2FX_QSS(fMultDiv2(p_flt[3], imag));

    sta[3] = sta[4] + FX_DBL2FX_QSS(fMultDiv2(p_fltm[2], real));
    sta[4] = sta[5] + FX_DBL2FX_QSS(fMultDiv2(p_flt[2], imag));
    sta[5] = sta[6] + FX_DBL2FX_QSS(fMultDiv2(p_fltm[1], real));
    sta[6] = sta[7] + FX_DBL2FX_QSS(fMultDiv2(p_flt[1], imag));

    sta[7] = sta[8] + FX_DBL2FX_QSS(fMultDiv2(p_fltm[0], real));
    sta[8] = FX_DBL2FX_QSS(fMultDiv2(p_flt[0], imag));

    p_flt += (p_stride * QMF_NO_POLY);
    p_fltm += (p_stride * QMF_NO_POLY);
    sta += 9;  // = (2*QMF_NO_POLY-1);
  }
}
#endif /* FUNCTION_qmfSynPrototypeFirSlot_NonSymmetric */

void qmfSynthesisFilteringSlot(HANDLE_QMF_FILTER_BANK synQmf,
                               const FIXP_DBL *realSlot,
                               const FIXP_DBL *imagSlot,
                               const int scaleFactorLowBand,
                               const int scaleFactorHighBand,
                               INT_PCM_QMFOUT *timeOut, const int stride,
                               FIXP_DBL *pWorkBuffer) {
  if (!(synQmf->flags & QMF_FLAG_LP))
    qmfInverseModulationHQ(synQmf, realSlot, imagSlot, scaleFactorLowBand,
                           scaleFactorHighBand, pWorkBuffer);
  else {
    if (synQmf->flags & QMF_FLAG_CLDFB) {
      qmfInverseModulationLP_odd(synQmf, realSlot, scaleFactorLowBand,
                                 scaleFactorHighBand, pWorkBuffer);
    } else {
      qmfInverseModulationLP_even(synQmf, realSlot, scaleFactorLowBand,
                                  scaleFactorHighBand, pWorkBuffer);
    }
  }

  if (synQmf->flags & QMF_FLAG_NONSYMMETRIC) {
    qmfSynPrototypeFirSlot_NonSymmetric(synQmf, pWorkBuffer,
                                        pWorkBuffer + synQmf->no_channels,
                                        timeOut, stride);
  } else {
    qmfSynPrototypeFirSlot(synQmf, pWorkBuffer,
                           pWorkBuffer + synQmf->no_channels, timeOut, stride);
  }
}

/*!
 *
 * \brief Perform complex-valued subband synthesis of the
 *        low band and the high band and store the
 *        time domain data in timeOut
 *
 * First step: Calculate the proper scaling factor of current
 * spectral data in qmfReal/qmfImag, old spectral data in the overlap
 * range and filter states.
 *
 * Second step: Perform Frequency-to-Time mapping with inverse
 * Modulation slot-wise.
 *
 * Third step: Perform FIR-filter slot-wise. To save space for filter
 * states, the MAC operations are executed directly on the filter states
 * instead of accumulating several products in the accumulator. The
 * buffer shift at the end of the function should be replaced by a
 * modulo operation, which is available on some DSPs.
 *
 * Last step: Copy the upper part of the spectral data to the overlap buffer.
 *
 * The qmf coefficient table is symmetric. The symmetry is exploited by
 * shrinking the coefficient table to half the size. The addressing mode
 * takes care of the symmetries.  If the #define #QMFTABLE_FULL is set,
 * coefficient addressing works on the full table size. The code will be
 * slightly faster and slightly more compact.
 *
 * Workbuffer requirement: 2 x sizeof(**QmfBufferReal) * synQmf->no_channels
 * The workbuffer must be aligned
 */
void qmfSynthesisFiltering(
    HANDLE_QMF_FILTER_BANK synQmf, /*!< Handle of Qmf Synthesis Bank  */
    FIXP_DBL **QmfBufferReal,      /*!< Low and High band, real */
    FIXP_DBL **QmfBufferImag,      /*!< Low and High band, imag */
    const QMF_SCALE_FACTOR *scaleFactor,
    const INT ov_len,        /*!< split Slot of overlap and actual slots */
    INT_PCM_QMFOUT *timeOut, /*!< Pointer to output */
    const INT stride,        /*!< stride factor of output */
    FIXP_DBL *pWorkBuffer    /*!< pointer to temporal working buffer */
) {
  int i;
  int L = synQmf->no_channels;
  int scaleFactorHighBand;
  int scaleFactorLowBand_ov, scaleFactorLowBand_no_ov;

  FDK_ASSERT(synQmf->no_channels >= synQmf->lsb);
  FDK_ASSERT(synQmf->no_channels >= synQmf->usb);

  /* adapt scaling */
  scaleFactorHighBand = -ALGORITHMIC_SCALING_IN_ANALYSIS_FILTERBANK -
                        scaleFactor->hb_scale - synQmf->filterScale;
  scaleFactorLowBand_ov = -ALGORITHMIC_SCALING_IN_ANALYSIS_FILTERBANK -
                          scaleFactor->ov_lb_scale - synQmf->filterScale;
  scaleFactorLowBand_no_ov = -ALGORITHMIC_SCALING_IN_ANALYSIS_FILTERBANK -
                             scaleFactor->lb_scale - synQmf->filterScale;

  for (i = 0; i < synQmf->no_col; i++) /* ----- no_col loop ----- */
  {
    const FIXP_DBL *QmfBufferImagSlot = NULL;

    int scaleFactorLowBand =
        (i < ov_len) ? scaleFactorLowBand_ov : scaleFactorLowBand_no_ov;

    if (!(synQmf->flags & QMF_FLAG_LP)) QmfBufferImagSlot = QmfBufferImag[i];

    qmfSynthesisFilteringSlot(synQmf, QmfBufferReal[i], QmfBufferImagSlot,
                              scaleFactorLowBand, scaleFactorHighBand,
                              timeOut + (i * L * stride), stride, pWorkBuffer);
  } /* no_col loop  i  */
}
#endif /* QMF_PCM_H */
