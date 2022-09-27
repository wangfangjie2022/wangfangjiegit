#ifndef _SYSTEMTASK_
#define _SYSTEMTASK_
//#include "usually.h"
/*================================================================================*
 *                                   宏定义                                       *
 *================================================================================*/
typedef void(*pTASKFUN)(void);
typedef int32_t(*pINITFUN)(void);
typedef int32_t(*pUNINITFUN)(void);
typedef void (*PSYSTICKFUN)(void);


#define MAX_TASK_COUNT 32 //----最大任务个数--------

#define MAX_SYSTICKFUN_COUNT 2  /* 滴答函数最大任务数 */

/*================================================================================*
 *                                  数据类型                                      *
 *================================================================================*/


/*================================================================================*
 *                               全局变量声明                                     *
 *================================================================================*/
extern pTASKFUN p1MsTask[MAX_TASK_COUNT];      // 紧急任务数组
extern uint8_t nValid1MsTaskCount;
extern uint8_t task1MsEnable[MAX_TASK_COUNT];  // 0:已停止，1:adding, 2:added, 3:stopping, 0:stopped

extern PSYSTICKFUN pSysTickTaskFun[MAX_SYSTICKFUN_COUNT];
extern uint8_t nSysTickTaskFunCount;

/*================================================================================*
 *                               全局函数声明                                     *
 *================================================================================*/
void TaskInit(void);
uint32_t AddTask(pINITFUN pInit, pTASKFUN pFun, pUNINITFUN pUninit);
uint32_t SetTaskToStop(uint32_t nTaskId);
void StopAllExcept(uint32_t nTaskId);
void Timer2Init(void);
void Task1MsTaskInit(void);
int32_t Add1MsTask(pTASKFUN pFun);
int32_t Delet1MsTask(pTASKFUN pFun);
void TaskRun(void);
void SysTickTaskIdle(void);
void SysTickTaskInit(void);
uint8_t AddSysTickTask(PSYSTICKFUN pTickTaskFun);
void Timer2Uninit(void);



#endif
/*================================================================================*
 *                                End of file                                     *
 *================================================================================*/


