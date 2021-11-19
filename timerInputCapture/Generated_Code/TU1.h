/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : TU1.h
**     Project     : ProcessorExpert
**     Processor   : MK60FN1M0VLQ15
**     Component   : TimerUnit_LDD
**     Version     : Component 01.158, Driver 01.11, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2021-10-08, 16:38, # CodeGen: 9
**     Abstract    :
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
**     Settings    :
**          Component name                                 : TU1
**          Module name                                    : FTM3
**          Counter                                        : FTM3_CNT
**          Counter direction                              : Up
**          Counter width                                  : 16 bits
**          Value type                                     : uint16_t
**          Input clock source                             : Internal
**            Counter frequency                            : Auto select
**          Counter restart                                : On-overrun
**            Overrun period                               : 1 sec
**            Interrupt                                    : Disabled
**          Channel list                                   : 1
**            Channel 0                                    : 
**              Mode                                       : Capture
**                Capture                                  : FTM3_C0V
**                Capture input pin                        : PTE5/SPI1_PCS2/UART3_RX/SDHC0_D2/FTM3_CH0
**                Capture input signal                     : 
**                Edge                                     : both edges
**                Maximum time of event                    : 3.125018624 ms
**                Interrupt                                : Disabled
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnCounterRestart                           : Disabled
**              OnChannel0                                 : Disabled
**              OnChannel1                                 : Disabled
**              OnChannel2                                 : Disabled
**              OnChannel3                                 : Disabled
**              OnChannel4                                 : Disabled
**              OnChannel5                                 : Disabled
**              OnChannel6                                 : Disabled
**              OnChannel7                                 : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init            - LDD_TDeviceData* TU1_Init(LDD_TUserData *UserDataPtr);
**         ResetCounter    - LDD_TError TU1_ResetCounter(LDD_TDeviceData *DeviceDataPtr);
**         GetCaptureValue - LDD_TError TU1_GetCaptureValue(LDD_TDeviceData *DeviceDataPtr, uint8_t...
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file TU1.h
** @version 01.11
** @brief
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
*/         
/*!
**  @addtogroup TU1_module TU1 module documentation
**  @{
*/         

#ifndef __TU1_H
#define __TU1_H

/* MODULE TU1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "FTM_PDD.h"
#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 


#ifndef __BWUserType_TU1_TValueType
#define __BWUserType_TU1_TValueType
  typedef uint16_t TU1_TValueType ;    /* Type for data parameters of methods */
#endif
#define TU1_CNT_INP_FREQ_U_0 0x01400000UL /* Counter input frequency in Hz */
#define TU1_CNT_INP_FREQ_R_0 20971395.017196544F /* Counter input frequency in Hz */
#define TU1_CNT_INP_FREQ_COUNT 0U      /* Count of predefined counter input frequencies */
#define TU1_PERIOD_TICKS   0x00010000UL /* Initialization value of period in 'counter ticks' */
#define TU1_NUMBER_OF_CHANNELS 0x01U   /* Count of predefined channels */
#define TU1_COUNTER_WIDTH  0x10U       /* Counter width in bits  */
#define TU1_COUNTER_DIR    DIR_UP      /* Direction of counting */
/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define TU1_PRPH_BASE_ADDRESS  0x400B9000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define TU1_Init_METHOD_ENABLED        /*!< Init method of the component TU1 is enabled (generated) */
#define TU1_ResetCounter_METHOD_ENABLED /*!< ResetCounter method of the component TU1 is enabled (generated) */
#define TU1_GetCaptureValue_METHOD_ENABLED /*!< GetCaptureValue method of the component TU1 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */



/*
** ===================================================================
**     Method      :  TU1_Init (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the
**         property ["Enable in init. code"] is set to "yes" value then
**         the device is also enabled (see the description of the
**         [Enable] method). In this case the [Enable] method is not
**         necessary and needn't to be generated. This method can be
**         called only once. Before the second call of Init the [Deinit]
**         must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* TU1_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  TU1_ResetCounter (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Resets counter. If counter is counting up then it is set to
**         zero. If counter is counting down then counter is updated to
**         the reload value.
**         The method is not available if HW doesn't allow resetting of
**         the counter.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError TU1_ResetCounter(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  TU1_GetCaptureValue (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Returns the content of capture register specified by the
**         parameter ChannelIdx. This method is available when at least
**         one channel is configured.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by [Init] method.
**     @param
**         ChannelIdx      - Index of the component
**                           channel.
**     @param
**         ValuePtr        - Pointer to return value of the
**                           capture register.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_PARAM_INDEX - ChannelIdx parameter is
**                           out of possible range
**                           ERR_NOTAVAIL -  The capture mode is not
**                           selected for selected channel.
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError TU1_GetCaptureValue(LDD_TDeviceData *DeviceDataPtr, uint8_t ChannelIdx, TU1_TValueType *ValuePtr);

/* END TU1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif
/* ifndef __TU1_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
