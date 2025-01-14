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
#ifndef OS_TCB_H
#define OS_TCB_H

/* Types */
typedef char               S8;
typedef unsigned char      U8;
typedef short              S16;
typedef unsigned short     U16;
typedef int                S32;
typedef unsigned int       U32;
typedef long long          S64;
typedef unsigned long long U64;
typedef unsigned char      BIT;
typedef unsigned int       BOOL;
typedef void               (*FUNCP)(void);

typedef struct OS_TCB {
  /* General part: identical for all implementations.                        */
  U8     cb_type;                 /* Control Block Type                      */
  U8     state;                   /* Task state                              */
  U8     prio;                    /* Execution priority                      */
  U8     task_id;                 /* Task ID value for optimized TCB access  */
  struct OS_TCB *p_lnk;           /* Link pointer for ready/sem. wait list   */
  struct OS_TCB *p_rlnk;          /* Link pointer for sem./mbx lst backwards */
  struct OS_TCB *p_dlnk;          /* Link pointer for delay list             */
  struct OS_TCB *p_blnk;          /* Link pointer for delay list backwards   */
  U16    delta_time;              /* Time until time out                     */
  U16    interval_time;           /* Time interval for periodic waits        */
  U16    events;                  /* Event flags                             */
  U16    waits;                   /* Wait flags                              */
  void   **msg;                   /* Direct message passing when task waits  */

  /* Hardware dependant part: specific for CM processor                      */
  U8     stack_frame;             /* Stack frame: 0=Basic, 1=Extended        */
  U8     reserved1;
  U16    reserved2;
  U32    priv_stack;              /* Private stack size in bytes             */
  U32    tsk_stack;               /* Current task Stack pointer (R13)        */
  U32    *stack;                  /* Pointer to Task Stack memory block      */

  /* Library dependant part                                                   */
#if defined (__CC_ARM) && !defined (__MICROLIB)
 /* A memory space for arm standard library. */
  U32 std_libspace[96/4];
#endif
#if __RTX_CPU_STATISTICS__
  U32    swap_in_time;            /* the task schedule in time              */
  U32    swap_out_time;           /* the task schedule out time             */
  U32    rtime;                   /* the task runing time after startup     */
  U8     *name;
#if TASK_HUNG_CHECK_ENABLED
  U8     hung_check;
  U32    hung_check_timeout;
#endif
#endif /* __RTX_CPU_STATISTICS__*/

  /* Task entry point used for uVision debugger                              */
  FUNCP  ptask;                   /* Task entry address                      */
} *P_TCB;

#endif
