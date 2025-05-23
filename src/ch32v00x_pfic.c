/********************************** (C) COPYRIGHT *******************************
 * File Name          : ch32v00x_misc.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2022/08/08
 * Description        : This file provides all the miscellaneous firmware functions .
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

#include "ch32v00x_pfic.h"

/*********************************************************************
 * @fn      PFIC_Init
 *
 * @brief   Initializes the PFIC peripheral according to the specified parameters in
 *        the PFIC_InitStruct.
 * 
 * @note see PFIC_Config for configuring interrupt nesting function.
 *
 * @param   PFIC_InitStruct - pointer to a PFIC_InitTypeDef structure that contains the
 *        configuration information for the specified PFIC peripheral.
 *            interrupt nesting enabled:
 *              PFIC_IRQChannelPreemptionPriority - range from 0 to 1.
 *              PFIC_IRQChannelSubPriority - range from 0 to 1.
 *
 *            interrupt nesting disabled:
 *              PFIC_IRQChannelPreemptionPriority - range is 0.
 *              PFIC_IRQChannelSubPriority - range from 0 to 3.
 * @param   PFIC_PriorityGroup - specifies the priority grouping bits length.
 *            PFIC_PriorityGroup_0: interrupt nesting disabled
 *            PFIC_PriorityGroup_1: interrupt nesting enabled
 * 
 * @return  none
 */
void PFIC_Init(PFIC_InitTypeDef *PFIC_InitStruct, uint32_t PFIC_PriorityGroup)
{
    if (PFIC_PriorityGroup == PFIC_PriorityGroup_0)
    {
        uint8_t sub = PFIC_InitStruct->PFIC_IRQChannelSubPriority & 0x2;
        PFIC_SetPriority(PFIC_InitStruct->PFIC_IRQChannel, (sub << 6));
    }
    else if (PFIC_PriorityGroup == PFIC_PriorityGroup_1)
    {
        uint8_t pre = PFIC_InitStruct->PFIC_IRQChannelPreemptionPriority & 0x1;
        uint8_t sub = PFIC_InitStruct->PFIC_IRQChannelSubPriority & 0x1;
        PFIC_SetPriority(PFIC_InitStruct->PFIC_IRQChannel, (pre << 7) | (sub << 6));
    }

    if(PFIC_InitStruct->PFIC_IRQChannelCmd != DISABLE)
    {
        PFIC_EnableIRQ(PFIC_InitStruct->PFIC_IRQChannel);
    }
    else
    {
        PFIC_DisableIRQ(PFIC_InitStruct->PFIC_IRQChannel);
    }
}