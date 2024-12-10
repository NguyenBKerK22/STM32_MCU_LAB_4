/*
 * system.c
 *
 *  Created on: Nov 29, 2024
 *      Author: ADMIN
 */


#include "system.h"
void  System_Initialization(){
	SCH_Init();
	HAL_TIM_Base_Start_IT(&htim2);
}
