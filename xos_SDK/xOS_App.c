#include "xOS_App.h"
#include "xOS_State.h"
#include "stdio.h"
#include "hal_trace.h"
#include "app_utils.h"
#include "app_thread.h"
#include "cmsis_os.h"
#include "app_thread.h"
#include "app_utils.h"
#include "xOS_Timer.h"



#define XOS_APP_DEBUG_ENABLE
#ifdef  XOS_APP_DEBUG_ENABLE 

#define xos_app_debug(format,...)     TRACE(5,"[xos app]%s (%d) " format "\n",__func__,__LINE__,##__VA_ARGS__);
#else
#define xos_app_debug(format,...) 
#endif


//---------------------------------------------------------------------------------------------------
#define osSTATE_DEFAULT_INEDEX                                      0U
#define osAPP_MONITOR_INTERVER_TIME                                 1000u

static  xOS_App_Op_E     xOS_APP_Current_Op=XOS_APP_OP_INITING_E;
static  xOS_App_State_E  xos_APP_current_State=XOS_APP_STATE_INITING_E;
//static  xOS_App_Op_E     xos_APP_current_PowerOp=XOS_APP_OP_INITING_E;
static  uint8_t xApp_Sleep_Mode = 0;


static uint8_t User_App_Power_SetSleep(uint8_t sleepenable);
#if 1
//add timer configure
static void xos_power_state_timerhandler(void const *param);
osTimerDef(xOS_State_timerID,xos_power_state_timerhandler);
static osTimerId xOS_StateTimerhandlerId = NULL;
#endif

//Powerconsumption
static uint32_t xOS_Increase_PowerConsumption(uint32_t argc ,uint32_t *argv);
static uint32_t xOS_Decrease_PowerConsumption(uint32_t argc ,uint32_t *argv);
static uint32_t xOS_Increase_PowerConsumptionStop(uint32_t argc ,uint32_t *argv);


// UI handle
static void
osState_op_tws_InitDone(xos_handle_state pre,xos_handle_operate operate,xos_handle_state next);
static void
osState_OP_tws_BoxIN_Hanlde(xos_handle_state pre,xos_handle_operate operate,xos_handle_state next);
static void
osState_OP_tws_BoxOut_Hanlde(xos_handle_state pre,xos_handle_operate operate,xos_handle_state next);
static void 
osState_OP_tws_CoverIn_Hanlde(xos_handle_state pre, xos_handle_operate operate, xos_handle_state next);
static void
osState_OP_tws_CoverOut_Hanlde(xos_handle_state pre, xos_handle_operate operate, xos_handle_state next);
static void
osState_OP_tws_WearOff_Hanlde(xos_handle_state pre, xos_handle_operate operate, xos_handle_state next);
static void
osState_OP_tws_WearOn_Hanlde(xos_handle_state pre, xos_handle_operate operate, xos_handle_state next);
static void 
osState_App_handle_public(xos_handle_state pre,xos_handle_operate operate,xos_handle_state next);



/*+---------------------------------------------------------------------------
	              App User Table Init
  +--------------------------------------------------------------------------*/
const xOS_StateInfo appUserTabel[]={

    {XOS_STATE(XOS_APP_STATE_INITING_E    ,  XOS_APP_STATE_INITDONE_E )      ,XOS_APP_OP_INITING_E     , osState_op_tws_InitDone},
    {XOS_STATE(XOS_APP_STATE_INITDONE_E   ,  XOS_APP_STATE_BOX_IN_E   )      ,XOS_APP_OP_BOX_IN_E      , osState_OP_tws_BoxIN_Hanlde},   
    //in box
	{XOS_STATE(XOS_APP_STATE_BOX_IN_E     ,  XOS_APP_STATE_COVER_IN_E )      ,XOS_APP_OP_COVER_IN_E    , osState_OP_tws_CoverIn_Hanlde},
	{XOS_STATE(XOS_APP_STATE_BOX_IN_E     ,  XOS_APP_STATE_COVER_OUT_E )     ,XOS_APP_OP_COVER_OUT_E   , osState_OP_tws_CoverOut_Hanlde},
	//cover in
	{XOS_STATE(XOS_APP_STATE_COVER_IN_E   ,  XOS_APP_STATE_COVER_OUT_E )     ,XOS_APP_OP_COVER_IN_E    , osState_OP_tws_CoverOut_Hanlde},
	{XOS_STATE(XOS_APP_STATE_COVER_IN_E   ,  XOS_APP_STATE_BOX_IN_E )        ,XOS_APP_OP_BOX_IN_E      , osState_OP_tws_BoxIN_Hanlde},
	//cover out
	{XOS_STATE(XOS_APP_STATE_COVER_OUT_E  ,  XOS_APP_STATE_COVER_IN_E )      ,XOS_APP_OP_COVER_IN_E    , osState_OP_tws_CoverIn_Hanlde},
	{XOS_STATE(XOS_APP_STATE_COVER_OUT_E  ,  XOS_APP_OP_BOX_OUT_E )          ,XOS_APP_OP_BOX_OUT_E     , osState_OP_tws_BoxOut_Hanlde},
	//out box 
	{XOS_STATE(XOS_APP_OP_BOX_OUT_E       ,  XOS_APP_STATE_WEAR_ON_E )       ,XOS_APP_OP_WEAR_ON_E     , osState_OP_tws_WearOn_Hanlde},
    {XOS_STATE(XOS_APP_OP_BOX_OUT_E       ,  XOS_APP_STATE_BOX_IN_E )        ,XOS_APP_OP_BOX_IN_E      , osState_OP_tws_BoxIN_Hanlde},
	//wear on
	{XOS_STATE(XOS_APP_STATE_WEAR_ON_E    ,  XOS_APP_STATE_BOX_IN_E )        ,XOS_APP_OP_WEAR_ON_E     , osState_OP_tws_WearOn_Hanlde},
	{XOS_STATE(XOS_APP_STATE_WEAR_ON_E    ,  XOS_APP_STATE_WAER_OFF_E )      ,XOS_APP_OP_WEAR_OFF_E    , osState_OP_tws_WearOff_Hanlde},
	//wear off
	{XOS_STATE(XOS_APP_STATE_WAER_OFF_E   ,  XOS_APP_STATE_WEAR_ON_E )       ,XOS_APP_OP_WEAR_ON_E    , osState_OP_tws_WearOn_Hanlde},
	{XOS_STATE(XOS_APP_STATE_WAER_OFF_E   ,  XOS_APP_STATE_BOX_IN_E )        ,XOS_APP_OP_BOX_IN_E      , osState_OP_tws_BoxIN_Hanlde},

};

const char * xOS_OP_String[]={
	"XOS_APP_OP_INITING_E",
	"XOS_APP_OP_INITDONE_E",
	"XOS_APP_OP_BOX_IN_E",
	"XOS_APP_OP_BOX_OUT_E",
	"XOS_APP_OP_COVER_IN_E",
	"XOS_APP_OP_COVER_OUT_E",
	"XOS_APP_OP_WEAR_ON_E",
	"XOS_APP_OP_WEAR_OFF_E",
};

// osstate 
const char * xOS_Sate_String[]={
	"XOS_APP_STATE_INITING_E",
	"XOS_APP_STATE_INITDONE_E",
	"XOS_APP_STATE_BOX_IN_E",
	"XOS_APP_STATE_BOX_OUT_E",
	"XOS_APP_STATE_COVER_IN_E",
	"XOS_APP_STATE_COVER_OUT_E",
	"XOS_APP_STATE_WEAR_ON_E",
	"XOS_APP_STATE_WAER_OFF_E",
};

static void osState_op_tws_InitDone(xos_handle_state pre,xos_handle_operate operate,xos_handle_state next)
{
	xos_app_debug("\r\n -------osState_op_tws_InitDone");
};
	
static void osState_OP_tws_BoxIN_Hanlde(xos_handle_state pre,xos_handle_operate operate,xos_handle_state next)
{
	xos_app_debug("\r\n -------osState_OP_tws_BoxIN_Hanlde");
}

static void osState_OP_tws_CoverIn_Hanlde(xos_handle_state pre, xos_handle_operate operate, xos_handle_state next)
{
	xos_app_debug("\r\n -------osState_OP_tws_CoverIn_Hanlde");
}


static void osState_OP_tws_CoverOut_Hanlde(xos_handle_state pre, xos_handle_operate operate, xos_handle_state next)
{
	xos_app_debug("\r\n --------osState_OP_tws_CoverOut_Hanlde");
}

/*
static void osState_OP_Initing(xos_handle_state pre,xos_handle_operate operate,xos_handle_state next)
{
	xos_app_debug("osState_OP_Initing");
	//----------------------------------------------------------

	//----------------------------------------------------------
}*/

static void osState_OP_tws_BoxOut_Hanlde(xos_handle_state pre,xos_handle_operate operate,xos_handle_state next)
{
	xos_app_debug("\r\n -------osState_OP_tws_BoxOut_Hanlde");
}


static void osState_OP_tws_WearOff_Hanlde(xos_handle_state pre, xos_handle_operate operate, xos_handle_state next)
{
	xos_app_debug("\r\n -------osState_OP_tws_WearOff_Hanlde");
}


static void osState_OP_tws_WearOn_Hanlde(xos_handle_state pre, xos_handle_operate operate, xos_handle_state next)
{
	xos_app_debug("\r\n -------osState_OP_tws_WearOn_Hanlde");
}


static void osState_App_handle_public(xos_handle_state pre, xos_handle_operate operate, xos_handle_state next)
{
	//xos_app_debug("osState_App_handle_public");
	xos_APP_current_State=pre;
    //xos_app_debug("\r\n--pre state[%s][next:%s]",xOS_Sate_String[pre],xOS_Sate_String[next]);
}

/*+---------------------------------------------------------------------------
			      App User Table End
	+--------------------------------------------------------------------------*/


#if 1
static void xos_power_state_timerhandler(void const *param)
{
	#ifdef XOS_POWER_AUTO_ADJUST_ENABLE
	if( xApp_Sleep_Mode ==1 ){
		app_sysfreq_req(APP_SYSFREQ_USER_APP_INIT, APP_SYSFREQ_32K );
		xos_app_debug("osState_OP_tws_BoxIN_Hanlde APP_SYSFREQ_32K ");
	}
	#endif
}
#endif

static uint32_t User_APP_PowerStateTableInit(uint32_t argc ,uint32_t *argv)
{
    os_HanldeTableInit(0,appUserTabel,sizeof(appUserTabel)/sizeof(appUserTabel[0]));

    os_handleTable_PublicHandle_Register(0, osState_App_handle_public);

	xos_app_debug("ADV timeout duration :[%d]", osSTATE_DEFAULT_INEDEX);

	os_Handle_StateSwitch(osSTATE_DEFAULT_INEDEX, XOS_APP_OP_INITING_E);

	User_App_Power_SetSleep(0);

	return 0;
}

uint8_t User_APP_Init(void)
{
	User_APP_PowerStateTableInit(0,NULL);

	#ifdef XOS_POWER_AUTO_ADJUST_ENABLE
	//create timer 
	if(xOS_StateTimerhandlerId==NULL){
		xOS_StateTimerhandlerId=osTimerCreate (osTimer(xOS_State_timerID), osTimerPeriodic, NULL);
        //osTimerStart(xOS_StateTimerhandlerId,500);
  	}
	#endif
	
	#if 1
	 if(xOS_SDKCreate_Timer()){
		xos_app_debug(" create time error !");
	 }
	 #endif

	//Software_TimerStart(xOS_Timer_Module_POWERCONSUMPTION_ID,JW_SOFTWARE_PERIOD_ONECE,5000,User_APP_PowerStateTableInit,0,NULL);

	return osState_True;
}

uint32_t xos_enter_sleppcallback(uint32_t argc ,uint32_t *argv)
{
	argc=argc;
	argv=argv;
	
	if(osTimerIsRunning(xOS_StateTimerhandlerId)){
			osTimerStop(xOS_StateTimerhandlerId);
	}
	osTimerStart(xOS_StateTimerhandlerId,osAPP_MONITOR_INTERVER_TIME);
	xos_app_debug("jw  start monitor timer run ...");
	return 0;
}



uint8_t User_APP_PowerState_Set(xOS_App_Op_E op)
{	
	xos_app_debug("%s ,OP: %s",__func__,xOS_OP_String[op]);
 	switch(op){

		case XOS_APP_OP_BOX_IN_E:
			xos_app_debug("jw XOS_APP_OP_BOX_IN_E");
			//Software_TimerCancel(xOS_Timer_Module_POWERCONSUMPTION_ID);
			//Software_TimerStart(xOS_Timer_Module_POWERCONSUMPTION_ID,JW_SOFTWARE_PERIOD_ONECE,5000,xOS_Decrease_PowerConsumption,0,NULL);
		break;

		case XOS_APP_OP_BOX_OUT_E:
			xos_app_debug("jw XOS_APP_OP_BOX_OUT_E");
			//Software_TimerCancel(xOS_Timer_Module_POWERCONSUMPTION_ID);
			//Software_TimerStart(xOS_Timer_Module_POWERCONSUMPTION_ID,JW_SOFTWARE_PERIOD_ONECE,1,xOS_Increase_PowerConsumption,0,NULL);
		break;

		case XOS_APP_OP_COVER_IN_E:
		    xos_app_debug("jw XOS_APP_OP_COVER_IN_E");
			//Software_TimerCancel(xOS_Timer_Module_POWERCONSUMPTION_ID);
			//Software_TimerStart(xOS_Timer_Module_POWERCONSUMPTION_ID,JW_SOFTWARE_PERIOD_ONECE,5000,xOS_Decrease_PowerConsumption,0,NULL);
		break;

		case XOS_APP_OP_COVER_OUT_E:
			xos_app_debug("jw XOS_APP_OP_COVER_OUT_E");
			//Software_TimerCancel(xOS_Timer_Module_POWERCONSUMPTION_ID);
			//Software_TimerStart(xOS_Timer_Module_POWERCONSUMPTION_ID,JW_SOFTWARE_PERIOD_ONECE,1,xOS_Increase_PowerConsumption,0,NULL);
		break;

		case XOS_APP_OP_WEAR_ON_E:
			xos_app_debug("jw XOS_APP_STATE_WEAR_ON_E");
			//Software_TimerCancel(xOS_Timer_Module_POWERCONSUMPTION_ID);
			//Software_TimerStart(xOS_Timer_Module_POWERCONSUMPTION_ID,JW_SOFTWARE_PERIOD_ONECE,10,xOS_Increase_PowerConsumption,0,NULL);
		break;

		case XOS_APP_OP_WEAR_OFF_E:
			xos_app_debug("jw XOS_APP_STATE_WAER_OFF_E");
		    //Software_TimerCancel(xOS_Timer_Module_POWERCONSUMPTION_ID);
			//Software_TimerStart(xOS_Timer_Module_POWERCONSUMPTION_ID,JW_SOFTWARE_PERIOD_ONECE,5000,xOS_Decrease_PowerConsumption,0,NULL);
		break;

		default:
		break;

	}
	os_Handle_StateSwitch(osSTATE_DEFAULT_INEDEX,op);
	xOS_APP_Current_Op=op;

	Software_TimerCancel(xOS_Timer_Module_POWERCONSUMPTION_ID);
	Software_TimerStart(xOS_Timer_Module_POWERCONSUMPTION_ID,JW_SOFTWARE_PERIOD_ONECE,5000,xOS_Increase_PowerConsumption,0,NULL);
	app_sysfreq_req(APP_SYSFREQ_USER_APP_INIT,APP_SYSFREQ_26M);
	xos_app_debug("xOS_Increase_PowerConsumption start---> from 26M");
    return 0;
}


static uint8_t User_App_Power_SetSleep(uint8_t sleepenable)
{
    xApp_Sleep_Mode = sleepenable;
	return 0;
}

uint8_t User_App_Power_GetSleep(void)
{
	return xApp_Sleep_Mode;
}


static uint32_t xOS_Increase_PowerConsumption(uint32_t argc ,uint32_t *argv)
{
	
	#if 0
	if( (xOS_APP_Current_Op==XOS_APP_OP_WEAR_ON_E) || (xOS_APP_Current_Op==XOS_APP_OP_COVER_OUT_E) || (xOS_APP_Current_Op==XOS_APP_OP_BOX_OUT_E) ){
		app_sysfreq_req(APP_SYSFREQ_USER_APP_INIT, HAL_CMU_FREQ_52M);
		Software_TimerStart(xOS_Timer_Module_POWERCONSUMPTION_ID,JW_SOFTWARE_PERIOD_ONECE,5000,xOS_Increase_PowerConsumptionStop,0,NULL);
	}else{

	}
	#endif
	 app_sysfreq_req(APP_SYSFREQ_USER_APP_INIT, HAL_CMU_FREQ_32K);
	 xos_app_debug("xOS_Increase_PowerConsumption stop---> to 32K");
	//Software_TimerStart(xOS_Timer_Module_POWERCONSUMPTION_ID,JW_SOFTWARE_PERIOD_ONECE,5000,xOS_Increase_PowerConsumptionStop,0,NULL);
	xOS_Increase_PowerConsumptionStop(0,NULL);
	xOS_Decrease_PowerConsumption(0,NULL);
	return false;
}
static uint32_t xOS_Increase_PowerConsumptionStop(uint32_t argc ,uint32_t *argv)
{
	//xos_app_debug("xOS_Increase_PowerConsumptionStop ");
    //app_sysfreq_req(APP_SYSFREQ_USER_APP_INIT, HAL_CMU_FREQ_32K);
	//xOS_Decrease_PowerConsumption(0,NULL);
	return false;
}


static uint32_t xOS_Decrease_PowerConsumption(uint32_t argc ,uint32_t *argv)
{
	xos_app_debug("xOS_Decrease_PowerConsumption <---");
	#if 0
	if( (xOS_APP_Current_Op==XOS_APP_OP_WEAR_OFF_E) || (xOS_APP_Current_Op==XOS_APP_OP_COVER_IN_E) || (xOS_APP_Current_Op==XOS_APP_OP_BOX_IN_E) ){
		app_sysfreq_req(APP_SYSFREQ_USER_APP_INIT, HAL_CMU_FREQ_32K);
	}else{

	}
	#endif
	return false;
}



