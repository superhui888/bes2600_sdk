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
#ifndef __APP_VOICE_ASSIST_PROMPT_LEAK_DETECT_H__
#define __APP_VOICE_ASSIST_PROMPT_LEAK_DETECT_H__

#include "plat_types.h"

#ifdef __cplusplus
extern "C" {
#endif

int32_t app_voice_assist_prompt_leak_detect_init(void);
int32_t app_voice_assist_prompt_leak_detect_open(void);
int32_t app_voice_assist_prompt_leak_detect_close(void);
int32_t app_voice_assist_prompt_leak_detect_set_working_status(int32_t status);

#ifdef __cplusplus
}
#endif

#endif