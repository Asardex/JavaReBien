/**
******************************************************************************
* @file    platform_init.h
* @author  MCD Application Team
* @version V1.0.0
* @date    04-Aout-2017
* @brief   Board HW init
******************************************************************************
* @attention
*
* <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice,
*      this list of conditions and the following disclaimer.
*   2. Redistributions in binary form must reproduce the above copyright notice,
*      this list of conditions and the following disclaimer in the documentation
*      and/or other materials provided with the distribution.
*   3. Neither the name of STMicroelectronics nor the names of its contributors
*      may be used to endorse or promote products derived from this software
*      without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************
*/
#ifndef __Platform_Init__
#define __Platform_Init__
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "FreeRTOS.h"
#include "task.h"

#include "stm32f7xx.h"
#include "stm32f7xx_hal.h"
#include "stm32f769i_discovery.h"
#include "stm32f769i_discovery_lcd.h"
#include "stm32f769i_discovery_ts.h"
#include "stm32f769i_discovery_qspi.h"
#include "stm32f7xx_hal_def.h"
#include "stm32f7xx_hal_flash.h"

typedef void (*uart_isr_t)(void);
void                 platform_Init(void);
uint32_t             platform_uart_add_weak_cb(uint32_t type,   void (*cb)(UART_HandleTypeDef *UartHandle));
void                 platform_uart_clear_weak_cb(void);
void                 platform_uart_config(uint32_t baudrate);
void                 platform_uart_term(void);
void                 platform_uart_set_isr(uint32_t num, uart_isr_t isr);
UART_HandleTypeDef*  platform_uart_get_console(void);
void                 platform_config_persistent_storage(uint32_t Offset,uint32_t Sector,uint32_t SectorSize);



void      LCD_Swap_buffer_Init(void);
uint32_t  LCD_SwapBuffer(void);
void      LCD_WaitVSync(void);
void      LCD_Vsync_Init(void);


#endif
