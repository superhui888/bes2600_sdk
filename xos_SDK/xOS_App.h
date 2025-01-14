#ifndef  __XOS_APP_H_
#define  __XOS_APP_H_

#include "xOS_State.h"

#ifdef __cplusplus
	extern "C"{
#endif

#include "stdint.h"
#define osState_Error 1
#define osState_True  0


//common function 
#define XOS_POWER_AUTO_ADJUST_ENABLEx 


//---xapp_state_typedef
typedef enum{

	XOS_APP_STATE_INITING_E=0,
	XOS_APP_STATE_INITDONE_E,
	XOS_APP_STATE_BOX_IN_E,
	XOS_APP_STATE_BOX_OUT_E,
	XOS_APP_STATE_COVER_IN_E,
	XOS_APP_STATE_COVER_OUT_E,
	XOS_APP_STATE_WEAR_ON_E,
	XOS_APP_STATE_WAER_OFF_E,

}xOS_App_State_E;

typedef enum{
	
XOS_APP_OP_INITING_E=0,
XOS_APP_OP_INITDONE_E,
XOS_APP_OP_BOX_IN_E,
XOS_APP_OP_BOX_OUT_E,
XOS_APP_OP_COVER_IN_E,
XOS_APP_OP_COVER_OUT_E,
XOS_APP_OP_WEAR_ON_E,
XOS_APP_OP_WEAR_OFF_E,

}xOS_App_Op_E;

uint8_t User_APP_Init(void);

uint8_t User_APP_PowerState_Set(xOS_App_Op_E op);

uint8_t User_App_Power_GetSleep(void);

#ifdef __cplusplus
	}
#endif

#endif
