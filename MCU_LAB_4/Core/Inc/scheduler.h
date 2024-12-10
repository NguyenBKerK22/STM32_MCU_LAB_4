/*
 * scheduler.h
 *
 *  Created on: Nov 29, 2024
 *      Author: ADMIN
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include "stdint.h"
#include "timer.h"
struct sTask {
	 // Pointer to the task (must be a ’void (void) ’ function)
	 void ( * pTask)(void) ;
	 // Delay (ticks ) until the function will (next) be run
	 uint32_t Delay;
	 // Interval ( ticks ) between subsequent runs.
	 uint32_t Period ;
	 // Incremented (by scheduler) when task is due to execute
	 uint8_t RunMe;
	 //This is a hint to solve the question below.
	 uint32_t TaskID;
};
#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0

extern struct sTask SCH_tasks_G[SCH_MAX_TASKS];

void SCH_Init();
void SCH_Add_Task(void (*pFunction)() , unsigned int DELAY, unsigned int PERIOD);
void SCH_Dispatch_Tasks(void);
void SCH_Delete_Task(uint32_t taskID);
void SCH_Update();
#endif /* INC_SCHEDULER_H_ */
