/*!****************************************************************************
 * @file
 * ch32v00x_stk.h
 *
 * @brief
 * SysTick Core Peripheral
 *
 * @date  21.03.2023
 ******************************************************************************/

/*- Header includes ----------------------------------------------------------*/
#include "ch32v00x_stk.h"


/*- Peripheral access functions ----------------------------------------------*/
/*!****************************************************************************
 * @brief
 * Configure SysTick timer
 *
 * @param[in] *init       Initialisation data
 * @date  21.03.2023
 ******************************************************************************/
void SysTick_Init(const SysTick_InitTypeDef* init)
{
  SysTick->CTLR = 0u;

  register uint32_t ulTmp = 0;
  if (init->SysTick_ClockPrescaler == SYSTICK_HCLK_Div1)
  {
    ulTmp |= SYSTICK_CTLR_STCLK_DIV1;
  }
  if (init->SysTick_CompareReload == ENABLE)
  {
    ulTmp |= SYSTICK_CTLR_STRE;
  }

  SysTick->CTLR = ulTmp;
  SysTick->CMPR = init->SysTick_CompareValue;
  SysTick->CNTR = init->SysTick_CounterPreload;
  SysTick->SR   = 0u;
}

/*!****************************************************************************
 * @brief
 * Enable or disable SysTick compare interrupt
 *
 * @param[in] state       Interrupt enable state
 * @date  21.03.2023
 ******************************************************************************/
void SysTick_ITConfig(FunctionalState state)
{
  if (state != DISABLE)
  {
    SysTick->CTLR |= SYSTICK_CTLR_STIE;
  }
  else
  {
    SysTick->CTLR &= ~SYSTICK_CTLR_STIE;
  }
}

/*!****************************************************************************
 * @brief
 * Get SysTick compare interrupt status
 *
 * @return  (ITStatus)  State whether compare interrupt has occurred or not
 * @date  21.03.2023
 ******************************************************************************/
ITStatus SysTick_GetITStatus(void)
{
  return (SysTick->SR & SYSTICK_SR_CNTIF) ? SET : RESET;
}

/*!****************************************************************************
 * @brief
 * Clear SysTick compare interrupt pending bit
 *
 * @date  21.03.2023
 ******************************************************************************/
void SysTick_ClearITPendingBit(void)
{
  SysTick->SR = 0u;
}

/*!****************************************************************************
 * @brief
 * Set SysTick counter state
 *
 * @param[in] state       Enable or disable counter
 * @date  21.03.2023
 ******************************************************************************/
void SysTick_Cmd(FunctionalState state)
{
  if (state != DISABLE)
  {
    SysTick->CTLR |= SYSTICK_CTLR_STE;
  }
  else
  {
    SysTick->CTLR &= ~SYSTICK_CTLR_STE;
  }
}
