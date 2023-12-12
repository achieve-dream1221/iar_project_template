#ifndef ZCL_GENERICAPP_H
#define ZCL_GENERICAPP_H

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************************************************
 * INCLUDES
 */
#include "zcl.h"


// Added to include ZLL Target functionality
#if defined ( BDB_TL_INITIATOR ) || defined ( BDB_TL_TARGET )
  #include "zcl_general.h"
  #include "bdb_tlCommissioning.h"
#endif

/*********************************************************************
 * CONSTANTS
 */
#define GENERICAPP_ENDPOINT            8
// Added to include ZLL Target functionality
#define GENERICAPP_NUM_GRPS            2


// Application Events
#define GENERICAPP_MAIN_SCREEN_EVT          0x0001
#define GENERICAPP_LEVEL_CTRL_EVT           0x0002
#define GENERICAPP_END_DEVICE_REJOIN_EVT    0x0004

/* GENERICAPP_TODO: define app events here */

#define GENERICAPP_EVT_1                    0x0008
/*
#define GENERICAPP_EVT_2                    0x0010
#define GENERICAPP_EVT_3                    0x0020
*/

// Application Display Modes
#define GENERIC_MAINMODE      0x00
#define GENERIC_HELPMODE      0x01

#define GENERICAPP_END_DEVICE_REJOIN_DELAY 10000

/*********************************************************************
 * MACROS
 */
/*********************************************************************
 * TYPEDEFS
 */

/*********************************************************************
 * VARIABLES
 */

// Added to include ZLL Target functionality
#if defined ( BDB_TL_INITIATOR ) || defined ( BDB_TL_TARGET )
  extern bdbTLDeviceInfo_t tlGenericApp_DeviceInfo;
#endif

extern SimpleDescriptionFormat_t zclGenericApp_SimpleDesc;

extern CONST zclCommandRec_t zclGenericApp_Cmds[];

extern CONST uint8 zclCmdsArraySize;

// attribute list
extern CONST zclAttrRec_t zclGenericApp_Attrs[];
extern CONST uint8 zclGenericApp_NumAttributes;

// Identify attributes
extern uint16 zclGenericApp_IdentifyTime;
extern uint8  zclGenericApp_IdentifyCommissionState;

// GENERICAPP_TODO: Declare application specific attributes here


/*********************************************************************
 * FUNCTIONS
 */

 /*
  * Initialization for the task
  */
extern void zclGenericApp_Init( byte task_id );

/*
 *  Event Process for the task
 */
extern UINT16 zclGenericApp_event_loop( byte task_id, UINT16 events );

/*
 *  Reset all writable attributes to their default values.
 */
extern void zclGenericApp_ResetAttributesToDefaultValues(void);


/*********************************************************************
*********************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* ZCL_GENERICAPP_H */
