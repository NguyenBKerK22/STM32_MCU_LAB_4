/*
 * scheduler.c
 *
 *  Created on: Nov 29, 2024
 *      Author: ADMIN
 */

#include "scheduler.h"
struct sTask SCH_tasks_G[SCH_MAX_TASKS];
void SCH_Update(void){
	unsigned char Index;
	 // NOTE: calculations are in *TICKS* (not milliseconds)
	 for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
	 // Check if there is a task at this location
		 if (SCH_tasks_G[Index ]. pTask) {
			 if (SCH_tasks_G[Index ]. Delay == 0){
				 SCH_tasks_G[Index ].RunMe += 1;
				 SCH_tasks_G[Index ]. Delay = SCH_tasks_G[Index ].Period ;
			 }
			 else{
				 SCH_tasks_G[Index ]. Delay-=1;
			 }

		 }
	 }
	 // The task is due to run
	 // Inc. the ’RunMe’ flag
}
void SCH_Delete_Task(uint32_t taskID){
	 if(SCH_tasks_G[taskID]. pTask == 0) {
		 return;
	 }
	 SCH_tasks_G[taskID]. pTask = 0;
	 SCH_tasks_G[taskID]. Delay = 0;
	 SCH_tasks_G[taskID]. Period = 0;
	 SCH_tasks_G[taskID]. RunMe = 0;
}
void SCH_Add_Task(void (*pFunction)() , unsigned int DELAY, unsigned int PERIOD){
	unsigned char Index = 0;
	// First find a gap in the array ( if there is one)
	while ((SCH_tasks_G[Index].pTask != 0) && (Index <SCH_MAX_TASKS))
	 {
		Index++;
	 }
	 // Havewe reached the end of the list?
	 if (Index == SCH_MAX_TASKS){
		 // Task list is full
		 // Set the global error variable
		 // Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
		 // Also return an error code
		 return;
	 }
	  // If we’re here, there is a space in the task array
	 SCH_tasks_G[Index].pTask = pFunction;
	 SCH_tasks_G[Index].Delay =DELAY;
	 SCH_tasks_G[Index].Period = PERIOD;
	 SCH_tasks_G[Index].RunMe = 0;
	 // return position of task (to allow later deletion)
	 return;
}
void SCH_Dispatch_Tasks(void){
	unsigned char Index;
	 // Dispatches (runs) the next task ( if one is ready)
	 for (Index = 0; Index < SCH_MAX_TASKS; Index++){
		 if (SCH_tasks_G[Index].RunMe > 0) {
		 	 (*SCH_tasks_G[Index].pTask)() ;
		 	 SCH_tasks_G[Index].RunMe -= 1; // Reset / reduce RunMe
		 	 // Periodic tasks will automatically run again
		 	 // − if this is a ’one shot’ task , remove it from the
		 	 if(SCH_tasks_G[Index]. Period == 0){
		 		 SCH_Delete_Task(Index) ;
		 	 }
	 	 }
	 }
}
void SCH_Init(){
	 unsigned char Index ;
	 for(Index=0; Index < SCH_MAX_TASKS; Index++) {
		 SCH_tasks_G[Index].pTask = 0;
		 SCH_tasks_G[Index].Delay = 0;
		 SCH_tasks_G[Index].Period = 0;
		 SCH_tasks_G[Index].RunMe = 0;
	 }
}
