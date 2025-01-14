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


/**
 ****************************************************************************************
 * @addtogroup APP
 * @{
 ****************************************************************************************
 */

/*
 * INCLUDE FILES
 ****************************************************************************************
 */

#include "rwip_config.h"

#if (BLE_APP_PRESENT)
#if (BLE_ANC_CLIENT)

#include "app_ancc.h"                  // Health Thermometer Application Definitions
#include "app.h"                     // Application Definitions
#include "app_task.h"                // application task definitions
#include "ancc_task.h"               // health thermometer functions
#include "co_bt.h"
#include "prf_types.h"
#include "prf_utils.h"
#include "arch.h"                    // Platform Definitions

#include "co_math.h"
#include "ke_timer.h"

/*
 * FUNCTION DEFINITIONS
 ****************************************************************************************
*/

void app_ancc_add_ancc(void)
{
    BLE_APP_DBG("app_ancc_add_ancc");
    struct gapm_profile_task_add_cmd *req = KE_MSG_ALLOC_DYN(GAPM_PROFILE_TASK_ADD_CMD,
                                                             TASK_GAPM,
                                                             TASK_APP,
                                                             gapm_profile_task_add_cmd,
                                                             0);

    // Fill message
    req->operation = GAPM_PROFILE_TASK_ADD;
#if BLE_CONNECTION_MAX > 1
    req->sec_lvl = PERM(SVC_AUTH, ENABLE) | PERM(SVC_MI, ENABLE);
#else
    req->sec_lvl = PERM(SVC_AUTH, ENABLE);
#endif

    req->prf_task_id = TASK_ID_ANCC;
    req->app_task = TASK_APP;
    req->start_hdl = 0;

    // Send the message
    ke_msg_send(req);
}

/**
 ****************************************************************************************
 * @brief Initialize application and enable ANCC profile.
 *
 ****************************************************************************************
 */
void app_ancc_enable(uint8_t conidx)
{
    BLE_FUNC_ENTER();

    // Allocate the message
    struct ancc_enable_req *req = KE_MSG_ALLOC(ANCC_ENABLE_REQ,
                                               KE_BUILD_ID(prf_get_task_from_id(TASK_ID_ANCC), conidx),
                                               TASK_APP,
                                               ancc_enable_req);

    // Fill in the parameter structure

    req->conidx = conidx;

    // Send the message
    ke_msg_send(req);
}

#endif  //BLE_ANC_CLIENT
#endif  //BLE_APP_PRESENT

/// @} APP
