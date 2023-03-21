/*!****************************************************************************
 * @file
 * ch32v00x_stk.h
 *
 * @brief
 * SysTick Core Peripheral
 *
 * @date  21.03.2023
 ******************************************************************************/

#ifndef CH32V00X_STK_H_
#define CH32V00X_STK_H_

/*- Header includes ----------------------------------------------------------*/
#include "ch32v00x.h"


/*- Type definitions ---------------------------------------------------------*/
/* SysTick Clock Divider Selector                                             */
typedef enum
{
  SYSTICK_HCLK_Div8,                  /*!< f_STK = f_HCLK / 8                 */
  SYSTICK_HCLK_Div1,                  /*!< f_STK = f_HCLK                     */
} SysTick_ClockPre;

/* Systick Initialisation Data                                                */
typedef struct
{
  FunctionalState SysTick_CompareReload;  /*< Upon reaching CMPR, the timer
                                           *  will automatically reload to zweo
                                           *  and continue counting           */
  SysTick_ClockPre SysTick_ClockPrescaler;  /*< Clock Prescaler (/1 or /8)    */
  uint32_t SysTick_CompareValue;      /*< Counter Compare value               */
  uint32_t SysTick_CounterPreload;    /*< Counter Preload value               */
} SysTick_InitTypeDef;


/*- Peripheral Access Functions ----------------------------------------------*/
void SysTick_Init(const SysTick_InitTypeDef* init);
void SysTick_ITConfig(FunctionalState state);
ITStatus SysTick_GetITStatus(void);
void SysTick_ClearITPendingBit(void);
void SysTick_Cmd(FunctionalState state);

#endif /* CH32V00X_STK_H_ */
