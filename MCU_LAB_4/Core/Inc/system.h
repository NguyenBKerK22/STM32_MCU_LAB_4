/*
 * system.h
 *
 *  Created on: Nov 29, 2024
 *      Author: ADMIN
 */

#ifndef INC_SYSTEM_H_
#define INC_SYSTEM_H_

#include "stm32f1xx_hal.h"
#include "scheduler.h"

extern TIM_HandleTypeDef htim2;
void  System_Initialization();
#endif /* INC_SYSTEM_H_ */
