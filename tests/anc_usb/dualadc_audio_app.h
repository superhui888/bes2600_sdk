/***************************************************************************
 *
 * Copyright 2015-2019 BES.
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
#ifndef __DUALADC_AUDIO_TEST_H__
#define __DUALADC_AUDIO_TEST_H__

#ifdef __cplusplus
extern "C" {
#endif


#include "plat_types.h"

void dualadc_audio_app(bool on);

void dualadc_audio_app_init(uint8_t *play_buf, uint32_t play_size, uint8_t *cap_buf, uint32_t cap_size);

void dualadc_audio_app_term(void);


#ifdef __cplusplus
}
#endif

#endif

