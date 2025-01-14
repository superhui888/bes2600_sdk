/***************************************************************************
 *
 * Copyright 2015-2020 BES.
 * All rights reserved. All unpublished rights reserved.
 *
 * No part of this work may be used or reproduced in any form or by any
 * means, or stored in a database or retrieval system, without prior written
 * permission of BES.
 *
 * Use of this work is governed by a license granted by BES.
 * This work contains confidential and proprietary information of
 * BES. which is protected by copyright, trade secret,
 * trademark and other intellectual property rights.
 *
 ****************************************************************************/
#ifndef __REG_ANALOG_BEST1305_H__
#define __REG_ANALOG_BEST1305_H__

#include "plat_types.h"

enum ANA_REG_T {
    ANA_REG_61 = 0x61,
    ANA_REG_62,
    ANA_REG_63,
    ANA_REG_64,
    ANA_REG_65,
    ANA_REG_66,
    ANA_REG_67,
    ANA_REG_68,
    ANA_REG_69,
    ANA_REG_6A,
    ANA_REG_6B,
    ANA_REG_6C,
    ANA_REG_6D,
    ANA_REG_6E,
    ANA_REG_6F,
    ANA_REG_70,
    ANA_REG_71,
    ANA_REG_72,
    ANA_REG_73,
    ANA_REG_74,
    ANA_REG_75,
    ANA_REG_76,
    ANA_REG_77,
    ANA_REG_78,
    ANA_REG_79,
    ANA_REG_7A,
    ANA_REG_7B,
    ANA_REG_7C,
    ANA_REG_7D,
    ANA_REG_7E,
    ANA_REG_7F,
    ANA_REG_80,
    ANA_REG_81,
    ANA_REG_82,
    ANA_REG_83,
    ANA_REG_84,
    ANA_REG_85,
    ANA_REG_86,
    ANA_REG_87,
    ANA_REG_88,
    ANA_REG_89,
    ANA_REG_8A,
    ANA_REG_8B,
    ANA_REG_8C,
    ANA_REG_8D,
    ANA_REG_8E,
    ANA_REG_8F,
    ANA_REG_90,
    ANA_REG_91,
    ANA_REG_92,
    ANA_REG_93,
    ANA_REG_94,
    ANA_REG_95,
    ANA_REG_96,
    ANA_REG_97,
    ANA_REG_98,
    ANA_REG_99,
    ANA_REG_9A,
    ANA_REG_9B,
    ANA_REG_9C,
    ANA_REG_9D,
    ANA_REG_9E,
    ANA_REG_9F,
    ANA_REG_A0,
    ANA_REG_A1,
    ANA_REG_A2,
    ANA_REG_A3,
    ANA_REG_A4,
    ANA_REG_A5,
    ANA_REG_A6,
    ANA_REG_A7,
    ANA_REG_A8,
    ANA_REG_A9,
    ANA_REG_AA,
    ANA_REG_AB,
    ANA_REG_AC,
    ANA_REG_AD,
    ANA_REG_AE,
    ANA_REG_AF,
    ANA_REG_B0,
    ANA_REG_B1,
    ANA_REG_B2,
    ANA_REG_B3,
    ANA_REG_B4,
    ANA_REG_B5,
    ANA_REG_B6,
    ANA_REG_B7,
    ANA_REG_B8,
    ANA_REG_B9,
    ANA_REG_BA,
    ANA_REG_BB,
    ANA_REG_BC,
    ANA_REG_BD,

    ANA_REG_161 = 0x161,
    ANA_REG_162,
    ANA_REG_163,
    ANA_REG_164,
    ANA_REG_165,
    ANA_REG_166,
    ANA_REG_167,
    ANA_REG_168,
    ANA_REG_169,
    ANA_REG_16A,
    ANA_REG_16B,
    ANA_REG_16C,
    ANA_REG_16D,
    ANA_REG_16E,
    ANA_REG_16F,
    ANA_REG_170,
    ANA_REG_171,
    ANA_REG_172,
    ANA_REG_173,
    ANA_REG_174,
    ANA_REG_175,
    ANA_REG_176,
    ANA_REG_177,
    ANA_REG_178,
    ANA_REG_179,
    ANA_REG_17A,
    ANA_REG_17B,
    ANA_REG_17C,
    ANA_REG_17D,
    ANA_REG_17E,
    ANA_REG_17F,
    ANA_REG_180,
    ANA_REG_181,
    ANA_REG_182,
    ANA_REG_183,
    ANA_REG_184,
    ANA_REG_185,
    ANA_REG_186,
    ANA_REG_187,
    ANA_REG_188,
    ANA_REG_189,
    ANA_REG_18A,
};

// REG_60
#define REVID_SHIFT                         0
#define REVID_MASK                          (0xF << REVID_SHIFT)
#define REVID(n)                            BITFIELD_VAL(REVID, n)
#define CHIPID_SHIFT                        4
#define CHIPID_MASK                         (0xFFF << CHIPID_SHIFT)
#define CHIPID(n)                           BITFIELD_VAL(CHIPID, n)

// REG_61
#define REG_CODEC_EN_ADCA                   (1 << 0)
#define REG_CODEC_RESET_ADCA                (1 << 1)
#define CFG_RESET_ADCA_DR                   (1 << 2)
#define REG_CODEC_IDETA_EN                  (1 << 3)
#define REG_CODEC_ADCA_CLK_SEL              (1 << 4)
#define REG_CODEC_ADCA_CH_SEL_SHIFT         5
#define REG_CODEC_ADCA_CH_SEL_MASK          (0x3 << REG_CODEC_ADCA_CH_SEL_SHIFT)
#define REG_CODEC_ADCA_CH_SEL(n)            BITFIELD_VAL(REG_CODEC_ADCA_CH_SEL, n)
#define REG_CODEC_ADCA_DITHER_BIT_EN        (1 << 7)
#define CFG_ADCA_DITHER_CLK_INV             (1 << 8)
#define REG_CODEC_ADCA_GAIN_UPDATE          (1 << 9)
#define REG_CODEC_ADCA_GAIN_BIT_SHIFT       10
#define REG_CODEC_ADCA_GAIN_BIT_MASK        (0x7 << REG_CODEC_ADCA_GAIN_BIT_SHIFT)
#define REG_CODEC_ADCA_GAIN_BIT(n)          BITFIELD_VAL(REG_CODEC_ADCA_GAIN_BIT, n)
#define REG_CODEC_ADCA_PRE_CHARGE           (1 << 13)
#define CFG_PRE_CHARGE_ADCA_DR              (1 << 14)
#define REG_RX_ADCA_ZERO_DET_EN             (1 << 15)

// REG_62
#define REG_CODEC_ADCA_RES_2P5K_DR          (1 << 0)
#define REG_CODEC_ADCA_RES_2P5K_UPDATE      (1 << 1)
#define REG_CODEC_ADCA_RES_2P5K             (1 << 2)
#define REG_CODEC_ADCA_CAP_BIT1_SHIFT       3
#define REG_CODEC_ADCA_CAP_BIT1_MASK        (0x7F << REG_CODEC_ADCA_CAP_BIT1_SHIFT)
#define REG_CODEC_ADCA_CAP_BIT1(n)          BITFIELD_VAL(REG_CODEC_ADCA_CAP_BIT1, n)
#define REG_CODEC_ADCA_CAP_BIT2_SHIFT       10
#define REG_CODEC_ADCA_CAP_BIT2_MASK        (0x1F << REG_CODEC_ADCA_CAP_BIT2_SHIFT)
#define REG_CODEC_ADCA_CAP_BIT2(n)          BITFIELD_VAL(REG_CODEC_ADCA_CAP_BIT2, n)

// REG_63
#define REG_CODEC_ADCA_CAP_BIT3_SHIFT       0
#define REG_CODEC_ADCA_CAP_BIT3_MASK        (0x1F << REG_CODEC_ADCA_CAP_BIT3_SHIFT)
#define REG_CODEC_ADCA_CAP_BIT3(n)          BITFIELD_VAL(REG_CODEC_ADCA_CAP_BIT3, n)
#define REG_CODEC_ADCA_OP1_IBIT_SHIFT       5
#define REG_CODEC_ADCA_OP1_IBIT_MASK        (0x3 << REG_CODEC_ADCA_OP1_IBIT_SHIFT)
#define REG_CODEC_ADCA_OP1_IBIT(n)          BITFIELD_VAL(REG_CODEC_ADCA_OP1_IBIT, n)
#define REG_CODEC_ADCA_OP2_IBIT_SHIFT       7
#define REG_CODEC_ADCA_OP2_IBIT_MASK        (0x3 << REG_CODEC_ADCA_OP2_IBIT_SHIFT)
#define REG_CODEC_ADCA_OP2_IBIT(n)          BITFIELD_VAL(REG_CODEC_ADCA_OP2_IBIT, n)
#define REG_CODEC_ADCA_OP3_IBIT_SHIFT       9
#define REG_CODEC_ADCA_OP3_IBIT_MASK        (0x3 << REG_CODEC_ADCA_OP3_IBIT_SHIFT)
#define REG_CODEC_ADCA_OP3_IBIT(n)          BITFIELD_VAL(REG_CODEC_ADCA_OP3_IBIT, n)
#define REG_CODEC_ADCA_OP4_IBIT_SHIFT       11
#define REG_CODEC_ADCA_OP4_IBIT_MASK        (0x3 << REG_CODEC_ADCA_OP4_IBIT_SHIFT)
#define REG_CODEC_ADCA_OP4_IBIT(n)          BITFIELD_VAL(REG_CODEC_ADCA_OP4_IBIT, n)
#define REG_CODEC_ADCA_REG_VSEL_SHIFT       13
#define REG_CODEC_ADCA_REG_VSEL_MASK        (0x7 << REG_CODEC_ADCA_REG_VSEL_SHIFT)
#define REG_CODEC_ADCA_REG_VSEL(n)          BITFIELD_VAL(REG_CODEC_ADCA_REG_VSEL, n)

// REG_64
#define REG_CODEC_ADCA_IBSEL_OFFSET_SHIFT   0
#define REG_CODEC_ADCA_IBSEL_OFFSET_MASK    (0xF << REG_CODEC_ADCA_IBSEL_OFFSET_SHIFT)
#define REG_CODEC_ADCA_IBSEL_OFFSET(n)      BITFIELD_VAL(REG_CODEC_ADCA_IBSEL_OFFSET, n)
#define REG_CODEC_ADCA_IBSEL_OP1_SHIFT      4
#define REG_CODEC_ADCA_IBSEL_OP1_MASK       (0xF << REG_CODEC_ADCA_IBSEL_OP1_SHIFT)
#define REG_CODEC_ADCA_IBSEL_OP1(n)         BITFIELD_VAL(REG_CODEC_ADCA_IBSEL_OP1, n)
#define REG_CODEC_ADCA_IBSEL_OP2_SHIFT      8
#define REG_CODEC_ADCA_IBSEL_OP2_MASK       (0xF << REG_CODEC_ADCA_IBSEL_OP2_SHIFT)
#define REG_CODEC_ADCA_IBSEL_OP2(n)         BITFIELD_VAL(REG_CODEC_ADCA_IBSEL_OP2, n)
#define REG_CODEC_ADCA_IBSEL_OP3_SHIFT      12
#define REG_CODEC_ADCA_IBSEL_OP3_MASK       (0xF << REG_CODEC_ADCA_IBSEL_OP3_SHIFT)
#define REG_CODEC_ADCA_IBSEL_OP3(n)         BITFIELD_VAL(REG_CODEC_ADCA_IBSEL_OP3, n)

// REG_65
#define REG_CODEC_ADCA_IBSEL_OP4_SHIFT      0
#define REG_CODEC_ADCA_IBSEL_OP4_MASK       (0xF << REG_CODEC_ADCA_IBSEL_OP4_SHIFT)
#define REG_CODEC_ADCA_IBSEL_OP4(n)         BITFIELD_VAL(REG_CODEC_ADCA_IBSEL_OP4, n)
#define REG_CODEC_ADCA_IBSEL_REG_SHIFT      4
#define REG_CODEC_ADCA_IBSEL_REG_MASK       (0xF << REG_CODEC_ADCA_IBSEL_REG_SHIFT)
#define REG_CODEC_ADCA_IBSEL_REG(n)         BITFIELD_VAL(REG_CODEC_ADCA_IBSEL_REG, n)
#define REG_CODEC_ADCA_IBSEL_VCOMP_SHIFT    8
#define REG_CODEC_ADCA_IBSEL_VCOMP_MASK     (0xF << REG_CODEC_ADCA_IBSEL_VCOMP_SHIFT)
#define REG_CODEC_ADCA_IBSEL_VCOMP(n)       BITFIELD_VAL(REG_CODEC_ADCA_IBSEL_VCOMP, n)
#define REG_CODEC_ADCA_IBSEL_VREF_SHIFT     12
#define REG_CODEC_ADCA_IBSEL_VREF_MASK      (0xF << REG_CODEC_ADCA_IBSEL_VREF_SHIFT)
#define REG_CODEC_ADCA_IBSEL_VREF(n)        BITFIELD_VAL(REG_CODEC_ADCA_IBSEL_VREF, n)

// REG_66
#define REG_CODEC_ADCA_IBSEL_VREFBUF_SHIFT  0
#define REG_CODEC_ADCA_IBSEL_VREFBUF_MASK   (0xF << REG_CODEC_ADCA_IBSEL_VREFBUF_SHIFT)
#define REG_CODEC_ADCA_IBSEL_VREFBUF(n)     BITFIELD_VAL(REG_CODEC_ADCA_IBSEL_VREFBUF, n)
#define REG_CODEC_ADCA_IBSEL_IDAC2_SHIFT    4
#define REG_CODEC_ADCA_IBSEL_IDAC2_MASK     (0xF << REG_CODEC_ADCA_IBSEL_IDAC2_SHIFT)
#define REG_CODEC_ADCA_IBSEL_IDAC2(n)       BITFIELD_VAL(REG_CODEC_ADCA_IBSEL_IDAC2, n)
#define REG_CODEC_ADCA_OFFSET_CAL_S_SHIFT   8
#define REG_CODEC_ADCA_OFFSET_CAL_S_MASK    (0x1F << REG_CODEC_ADCA_OFFSET_CAL_S_SHIFT)
#define REG_CODEC_ADCA_OFFSET_CAL_S(n)      BITFIELD_VAL(REG_CODEC_ADCA_OFFSET_CAL_S, n)
#define REG_CODEC_ADCA_OFFSET_CURRENT_EN    (1 << 13)
#define REG_CODEC_ADCA_OFFSET_CURRENT_SEL   (1 << 14)
#define REG_CODEC_ADCA_OFFSET_SW_EN         (1 << 15)

// REG_67
#define REG_CODEC_ADCA_OFFSET_BIT_SHIFT     0
#define REG_CODEC_ADCA_OFFSET_BIT_MASK      (0x3FFF << REG_CODEC_ADCA_OFFSET_BIT_SHIFT)
#define REG_CODEC_ADCA_OFFSET_BIT(n)        BITFIELD_VAL(REG_CODEC_ADCA_OFFSET_BIT, n)
#define REG_CODEC_ADCA_DVDD_SEL             (1 << 14)
#define REG_CODEC_ADCA_PU_REG               (1 << 15)

// REG_68
#define REG_CODEC_ADCA_VREF_SEL_SHIFT       0
#define REG_CODEC_ADCA_VREF_SEL_MASK        (0xF << REG_CODEC_ADCA_VREF_SEL_SHIFT)
#define REG_CODEC_ADCA_VREF_SEL(n)          BITFIELD_VAL(REG_CODEC_ADCA_VREF_SEL, n)
#define REG_CODEC_ADCA_VREFBUF_BIT_SHIFT    4
#define REG_CODEC_ADCA_VREFBUF_BIT_MASK     (0xF << REG_CODEC_ADCA_VREFBUF_BIT_SHIFT)
#define REG_CODEC_ADCA_VREFBUF_BIT(n)       BITFIELD_VAL(REG_CODEC_ADCA_VREFBUF_BIT, n)
#define ADCA_TIMER_RSTN_DLY_SHIFT           8
#define ADCA_TIMER_RSTN_DLY_MASK            (0x3F << ADCA_TIMER_RSTN_DLY_SHIFT)
#define ADCA_TIMER_RSTN_DLY(n)              BITFIELD_VAL(ADCA_TIMER_RSTN_DLY, n)

// REG_69
#define ADCA_OPEN_TIMER_DLY_SHIFT           0
#define ADCA_OPEN_TIMER_DLY_MASK            (0xF << ADCA_OPEN_TIMER_DLY_SHIFT)
#define ADCA_OPEN_TIMER_DLY(n)              BITFIELD_VAL(ADCA_OPEN_TIMER_DLY, n)
#define ADCA_PRE_CHARGE_TIMER_DLY_SHIFT     4
#define ADCA_PRE_CHARGE_TIMER_DLY_MASK      (0xFF << ADCA_PRE_CHARGE_TIMER_DLY_SHIFT)
#define ADCA_PRE_CHARGE_TIMER_DLY(n)        BITFIELD_VAL(ADCA_PRE_CHARGE_TIMER_DLY, n)
#define REG_CODEC_ADCA_HP_MODE              (1 << 12)
#define REG_CODEC_ADCA_LP_MODE              (1 << 13)
#define REG_CODEC_ADCA_NP_MODE              (1 << 14)
#define REG_CODEC_ADCA_OP1_HP_MODE          (1 << 15)

// REG_6A
#define REG_RX_PGAA_EN                      (1 << 0)
#define REG_RX_PGAA_RESET                   (1 << 1)
#define CFG_RESET_PGAA_DR                   (1 << 2)
#define REG_RX_PGAA_2P5K_SEL                (1 << 3)
#define REG_RX_PGAA_7P5K_SEL                (1 << 4)
#define REG_RX_PGAA_10K_SEL                 (1 << 5)
#define REG_RX_PGAA_CHANSEL_SHIFT           6
#define REG_RX_PGAA_CHANSEL_MASK            (0x3 << REG_RX_PGAA_CHANSEL_SHIFT)
#define REG_RX_PGAA_CHANSEL(n)              BITFIELD_VAL(REG_RX_PGAA_CHANSEL, n)
#define REG_RX_PGAA_DACGAIN_SHIFT           8
#define REG_RX_PGAA_DACGAIN_MASK            (0x3 << REG_RX_PGAA_DACGAIN_SHIFT)
#define REG_RX_PGAA_DACGAIN(n)              BITFIELD_VAL(REG_RX_PGAA_DACGAIN, n)
#define REG_RX_PGAA_IBIT_OPA_SHIFT          10
#define REG_RX_PGAA_IBIT_OPA_MASK           (0x3 << REG_RX_PGAA_IBIT_OPA_SHIFT)
#define REG_RX_PGAA_IBIT_OPA(n)             BITFIELD_VAL(REG_RX_PGAA_IBIT_OPA, n)
#define REG_RX_PGAA_OFFSET_CAL_EN           (1 << 12)
#define REG_RX_PGAA_OP_C_SEL                (1 << 13)
#define REG_RX_PGAA_OP_GM_SEL               (1 << 14)
#define REG_RX_PGAA_OP_R_SEL                (1 << 15)

// REG_6B
#define REG_RX_PGAA_GAIN_SHIFT              0
#define REG_RX_PGAA_GAIN_MASK               (0xF << REG_RX_PGAA_GAIN_SHIFT)
#define REG_RX_PGAA_GAIN(n)                 BITFIELD_VAL(REG_RX_PGAA_GAIN, n)
#define REG_RX_PGAA_GAIN_UPDATE             (1 << 4)
#define REG_RX_PGAA_LARGEGAIN_SHIFT         5
#define REG_RX_PGAA_LARGEGAIN_MASK          (0xF << REG_RX_PGAA_LARGEGAIN_SHIFT)
#define REG_RX_PGAA_LARGEGAIN(n)            BITFIELD_VAL(REG_RX_PGAA_LARGEGAIN, n)
#define REG_RX_PGAA_LARGEGAIN_UPDATE        (1 << 9)
#define REG_RX_PGAA_DRE_SHIFT               10
#define REG_RX_PGAA_DRE_MASK                (0xF << REG_RX_PGAA_DRE_SHIFT)
#define REG_RX_PGAA_DRE(n)                  BITFIELD_VAL(REG_RX_PGAA_DRE, n)
#define REG_RX_PGAA_DRE_DR                  (1 << 14)
#define REG_RX_PGAA_DRE_UPDATE              (1 << 15)

// REG_6C
#define REG_RX_PGAA_RFB_EN                  (1 << 0)
#define REG_RX_PGAA_LP_PGA_LV_SHIFT         1
#define REG_RX_PGAA_LP_PGA_LV_MASK          (0x7 << REG_RX_PGAA_LP_PGA_LV_SHIFT)
#define REG_RX_PGAA_LP_PGA_LV(n)            BITFIELD_VAL(REG_RX_PGAA_LP_PGA_LV, n)
#define REG_RX_PGAA_PRE_CHARGE              (1 << 4)
#define CFG_RX_PGAA_PRE_CHARGE_DR           (1 << 5)
#define PGAA_PRE_CHARGE_TIMER_DLY_SHIFT     6
#define PGAA_PRE_CHARGE_TIMER_DLY_MASK      (0xFF << PGAA_PRE_CHARGE_TIMER_DLY_SHIFT)
#define PGAA_PRE_CHARGE_TIMER_DLY(n)        BITFIELD_VAL(PGAA_PRE_CHARGE_TIMER_DLY, n)



// REG_6F
#define CHIP_ADDR_I2C_SHIFT                 0
#define CHIP_ADDR_I2C_MASK                  (0x7F << CHIP_ADDR_I2C_SHIFT)
#define CHIP_ADDR_I2C(n)                    BITFIELD_VAL(CHIP_ADDR_I2C, n)



// REG_71
#define REG_CODEC_EN_ADCB                   (1 << 0)
#define REG_CODEC_RESET_ADCB                (1 << 1)
#define CFG_RESET_ADCB_DR                   (1 << 2)
#define REG_CODEC_IDETB_EN                  (1 << 3)
#define REG_CODEC_ADCB_CLK_SEL              (1 << 4)
#define REG_CODEC_ADCB_CH_SEL_SHIFT         5
#define REG_CODEC_ADCB_CH_SEL_MASK          (0x3 << REG_CODEC_ADCB_CH_SEL_SHIFT)
#define REG_CODEC_ADCB_CH_SEL(n)            BITFIELD_VAL(REG_CODEC_ADCB_CH_SEL, n)
#define REG_CODEC_ADCB_DITHER_BIT_EN        (1 << 7)
#define CFG_ADCB_DITHER_CLK_INV             (1 << 8)
#define REG_CODEC_ADCB_GAIN_UPDATE          (1 << 9)
#define REG_CODEC_ADCB_GAIN_BIT_SHIFT       10
#define REG_CODEC_ADCB_GAIN_BIT_MASK        (0x7 << REG_CODEC_ADCB_GAIN_BIT_SHIFT)
#define REG_CODEC_ADCB_GAIN_BIT(n)          BITFIELD_VAL(REG_CODEC_ADCB_GAIN_BIT, n)
#define REG_CODEC_ADCB_PRE_CHARGE           (1 << 13)
#define CFG_PRE_CHARGE_ADCB_DR              (1 << 14)
#define REG_RX_ADCB_ZERO_DET_EN             (1 << 15)

// REG_72
#define REG_CODEC_ADCB_RES_2P5K_DR          (1 << 0)
#define REG_CODEC_ADCB_RES_2P5K_UPDATE      (1 << 1)
#define REG_CODEC_ADCB_RES_2P5K             (1 << 2)
#define REG_CODEC_ADCB_CAP_BIT1_SHIFT       3
#define REG_CODEC_ADCB_CAP_BIT1_MASK        (0x7F << REG_CODEC_ADCB_CAP_BIT1_SHIFT)
#define REG_CODEC_ADCB_CAP_BIT1(n)          BITFIELD_VAL(REG_CODEC_ADCB_CAP_BIT1, n)
#define REG_CODEC_ADCB_CAP_BIT2_SHIFT       10
#define REG_CODEC_ADCB_CAP_BIT2_MASK        (0x1F << REG_CODEC_ADCB_CAP_BIT2_SHIFT)
#define REG_CODEC_ADCB_CAP_BIT2(n)          BITFIELD_VAL(REG_CODEC_ADCB_CAP_BIT2, n)

// REG_73
#define REG_CODEC_ADCB_CAP_BIT3_SHIFT       0
#define REG_CODEC_ADCB_CAP_BIT3_MASK        (0x1F << REG_CODEC_ADCB_CAP_BIT3_SHIFT)
#define REG_CODEC_ADCB_CAP_BIT3(n)          BITFIELD_VAL(REG_CODEC_ADCB_CAP_BIT3, n)
#define REG_CODEC_ADCB_OP1_IBIT_SHIFT       5
#define REG_CODEC_ADCB_OP1_IBIT_MASK        (0x3 << REG_CODEC_ADCB_OP1_IBIT_SHIFT)
#define REG_CODEC_ADCB_OP1_IBIT(n)          BITFIELD_VAL(REG_CODEC_ADCB_OP1_IBIT, n)
#define REG_CODEC_ADCB_OP2_IBIT_SHIFT       7
#define REG_CODEC_ADCB_OP2_IBIT_MASK        (0x3 << REG_CODEC_ADCB_OP2_IBIT_SHIFT)
#define REG_CODEC_ADCB_OP2_IBIT(n)          BITFIELD_VAL(REG_CODEC_ADCB_OP2_IBIT, n)
#define REG_CODEC_ADCB_OP3_IBIT_SHIFT       9
#define REG_CODEC_ADCB_OP3_IBIT_MASK        (0x3 << REG_CODEC_ADCB_OP3_IBIT_SHIFT)
#define REG_CODEC_ADCB_OP3_IBIT(n)          BITFIELD_VAL(REG_CODEC_ADCB_OP3_IBIT, n)
#define REG_CODEC_ADCB_OP4_IBIT_SHIFT       11
#define REG_CODEC_ADCB_OP4_IBIT_MASK        (0x3 << REG_CODEC_ADCB_OP4_IBIT_SHIFT)
#define REG_CODEC_ADCB_OP4_IBIT(n)          BITFIELD_VAL(REG_CODEC_ADCB_OP4_IBIT, n)
#define REG_CODEC_ADCB_REG_VSEL_SHIFT       13
#define REG_CODEC_ADCB_REG_VSEL_MASK        (0x7 << REG_CODEC_ADCB_REG_VSEL_SHIFT)
#define REG_CODEC_ADCB_REG_VSEL(n)          BITFIELD_VAL(REG_CODEC_ADCB_REG_VSEL, n)

// REG_74
#define REG_CODEC_ADCB_IBSEL_OFFSET_SHIFT   0
#define REG_CODEC_ADCB_IBSEL_OFFSET_MASK    (0xF << REG_CODEC_ADCB_IBSEL_OFFSET_SHIFT)
#define REG_CODEC_ADCB_IBSEL_OFFSET(n)      BITFIELD_VAL(REG_CODEC_ADCB_IBSEL_OFFSET, n)
#define REG_CODEC_ADCB_IBSEL_OP1_SHIFT      4
#define REG_CODEC_ADCB_IBSEL_OP1_MASK       (0xF << REG_CODEC_ADCB_IBSEL_OP1_SHIFT)
#define REG_CODEC_ADCB_IBSEL_OP1(n)         BITFIELD_VAL(REG_CODEC_ADCB_IBSEL_OP1, n)
#define REG_CODEC_ADCB_IBSEL_OP2_SHIFT      8
#define REG_CODEC_ADCB_IBSEL_OP2_MASK       (0xF << REG_CODEC_ADCB_IBSEL_OP2_SHIFT)
#define REG_CODEC_ADCB_IBSEL_OP2(n)         BITFIELD_VAL(REG_CODEC_ADCB_IBSEL_OP2, n)
#define REG_CODEC_ADCB_IBSEL_OP3_SHIFT      12
#define REG_CODEC_ADCB_IBSEL_OP3_MASK       (0xF << REG_CODEC_ADCB_IBSEL_OP3_SHIFT)
#define REG_CODEC_ADCB_IBSEL_OP3(n)         BITFIELD_VAL(REG_CODEC_ADCB_IBSEL_OP3, n)

// REG_75
#define REG_CODEC_ADCB_IBSEL_OP4_SHIFT      0
#define REG_CODEC_ADCB_IBSEL_OP4_MASK       (0xF << REG_CODEC_ADCB_IBSEL_OP4_SHIFT)
#define REG_CODEC_ADCB_IBSEL_OP4(n)         BITFIELD_VAL(REG_CODEC_ADCB_IBSEL_OP4, n)
#define REG_CODEC_ADCB_IBSEL_REG_SHIFT      4
#define REG_CODEC_ADCB_IBSEL_REG_MASK       (0xF << REG_CODEC_ADCB_IBSEL_REG_SHIFT)
#define REG_CODEC_ADCB_IBSEL_REG(n)         BITFIELD_VAL(REG_CODEC_ADCB_IBSEL_REG, n)
#define REG_CODEC_ADCB_IBSEL_VCOMP_SHIFT    8
#define REG_CODEC_ADCB_IBSEL_VCOMP_MASK     (0xF << REG_CODEC_ADCB_IBSEL_VCOMP_SHIFT)
#define REG_CODEC_ADCB_IBSEL_VCOMP(n)       BITFIELD_VAL(REG_CODEC_ADCB_IBSEL_VCOMP, n)
#define REG_CODEC_ADCB_IBSEL_VREF_SHIFT     12
#define REG_CODEC_ADCB_IBSEL_VREF_MASK      (0xF << REG_CODEC_ADCB_IBSEL_VREF_SHIFT)
#define REG_CODEC_ADCB_IBSEL_VREF(n)        BITFIELD_VAL(REG_CODEC_ADCB_IBSEL_VREF, n)

// REG_76
#define REG_CODEC_ADCB_IBSEL_VREFBUF_SHIFT  0
#define REG_CODEC_ADCB_IBSEL_VREFBUF_MASK   (0xF << REG_CODEC_ADCB_IBSEL_VREFBUF_SHIFT)
#define REG_CODEC_ADCB_IBSEL_VREFBUF(n)     BITFIELD_VAL(REG_CODEC_ADCB_IBSEL_VREFBUF, n)
#define REG_CODEC_ADCB_IBSEL_IDAC2_SHIFT    4
#define REG_CODEC_ADCB_IBSEL_IDAC2_MASK     (0xF << REG_CODEC_ADCB_IBSEL_IDAC2_SHIFT)
#define REG_CODEC_ADCB_IBSEL_IDAC2(n)       BITFIELD_VAL(REG_CODEC_ADCB_IBSEL_IDAC2, n)
#define REG_CODEC_ADCB_OFFSET_CAL_S_SHIFT   8
#define REG_CODEC_ADCB_OFFSET_CAL_S_MASK    (0x1F << REG_CODEC_ADCB_OFFSET_CAL_S_SHIFT)
#define REG_CODEC_ADCB_OFFSET_CAL_S(n)      BITFIELD_VAL(REG_CODEC_ADCB_OFFSET_CAL_S, n)
#define REG_CODEC_ADCB_OFFSET_CURRENT_EN    (1 << 13)
#define REG_CODEC_ADCB_OFFSET_CURRENT_SEL   (1 << 14)
#define REG_CODEC_ADCB_OFFSET_SW_EN         (1 << 15)

// REG_77
#define REG_CODEC_ADCB_OFFSET_BIT_SHIFT     0
#define REG_CODEC_ADCB_OFFSET_BIT_MASK      (0x3FFF << REG_CODEC_ADCB_OFFSET_BIT_SHIFT)
#define REG_CODEC_ADCB_OFFSET_BIT(n)        BITFIELD_VAL(REG_CODEC_ADCB_OFFSET_BIT, n)
#define REG_CODEC_ADCB_DVDD_SEL             (1 << 14)
#define REG_CODEC_ADCB_PU_REG               (1 << 15)

// REG_78
#define REG_CODEC_ADCB_VREF_SEL_SHIFT       0
#define REG_CODEC_ADCB_VREF_SEL_MASK        (0xF << REG_CODEC_ADCB_VREF_SEL_SHIFT)
#define REG_CODEC_ADCB_VREF_SEL(n)          BITFIELD_VAL(REG_CODEC_ADCB_VREF_SEL, n)
#define REG_CODEC_ADCB_VREFBUF_BIT_SHIFT    4
#define REG_CODEC_ADCB_VREFBUF_BIT_MASK     (0xF << REG_CODEC_ADCB_VREFBUF_BIT_SHIFT)
#define REG_CODEC_ADCB_VREFBUF_BIT(n)       BITFIELD_VAL(REG_CODEC_ADCB_VREFBUF_BIT, n)
#define ADCB_TIMER_RSTN_DLY_SHIFT           8
#define ADCB_TIMER_RSTN_DLY_MASK            (0x3F << ADCB_TIMER_RSTN_DLY_SHIFT)
#define ADCB_TIMER_RSTN_DLY(n)              BITFIELD_VAL(ADCB_TIMER_RSTN_DLY, n)


// REG_79
#define ADCB_OPEN_TIMER_DLY_SHIFT           0
#define ADCB_OPEN_TIMER_DLY_MASK            (0xF << ADCB_OPEN_TIMER_DLY_SHIFT)
#define ADCB_OPEN_TIMER_DLY(n)              BITFIELD_VAL(ADCB_OPEN_TIMER_DLY, n)
#define ADCB_PRE_CHARGE_TIMER_DLY_SHIFT     4
#define ADCB_PRE_CHARGE_TIMER_DLY_MASK      (0xFF << ADCB_PRE_CHARGE_TIMER_DLY_SHIFT)
#define ADCB_PRE_CHARGE_TIMER_DLY(n)        BITFIELD_VAL(ADCB_PRE_CHARGE_TIMER_DLY, n)
#define REG_CODEC_ADCB_HP_MODE              (1 << 12)
#define REG_CODEC_ADCB_LP_MODE              (1 << 13)
#define REG_CODEC_ADCB_NP_MODE              (1 << 14)
#define REG_CODEC_ADCB_OP1_HP_MODE          (1 << 15)

// REG_7A
#define REG_RX_PGAB_EN                      (1 << 0)
#define REG_RX_PGAB_RESET                   (1 << 1)
#define CFG_RESET_PGAB_DR                   (1 << 2)
#define REG_RX_PGAB_2P5K_SEL                (1 << 3)
#define REG_RX_PGAB_7P5K_SEL                (1 << 4)
#define REG_RX_PGAB_10K_SEL                 (1 << 5)
#define REG_RX_PGAB_CHANSEL_SHIFT           6
#define REG_RX_PGAB_CHANSEL_MASK            (0x3 << REG_RX_PGAB_CHANSEL_SHIFT)
#define REG_RX_PGAB_CHANSEL(n)              BITFIELD_VAL(REG_RX_PGAB_CHANSEL, n)
#define REG_RX_PGAB_DACGAIN_SHIFT           8
#define REG_RX_PGAB_DACGAIN_MASK            (0x3 << REG_RX_PGAB_DACGAIN_SHIFT)
#define REG_RX_PGAB_DACGAIN(n)              BITFIELD_VAL(REG_RX_PGAB_DACGAIN, n)
#define REG_RX_PGAB_IBIT_OPA_SHIFT          10
#define REG_RX_PGAB_IBIT_OPA_MASK           (0x3 << REG_RX_PGAB_IBIT_OPA_SHIFT)
#define REG_RX_PGAB_IBIT_OPA(n)             BITFIELD_VAL(REG_RX_PGAB_IBIT_OPA, n)
#define REG_RX_PGAB_OFFSET_CAL_EN           (1 << 12)
#define REG_RX_PGAB_OP_C_SEL                (1 << 13)
#define REG_RX_PGAB_OP_GM_SEL               (1 << 14)
#define REG_RX_PGAB_OP_R_SEL                (1 << 15)

// REG_7B
#define REG_RX_PGAB_GAIN_SHIFT              0
#define REG_RX_PGAB_GAIN_MASK               (0xF << REG_RX_PGAB_GAIN_SHIFT)
#define REG_RX_PGAB_GAIN(n)                 BITFIELD_VAL(REG_RX_PGAB_GAIN, n)
#define REG_RX_PGAB_GAIN_UPDATE             (1 << 4)
#define REG_RX_PGAB_LARGEGAIN_SHIFT         5
#define REG_RX_PGAB_LARGEGAIN_MASK          (0xF << REG_RX_PGAB_LARGEGAIN_SHIFT)
#define REG_RX_PGAB_LARGEGAIN(n)            BITFIELD_VAL(REG_RX_PGAB_LARGEGAIN, n)
#define REG_RX_PGAB_LARGEGAIN_UPDATE        (1 << 9)
#define REG_RX_PGAB_DRE_SHIFT               10
#define REG_RX_PGAB_DRE_MASK                (0xF << REG_RX_PGAB_DRE_SHIFT)
#define REG_RX_PGAB_DRE(n)                  BITFIELD_VAL(REG_RX_PGAB_DRE, n)
#define REG_RX_PGAB_DRE_DR                  (1 << 14)
#define REG_RX_PGAB_DRE_UPDATE              (1 << 15)

// REG_7C
#define REG_RX_PGAB_RFB_EN                  (1 << 0)
#define REG_RX_PGAB_LP_PGA_LV_SHIFT         1
#define REG_RX_PGAB_LP_PGA_LV_MASK          (0x7 << REG_RX_PGAB_LP_PGA_LV_SHIFT)
#define REG_RX_PGAB_LP_PGA_LV(n)            BITFIELD_VAL(REG_RX_PGAB_LP_PGA_LV, n)
#define REG_RX_PGAB_PRE_CHARGE              (1 << 4)
#define CFG_RX_PGAB_PRE_CHARGE_DR           (1 << 5)
#define PGAB_PRE_CHARGE_TIMER_DLY_SHIFT     6
#define PGAB_PRE_CHARGE_TIMER_DLY_MASK      (0xFF << PGAB_PRE_CHARGE_TIMER_DLY_SHIFT)
#define PGAB_PRE_CHARGE_TIMER_DLY(n)        BITFIELD_VAL(PGAB_PRE_CHARGE_TIMER_DLY, n)


// REG_81
#define REG_CODEC_EN_ADCC                   (1 << 0)
#define REG_CODEC_RESET_ADCC                (1 << 1)
#define CFG_RESET_ADCC_DR                   (1 << 2)
#define REG_CODEC_IDETC_EN                  (1 << 3)
#define REG_CODEC_ADCC_CLK_SEL              (1 << 4)
#define REG_CODEC_ADCC_CH_SEL_SHIFT         5
#define REG_CODEC_ADCC_CH_SEL_MASK          (0x3 << REG_CODEC_ADCC_CH_SEL_SHIFT)
#define REG_CODEC_ADCC_CH_SEL(n)            BITFIELD_VAL(REG_CODEC_ADCC_CH_SEL, n)
#define REG_CODEC_ADCC_DITHER_BIT_EN        (1 << 7)
#define CFG_ADCC_DITHER_CLK_INV             (1 << 8)
#define REG_CODEC_ADCC_GAIN_UPDATE          (1 << 9)
#define REG_CODEC_ADCC_GAIN_BIT_SHIFT       10
#define REG_CODEC_ADCC_GAIN_BIT_MASK        (0x7 << REG_CODEC_ADCC_GAIN_BIT_SHIFT)
#define REG_CODEC_ADCC_GAIN_BIT(n)          BITFIELD_VAL(REG_CODEC_ADCC_GAIN_BIT, n)
#define REG_CODEC_ADCC_PRE_CHARGE           (1 << 13)
#define CFG_PRE_CHARGE_ADCC_DR              (1 << 14)
#define REG_RX_ADCC_ZERO_DET_EN             (1 << 15)

// REG_82
#define REG_CODEC_ADCC_RES_2P5K_DR          (1 << 0)
#define REG_CODEC_ADCC_RES_2P5K_UPDATE      (1 << 1)
#define REG_CODEC_ADCC_RES_2P5K             (1 << 2)
#define REG_CODEC_ADCC_CAP_BIT1_SHIFT       3
#define REG_CODEC_ADCC_CAP_BIT1_MASK        (0x7F << REG_CODEC_ADCC_CAP_BIT1_SHIFT)
#define REG_CODEC_ADCC_CAP_BIT1(n)          BITFIELD_VAL(REG_CODEC_ADCC_CAP_BIT1, n)
#define REG_CODEC_ADCC_CAP_BIT2_SHIFT       10
#define REG_CODEC_ADCC_CAP_BIT2_MASK        (0x1F << REG_CODEC_ADCC_CAP_BIT2_SHIFT)
#define REG_CODEC_ADCC_CAP_BIT2(n)          BITFIELD_VAL(REG_CODEC_ADCC_CAP_BIT2, n)

// REG_83
#define REG_CODEC_ADCC_CAP_BIT3_SHIFT       0
#define REG_CODEC_ADCC_CAP_BIT3_MASK        (0x1F << REG_CODEC_ADCC_CAP_BIT3_SHIFT)
#define REG_CODEC_ADCC_CAP_BIT3(n)          BITFIELD_VAL(REG_CODEC_ADCC_CAP_BIT3, n)
#define REG_CODEC_ADCC_OP1_IBIT_SHIFT       5
#define REG_CODEC_ADCC_OP1_IBIT_MASK        (0x3 << REG_CODEC_ADCC_OP1_IBIT_SHIFT)
#define REG_CODEC_ADCC_OP1_IBIT(n)          BITFIELD_VAL(REG_CODEC_ADCC_OP1_IBIT, n)
#define REG_CODEC_ADCC_OP2_IBIT_SHIFT       7
#define REG_CODEC_ADCC_OP2_IBIT_MASK        (0x3 << REG_CODEC_ADCC_OP2_IBIT_SHIFT)
#define REG_CODEC_ADCC_OP2_IBIT(n)          BITFIELD_VAL(REG_CODEC_ADCC_OP2_IBIT, n)
#define REG_CODEC_ADCC_OP3_IBIT_SHIFT       9
#define REG_CODEC_ADCC_OP3_IBIT_MASK        (0x3 << REG_CODEC_ADCC_OP3_IBIT_SHIFT)
#define REG_CODEC_ADCC_OP3_IBIT(n)          BITFIELD_VAL(REG_CODEC_ADCC_OP3_IBIT, n)
#define REG_CODEC_ADCC_OP4_IBIT_SHIFT       11
#define REG_CODEC_ADCC_OP4_IBIT_MASK        (0x3 << REG_CODEC_ADCC_OP4_IBIT_SHIFT)
#define REG_CODEC_ADCC_OP4_IBIT(n)          BITFIELD_VAL(REG_CODEC_ADCC_OP4_IBIT, n)
#define REG_CODEC_ADCC_REG_VSEL_SHIFT       13
#define REG_CODEC_ADCC_REG_VSEL_MASK        (0x7 << REG_CODEC_ADCC_REG_VSEL_SHIFT)
#define REG_CODEC_ADCC_REG_VSEL(n)          BITFIELD_VAL(REG_CODEC_ADCC_REG_VSEL, n)

// REG_84
#define REG_CODEC_ADCC_IBSEL_OFFSET_SHIFT   0
#define REG_CODEC_ADCC_IBSEL_OFFSET_MASK    (0xF << REG_CODEC_ADCC_IBSEL_OFFSET_SHIFT)
#define REG_CODEC_ADCC_IBSEL_OFFSET(n)      BITFIELD_VAL(REG_CODEC_ADCC_IBSEL_OFFSET, n)
#define REG_CODEC_ADCC_IBSEL_OP1_SHIFT      4
#define REG_CODEC_ADCC_IBSEL_OP1_MASK       (0xF << REG_CODEC_ADCC_IBSEL_OP1_SHIFT)
#define REG_CODEC_ADCC_IBSEL_OP1(n)         BITFIELD_VAL(REG_CODEC_ADCC_IBSEL_OP1, n)
#define REG_CODEC_ADCC_IBSEL_OP2_SHIFT      8
#define REG_CODEC_ADCC_IBSEL_OP2_MASK       (0xF << REG_CODEC_ADCC_IBSEL_OP2_SHIFT)
#define REG_CODEC_ADCC_IBSEL_OP2(n)         BITFIELD_VAL(REG_CODEC_ADCC_IBSEL_OP2, n)
#define REG_CODEC_ADCC_IBSEL_OP3_SHIFT      12
#define REG_CODEC_ADCC_IBSEL_OP3_MASK       (0xF << REG_CODEC_ADCC_IBSEL_OP3_SHIFT)
#define REG_CODEC_ADCC_IBSEL_OP3(n)         BITFIELD_VAL(REG_CODEC_ADCC_IBSEL_OP3, n)

// REG_85
#define REG_CODEC_ADCC_IBSEL_OP4_SHIFT      0
#define REG_CODEC_ADCC_IBSEL_OP4_MASK       (0xF << REG_CODEC_ADCC_IBSEL_OP4_SHIFT)
#define REG_CODEC_ADCC_IBSEL_OP4(n)         BITFIELD_VAL(REG_CODEC_ADCC_IBSEL_OP4, n)
#define REG_CODEC_ADCC_IBSEL_REG_SHIFT      4
#define REG_CODEC_ADCC_IBSEL_REG_MASK       (0xF << REG_CODEC_ADCC_IBSEL_REG_SHIFT)
#define REG_CODEC_ADCC_IBSEL_REG(n)         BITFIELD_VAL(REG_CODEC_ADCC_IBSEL_REG, n)
#define REG_CODEC_ADCC_IBSEL_VCOMP_SHIFT    8
#define REG_CODEC_ADCC_IBSEL_VCOMP_MASK     (0xF << REG_CODEC_ADCC_IBSEL_VCOMP_SHIFT)
#define REG_CODEC_ADCC_IBSEL_VCOMP(n)       BITFIELD_VAL(REG_CODEC_ADCC_IBSEL_VCOMP, n)
#define REG_CODEC_ADCC_IBSEL_VREF_SHIFT     12
#define REG_CODEC_ADCC_IBSEL_VREF_MASK      (0xF << REG_CODEC_ADCC_IBSEL_VREF_SHIFT)
#define REG_CODEC_ADCC_IBSEL_VREF(n)        BITFIELD_VAL(REG_CODEC_ADCC_IBSEL_VREF, n)

// REG_86
#define REG_CODEC_ADCC_IBSEL_VREFBUF_SHIFT  0
#define REG_CODEC_ADCC_IBSEL_VREFBUF_MASK   (0xF << REG_CODEC_ADCC_IBSEL_VREFBUF_SHIFT)
#define REG_CODEC_ADCC_IBSEL_VREFBUF(n)     BITFIELD_VAL(REG_CODEC_ADCC_IBSEL_VREFBUF, n)
#define REG_CODEC_ADCC_IBSEL_IDAC2_SHIFT    4
#define REG_CODEC_ADCC_IBSEL_IDAC2_MASK     (0xF << REG_CODEC_ADCC_IBSEL_IDAC2_SHIFT)
#define REG_CODEC_ADCC_IBSEL_IDAC2(n)       BITFIELD_VAL(REG_CODEC_ADCC_IBSEL_IDAC2, n)
#define REG_CODEC_ADCC_OFFSET_CAL_S_SHIFT   8
#define REG_CODEC_ADCC_OFFSET_CAL_S_MASK    (0x1F << REG_CODEC_ADCC_OFFSET_CAL_S_SHIFT)
#define REG_CODEC_ADCC_OFFSET_CAL_S(n)      BITFIELD_VAL(REG_CODEC_ADCC_OFFSET_CAL_S, n)
#define REG_CODEC_ADCC_OFFSET_CURRENT_EN    (1 << 13)
#define REG_CODEC_ADCC_OFFSET_CURRENT_SEL   (1 << 14)
#define REG_CODEC_ADCC_OFFSET_SW_EN         (1 << 15)

// REG_87
#define REG_CODEC_ADCC_OFFSET_BIT_SHIFT     0
#define REG_CODEC_ADCC_OFFSET_BIT_MASK      (0x3FFF << REG_CODEC_ADCC_OFFSET_BIT_SHIFT)
#define REG_CODEC_ADCC_OFFSET_BIT(n)        BITFIELD_VAL(REG_CODEC_ADCC_OFFSET_BIT, n)
#define REG_CODEC_ADCC_DVDD_SEL             (1 << 14)
#define REG_CODEC_ADCC_PU_REG               (1 << 15)

// REG_88
#define REG_CODEC_ADCC_VREF_SEL_SHIFT       0
#define REG_CODEC_ADCC_VREF_SEL_MASK        (0xF << REG_CODEC_ADCC_VREF_SEL_SHIFT)
#define REG_CODEC_ADCC_VREF_SEL(n)          BITFIELD_VAL(REG_CODEC_ADCC_VREF_SEL, n)
#define REG_CODEC_ADCC_VREFBUF_BIT_SHIFT    4
#define REG_CODEC_ADCC_VREFBUF_BIT_MASK     (0xF << REG_CODEC_ADCC_VREFBUF_BIT_SHIFT)
#define REG_CODEC_ADCC_VREFBUF_BIT(n)       BITFIELD_VAL(REG_CODEC_ADCC_VREFBUF_BIT, n)
#define ADCC_TIMER_RSTN_DLY_SHIFT           8
#define ADCC_TIMER_RSTN_DLY_MASK            (0x3F << ADCC_TIMER_RSTN_DLY_SHIFT)
#define ADCC_TIMER_RSTN_DLY(n)              BITFIELD_VAL(ADCC_TIMER_RSTN_DLY, n)


// REG_89
#define ADCC_OPEN_TIMER_DLY_SHIFT           0
#define ADCC_OPEN_TIMER_DLY_MASK            (0xF << ADCC_OPEN_TIMER_DLY_SHIFT)
#define ADCC_OPEN_TIMER_DLY(n)              BITFIELD_VAL(ADCC_OPEN_TIMER_DLY, n)
#define ADCC_PRE_CHARGE_TIMER_DLY_SHIFT     4
#define ADCC_PRE_CHARGE_TIMER_DLY_MASK      (0xFF << ADCC_PRE_CHARGE_TIMER_DLY_SHIFT)
#define ADCC_PRE_CHARGE_TIMER_DLY(n)        BITFIELD_VAL(ADCC_PRE_CHARGE_TIMER_DLY, n)
#define REG_CODEC_ADCC_HP_MODE              (1 << 12)
#define REG_CODEC_ADCC_LP_MODE              (1 << 13)
#define REG_CODEC_ADCC_NP_MODE              (1 << 14)
#define REG_CODEC_ADCC_OP1_HP_MODE          (1 << 15)

// REG_8A
#define REG_RX_PGAC_EN                      (1 << 0)
#define REG_RX_PGAC_RESET                   (1 << 1)
#define CFG_RESET_PGAC_DR                   (1 << 2)
#define REG_RX_PGAC_2P5K_SEL                (1 << 3)
#define REG_RX_PGAC_7P5K_SEL                (1 << 4)
#define REG_RX_PGAC_10K_SEL                 (1 << 5)
#define REG_RX_PGAC_CHANSEL_SHIFT           6
#define REG_RX_PGAC_CHANSEL_MASK            (0x3 << REG_RX_PGAC_CHANSEL_SHIFT)
#define REG_RX_PGAC_CHANSEL(n)              BITFIELD_VAL(REG_RX_PGAC_CHANSEL, n)
#define REG_RX_PGAC_DACGAIN_SHIFT           8
#define REG_RX_PGAC_DACGAIN_MASK            (0x3 << REG_RX_PGAC_DACGAIN_SHIFT)
#define REG_RX_PGAC_DACGAIN(n)              BITFIELD_VAL(REG_RX_PGAC_DACGAIN, n)
#define REG_RX_PGAC_IBIT_OPA_SHIFT          10
#define REG_RX_PGAC_IBIT_OPA_MASK           (0x3 << REG_RX_PGAC_IBIT_OPA_SHIFT)
#define REG_RX_PGAC_IBIT_OPA(n)             BITFIELD_VAL(REG_RX_PGAC_IBIT_OPA, n)
#define REG_RX_PGAC_OFFSET_CAL_EN           (1 << 12)
#define REG_RX_PGAC_OP_C_SEL                (1 << 13)
#define REG_RX_PGAC_OP_GM_SEL               (1 << 14)
#define REG_RX_PGAC_OP_R_SEL                (1 << 15)

// REG_8B
#define REG_RX_PGAC_GAIN_SHIFT              0
#define REG_RX_PGAC_GAIN_MASK               (0xF << REG_RX_PGAC_GAIN_SHIFT)
#define REG_RX_PGAC_GAIN(n)                 BITFIELD_VAL(REG_RX_PGAC_GAIN, n)
#define REG_RX_PGAC_GAIN_UPDATE             (1 << 4)
#define REG_RX_PGAC_LARGEGAIN_SHIFT         5
#define REG_RX_PGAC_LARGEGAIN_MASK          (0xF << REG_RX_PGAC_LARGEGAIN_SHIFT)
#define REG_RX_PGAC_LARGEGAIN(n)            BITFIELD_VAL(REG_RX_PGAC_LARGEGAIN, n)
#define REG_RX_PGAC_LARGEGAIN_UPDATE        (1 << 9)
#define REG_RX_PGAC_DRE_SHIFT               10
#define REG_RX_PGAC_DRE_MASK                (0xF << REG_RX_PGAC_DRE_SHIFT)
#define REG_RX_PGAC_DRE(n)                  BITFIELD_VAL(REG_RX_PGAC_DRE, n)
#define REG_RX_PGAC_DRE_DR                  (1 << 14)
#define REG_RX_PGAC_DRE_UPDATE              (1 << 15)

// REG_8C
#define REG_RX_PGAC_RFB_EN                  (1 << 0)
#define REG_RX_PGAC_LP_PGA_LV_SHIFT         1
#define REG_RX_PGAC_LP_PGA_LV_MASK          (0x7 << REG_RX_PGAC_LP_PGA_LV_SHIFT)
#define REG_RX_PGAC_LP_PGA_LV(n)            BITFIELD_VAL(REG_RX_PGAC_LP_PGA_LV, n)
#define REG_RX_PGAC_PRE_CHARGE              (1 << 4)
#define CFG_RX_PGAC_PRE_CHARGE_DR           (1 << 5)
#define PGAC_PRE_CHARGE_TIMER_DLY_SHIFT     6
#define PGAC_PRE_CHARGE_TIMER_DLY_MASK      (0xFF << PGAC_PRE_CHARGE_TIMER_DLY_SHIFT)
#define PGAC_PRE_CHARGE_TIMER_DLY(n)        BITFIELD_VAL(PGAC_PRE_CHARGE_TIMER_DLY, n)

// REG_AD
#define PU_OSC_PLL24MADC                    (1 << 0)
#define PU_OSC_PLL24MDAC                    (1 << 1)

// REG_AE
#define RESERVED_DIG_15_0_SHIFT             0
#define RESERVED_DIG_15_0_MASK              (0xFFFF << RESERVED_DIG_15_0_SHIFT)
#define RESERVED_DIG_15_0(n)                BITFIELD_VAL(RESERVED_DIG_15_0, n)

// REG_AF
#define RESERVED_DIG_31_16_SHIFT            0
#define RESERVED_DIG_31_16_MASK             (0xFFFF << RESERVED_DIG_31_16_SHIFT)
#define RESERVED_DIG_31_16(n)               BITFIELD_VAL(RESERVED_DIG_31_16, n)



// REG_B0
#define REG_CODEC_ADC_CAP_BIT               (1 << 0)
#define REG_CODEC_ADC_DITHER0P5_EN          (1 << 1)
#define REG_CODEC_ADC_DITHER0P25_EN         (1 << 2)
#define REG_CODEC_ADC_DITHER1_EN            (1 << 3)
#define REG_CODEC_ADC_DITHER2_EN            (1 << 4)
#define REG_CODEC_ADC_DITHER_PHASE_SEL      (1 << 5)
#define REG_CODEC_ADC_OP1_R_SEL             (1 << 6)
#define REG_CODEC_ADC_OP2_R_SEL             (1 << 7)
#define REG_CODEC_ADC_OP3_R_SEL             (1 << 8)
#define REG_CODEC_ADC_OP4_R_SEL             (1 << 9)
#define REG_CODEC_ADC_RES_SEL_SHIFT         10
#define REG_CODEC_ADC_RES_SEL_MASK          (0x7 << REG_CODEC_ADC_RES_SEL_SHIFT)
#define REG_CODEC_ADC_RES_SEL(n)            BITFIELD_VAL(REG_CODEC_ADC_RES_SEL, n)
#define REG_CODEC_EN_BIAS                   (1 << 13)
#define REG_CODEC_EN_BIAS_LP                (1 << 14)
#define REG_CODEC_EN_RX_EXT                 (1 << 15)

// REG_B1
#define REG_CODEC_BIAS_IBSEL_SHIFT          0
#define REG_CODEC_BIAS_IBSEL_MASK           (0xF << REG_CODEC_BIAS_IBSEL_SHIFT)
#define REG_CODEC_BIAS_IBSEL(n)             BITFIELD_VAL(REG_CODEC_BIAS_IBSEL, n)
#define REG_CODEC_BIAS_IBSEL_TX_SHIFT       4
#define REG_CODEC_BIAS_IBSEL_TX_MASK        (0xF << REG_CODEC_BIAS_IBSEL_TX_SHIFT)
#define REG_CODEC_BIAS_IBSEL_TX(n)          BITFIELD_VAL(REG_CODEC_BIAS_IBSEL_TX, n)
#define REG_CODEC_BIAS_IBSEL_VOICE_SHIFT    8
#define REG_CODEC_BIAS_IBSEL_VOICE_MASK     (0xF << REG_CODEC_BIAS_IBSEL_VOICE_SHIFT)
#define REG_CODEC_BIAS_IBSEL_VOICE(n)       BITFIELD_VAL(REG_CODEC_BIAS_IBSEL_VOICE, n)
#define CFG_ADC_START                       (1 << 12)


// REG_B2
#define REG_CODEC_EN_VCM                    (1 << 0)
#define REG_CODEC_EN_VCM_BUFFER             (1 << 1)
#define REG_CODEC_LP_VCM                    (1 << 2)
#define RESERVED_DIG_32                     (1 << 3)
#define REG_CODEC_VCM_LOW_VCM_SHIFT         4
#define REG_CODEC_VCM_LOW_VCM_MASK          (0xF << REG_CODEC_VCM_LOW_VCM_SHIFT)
#define REG_CODEC_VCM_LOW_VCM(n)            BITFIELD_VAL(REG_CODEC_VCM_LOW_VCM, n)
#define REG_CODEC_VCM_LOW_VCM_LP_SHIFT      8
#define REG_CODEC_VCM_LOW_VCM_LP_MASK       (0xF << REG_CODEC_VCM_LOW_VCM_LP_SHIFT)
#define REG_CODEC_VCM_LOW_VCM_LP(n)         BITFIELD_VAL(REG_CODEC_VCM_LOW_VCM_LP, n)
#define REG_CODEC_VCM_LOW_VCM_LPF_SHIFT     12
#define REG_CODEC_VCM_LOW_VCM_LPF_MASK      (0xF << REG_CODEC_VCM_LOW_VCM_LPF_SHIFT)
#define REG_CODEC_VCM_LOW_VCM_LPF(n)        BITFIELD_VAL(REG_CODEC_VCM_LOW_VCM_LPF, n)

// REG_B3
#define REG_CODEC_VCM_EN_LPF                (1 << 0)
#define REG_CODEC_BIAS_LOWV                 (1 << 1)
#define REG_CODEC_BIAS_LOWV_LP              (1 << 2)
#define REG_CODEC_BUF_LOWPOWER              (1 << 3)
#define REG_CODEC_BUF_LOWPOWER2             (1 << 4)
#define REG_CODEC_BUF_LOWVCM_SHIFT          5
#define REG_CODEC_BUF_LOWVCM_MASK           (0x7 << REG_CODEC_BUF_LOWVCM_SHIFT)
#define REG_CODEC_BUF_LOWVCM(n)             BITFIELD_VAL(REG_CODEC_BUF_LOWVCM, n)



// REG_160
#define REVID_SHIFT                         0
#define REVID_MASK                          (0xF << REVID_SHIFT)
#define REVID(n)                            BITFIELD_VAL(REVID, n)


// REG_16C
#define CFG_TX_PEAK_OFF_ADC_EN              (1 << 0)
#define CFG_TX_PEAK_OFF_DAC_EN              (1 << 1)
#define CFG_PEAK_DET_DR                     (1 << 2)
#define CFG_TX_PEAK_OFF_ADC                 (1 << 3)
#define CFG_TX_PEAK_OFF_DAC                 (1 << 4)
#define CFG_PEAK_DET_DB_DELAY_SHIFT         5
#define CFG_PEAK_DET_DB_DELAY_MASK          (0x7 << CFG_PEAK_DET_DB_DELAY_SHIFT)
#define CFG_PEAK_DET_DB_DELAY(n)            BITFIELD_VAL(CFG_PEAK_DET_DB_DELAY, n)



// REG_16D
#define REG_CODEC_TX_PEAK_NL_EN             (1 << 0)

#define REG_CODEC_TX_PEAK_PL_EN             (1 << 2)

#define REG_CODEC_TX_PEAK_DET_BIT           (1 << 4)
#define REG_PU_CLKMUX_LDO0P9                (1 << 5)
#define REG_PU_OSC                          (1 << 6)
#define REG_CLKMUX_DVDD_SEL                 (1 << 7)
#define REG_CRYSTAL_SEL_LV                  (1 << 8)
#define REG_IDETLEAR_EN                     (1 << 9)

#define REG_EXTPLL_SEL                      (1 << 11)
#define REG_TX_REGULATOR_BIT_SHIFT          12
#define REG_TX_REGULATOR_BIT_MASK           (0xF << REG_TX_REGULATOR_BIT_SHIFT)
#define REG_TX_REGULATOR_BIT(n)             BITFIELD_VAL(REG_TX_REGULATOR_BIT, n)

// REG_16E
#define REG_CODEC_TX_EAR_DR_EN              (1 << 0)
#define REG_CODEC_TX_EAR_DRE_GAIN_L_UPDATE  (1 << 1)

#define REG_CODEC_TX_EAR_DRE_GAIN_L_SHIFT   3
#define REG_CODEC_TX_EAR_DRE_GAIN_L_MASK    (0x1F << REG_CODEC_TX_EAR_DRE_GAIN_L_SHIFT)
#define REG_CODEC_TX_EAR_DRE_GAIN_L(n)      BITFIELD_VAL(REG_CODEC_TX_EAR_DRE_GAIN_L, n)

#define REG_CODEC_TX_EAR_ENBIAS             (1 << 13)
#define REG_CODEC_TX_EAR_LPBIAS             (1 << 14)
#define REG_CODEC_TX_EAR_OCEN               (1 << 15)

// REG_16F
#define REG_CODEC_TEST_SEL_SHIFT            0
#define REG_CODEC_TEST_SEL_MASK             (0xF << REG_CODEC_TEST_SEL_SHIFT)
#define REG_CODEC_TEST_SEL(n)               BITFIELD_VAL(REG_CODEC_TEST_SEL, n)
#define REG_CODEC_TX_DAC_MUTEL              (1 << 4)

#define REG_CODEC_TX_DAC_SWR_SHIFT          6
#define REG_CODEC_TX_DAC_SWR_MASK           (0x3 << REG_CODEC_TX_DAC_SWR_SHIFT)
#define REG_CODEC_TX_DAC_SWR(n)             BITFIELD_VAL(REG_CODEC_TX_DAC_SWR, n)
#define REG_CODEC_TX_DAC_VREF_L_SHIFT       8
#define REG_CODEC_TX_DAC_VREF_L_MASK        (0xF << REG_CODEC_TX_DAC_VREF_L_SHIFT)
#define REG_CODEC_TX_DAC_VREF_L(n)          BITFIELD_VAL(REG_CODEC_TX_DAC_VREF_L, n)

// REG_170
#define REG_CODEC_TX_EAR_COMP1_SHIFT        0
#define REG_CODEC_TX_EAR_COMP1_MASK         (0xFF << REG_CODEC_TX_EAR_COMP1_SHIFT)
#define REG_CODEC_TX_EAR_COMP1(n)           BITFIELD_VAL(REG_CODEC_TX_EAR_COMP1, n)

// REG_171
#define REG_CODEC_TX_EAR_LOWGAINL_SHIFT     0
#define REG_CODEC_TX_EAR_LOWGAINL_MASK      (0x3F << REG_CODEC_TX_EAR_LOWGAINL_SHIFT)
#define REG_CODEC_TX_EAR_LOWGAINL(n)        BITFIELD_VAL(REG_CODEC_TX_EAR_LOWGAINL, n)

#define REG_CODEC_TX_EAR_IBSEL_SHIFT        12
#define REG_CODEC_TX_EAR_IBSEL_MASK         (0x3 << REG_CODEC_TX_EAR_IBSEL_SHIFT)
#define REG_CODEC_TX_EAR_IBSEL(n)           BITFIELD_VAL(REG_CODEC_TX_EAR_IBSEL, n)
#define REG_CODEC_TX_EAR_LCAL               (1 << 14)


// REG_172
#define REG_CODEC_TX_EAR_OFF_BITL_SHIFT     0
#define REG_CODEC_TX_EAR_OFF_BITL_MASK      (0x3FFF << REG_CODEC_TX_EAR_OFF_BITL_SHIFT)
#define REG_CODEC_TX_EAR_OFF_BITL(n)        BITFIELD_VAL(REG_CODEC_TX_EAR_OFF_BITL, n)
#define REG_CODEC_TX_EAR_OFFEN              (1 << 14)
#define REG_CODEC_TX_EN_DACLDO              (1 << 15)


// REG_173
#define REG_CODEC_TX_EAR_DIS_SHIFT          14
#define REG_CODEC_TX_EAR_DIS_MASK           (0x3 << REG_CODEC_TX_EAR_DIS_SHIFT)
#define REG_CODEC_TX_EAR_DIS(n)             BITFIELD_VAL(REG_CODEC_TX_EAR_DIS, n)

// REG_174
#define REG_CODEC_TX_EAR_SOFTSTART_SHIFT    0
#define REG_CODEC_TX_EAR_SOFTSTART_MASK     (0x3F << REG_CODEC_TX_EAR_SOFTSTART_SHIFT)
#define REG_CODEC_TX_EAR_SOFTSTART(n)       BITFIELD_VAL(REG_CODEC_TX_EAR_SOFTSTART, n)
#define REG_CODEC_TX_EAR_OUTPUTSEL_SHIFT    6
#define REG_CODEC_TX_EAR_OUTPUTSEL_MASK     (0x1F << REG_CODEC_TX_EAR_OUTPUTSEL_SHIFT)
#define REG_CODEC_TX_EAR_OUTPUTSEL(n)       BITFIELD_VAL(REG_CODEC_TX_EAR_OUTPUTSEL, n)
#define REG_CODEC_TX_EAR_DR_ST_SHIFT        11
#define REG_CODEC_TX_EAR_DR_ST_MASK         (0x7 << REG_CODEC_TX_EAR_DR_ST_SHIFT)
#define REG_CODEC_TX_EAR_DR_ST(n)           BITFIELD_VAL(REG_CODEC_TX_EAR_DR_ST, n)
#define REG_CODEC_TX_EAR_FB_SW_SHIFT        14
#define REG_CODEC_TX_EAR_FB_SW_MASK         (0x3 << REG_CODEC_TX_EAR_FB_SW_SHIFT)
#define REG_CODEC_TX_EAR_FB_SW(n)           BITFIELD_VAL(REG_CODEC_TX_EAR_FB_SW, n)

// REG_175
#define REG_CODEC_TX_EN_EARPA_L             (1 << 0)

#define REG_CODEC_TX_EN_LCLK                (1 << 2)
#define REG_CODEC_TX_EN_LDAC                (1 << 3)


#define REG_CODEC_TX_EN_S1PA                (1 << 6)
#define REG_CODEC_TX_EN_S2PA                (1 << 7)
#define REG_CODEC_TX_EN_S3PA                (1 << 8)
#define REG_CODEC_TX_EN_S4PA                (1 << 9)
#define REG_CODEC_TX_EN_S5PA                (1 << 10)
#define REG_PU_TX_REGULATOR                 (1 << 11)
#define REG_BYPASS_TX_REGULATOR             (1 << 12)
#define REG_CODEC_DAC_CLK_EDGE_SEL          (1 << 13)
#define REG_CODEC_TX_EAR_GAIN_SHIFT         14
#define REG_CODEC_TX_EAR_GAIN_MASK          (0x3 << REG_CODEC_TX_EAR_GAIN_SHIFT)
#define REG_CODEC_TX_EAR_GAIN(n)            BITFIELD_VAL(REG_CODEC_TX_EAR_GAIN, n)

// REG_176
#define REG_CODEC_TX_EN_LPPA                (1 << 0)
#define REG_CODEC_TX_SW_MODE                (1 << 1)
#define DRE_GAIN_SEL_L                      (1 << 2)

#define CFG_TX_TREE_EN                      (1 << 4)
#define CFG_TX_CH0_MUTE                     (1 << 5)

#define CFG_TX_CLK_INV                      (1 << 7)
#define CFG_CODEC_DIN_L_RST                 (1 << 8)
#define REG_CODEC_TX_EAR_VCM_SHIFT          9
#define REG_CODEC_TX_EAR_VCM_MASK           (0x7 << REG_CODEC_TX_EAR_VCM_SHIFT)
#define REG_CODEC_TX_EAR_VCM(n)             BITFIELD_VAL(REG_CODEC_TX_EAR_VCM, n)


// REG_177
#define CODEC_DIN_L_HI_RSTVAL_SHIFT         0
#define CODEC_DIN_L_HI_RSTVAL_MASK          (0xFFFF << CODEC_DIN_L_HI_RSTVAL_SHIFT)
#define CODEC_DIN_L_HI_RSTVAL(n)            BITFIELD_VAL(CODEC_DIN_L_HI_RSTVAL, n)

// REG_178
#define CODEC_DIN_L_LO_RSTVAL_SHIFT         0
#define CODEC_DIN_L_LO_RSTVAL_MASK          (0xFFFF << CODEC_DIN_L_LO_RSTVAL_SHIFT)
#define CODEC_DIN_L_LO_RSTVAL(n)            BITFIELD_VAL(CODEC_DIN_L_LO_RSTVAL, n)





// REG_17B
#define REG_CODEC_CASN_L_SHIFT              0
#define REG_CODEC_CASN_L_MASK               (0x3 << REG_CODEC_CASN_L_SHIFT)
#define REG_CODEC_CASN_L(n)                 BITFIELD_VAL(REG_CODEC_CASN_L, n)

#define REG_CODEC_CASP_L_SHIFT              4
#define REG_CODEC_CASP_L_MASK               (0x3 << REG_CODEC_CASP_L_SHIFT)
#define REG_CODEC_CASP_L(n)                 BITFIELD_VAL(REG_CODEC_CASP_L, n)

#define REG_CODEC_TX_IB_SEL_ST2_SHIFT       8
#define REG_CODEC_TX_IB_SEL_ST2_MASK        (0x3 << REG_CODEC_TX_IB_SEL_ST2_SHIFT)
#define REG_CODEC_TX_IB_SEL_ST2(n)          BITFIELD_VAL(REG_CODEC_TX_IB_SEL_ST2, n)

#define REG_CODEC_TX_OC_PATH                (1 << 11)
#define REG_CODEC_TX_OFF_RANGE_X2           (1 << 12)


// REG_17C
#define REG_CODEC_TX_VREFBUF_CAS_L_SHIFT    0
#define REG_CODEC_TX_VREFBUF_CAS_L_MASK     (0x3 << REG_CODEC_TX_VREFBUF_CAS_L_SHIFT)
#define REG_CODEC_TX_VREFBUF_CAS_L(n)       BITFIELD_VAL(REG_CODEC_TX_VREFBUF_CAS_L, n)

#define REG_CODEC_TX_VREFBUF_ISEL_SHIFT     4
#define REG_CODEC_TX_VREFBUF_ISEL_MASK      (0x7 << REG_CODEC_TX_VREFBUF_ISEL_SHIFT)
#define REG_CODEC_TX_VREFBUF_ISEL(n)        BITFIELD_VAL(REG_CODEC_TX_VREFBUF_ISEL, n)

#define REG_DAC_LOWGAIN_SHIFT               9
#define REG_DAC_LOWGAIN_MASK                (0x3 << REG_DAC_LOWGAIN_SHIFT)
#define REG_DAC_LOWGAIN(n)                  BITFIELD_VAL(REG_DAC_LOWGAIN, n)
#define REG_CODEC_TX_VREF_RZ                (1 << 11)





// REG_17D
#define REG_ZERO_DETECT_POWER_DOWN_DIRECT   (1 << 0)
#define REG_ZERO_DETECT_POWER_DOWN          (1 << 1)
#define REG_ZERO_DETECT_CHANGE              (1 << 2)
#define REG_CLOSE_PA                        (1 << 3)
#define REG_CLOSE_PA_DIRECT                 (1 << 4)
#define REG_CLOSE_SPA                       (1 << 5)
#define REG_PU_ZERO_DET_L                   (1 << 6)



// REG_17E
#define REG_CLKMUX_LOWF_IN                  (1 << 5)


// REG_17F
#define TX_PEAK_DET_STATUS                  (1 << 0)
#define TX_PEAK_DET_NL_STATUS               (1 << 1)

#define TX_PEAK_DET_PL_STATUS               (1 << 3)



// REG_186
#define RESERVED_ANA_15_0_SHIFT             0
#define RESERVED_ANA_15_0_MASK              (0xFFFF << RESERVED_ANA_15_0_SHIFT)
#define RESERVED_ANA_15_0(n)                BITFIELD_VAL(RESERVED_ANA_15_0, n)

// REG_187
#define RESERVED_ANA_31_16_SHIFT            0
#define RESERVED_ANA_31_16_MASK             (0xFFFF << RESERVED_ANA_31_16_SHIFT)
#define RESERVED_ANA_31_16(n)               BITFIELD_VAL(RESERVED_ANA_31_16, n)

// REG_188
#define RESERVED_ANA_47_32_SHIFT            0
#define RESERVED_ANA_47_32_MASK             (0xFFFF << RESERVED_ANA_47_32_SHIFT)
#define RESERVED_ANA_47_32(n)               BITFIELD_VAL(RESERVED_ANA_47_32, n)

// REG_189
#define RESERVED_ANA_55_48_SHIFT            0
#define RESERVED_ANA_55_48_MASK             (0xFF << RESERVED_ANA_55_48_SHIFT)
#define RESERVED_ANA_55_48(n)               BITFIELD_VAL(RESERVED_ANA_55_48, n)

// REG_18A
#define REG_CODEC_TX_EAR_GAIN_CHANGE        (1 << 10)


#endif

