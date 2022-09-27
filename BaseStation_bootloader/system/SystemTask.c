/*================================================================================*
 * Copyright(c) 2015-2017, Autel Intelligent Technology Corp., Ltd
 * All rights reserved
 *================================================================================*
 *
 * 文件名称: SystemTask.c
 *
 * 文件描述: 系统任务
 * 作    者:
 * 创建时间:
 * 文件版本:
 * 修改历史:
 *
 *================================================================================*/

/*================================================================================*
 *                                 头文件包含                                     *
 *================================================================================*/
#include "Sys_cfg.h"
#include "includes.h"

/*================================================================================*
 *                                   宏定义                                       *
 *================================================================================*/


/*================================================================================*
 *                                数据结构定义                                    *
 *================================================================================*/
/*
结构体说明：TASKOBJ 任务结构体
参数说明：          任务ID
                    任务初始化函数指针
                    任务运行函数指针
                    卸载任务函数指针
*/
typedef struct
{
        uint32_t nTaskId;
        pINITFUN pInit;     //初始化任务，只执行一次
        pTASKFUN pTaskFun;  //任务函数
        pUNINITFUN pUninit;
} TASKOBJ;

/*
枚举说明：TASKSTAT 任务状态枚举
参数说明：任务已经停止
					任务处于加载中
					任务已经加载
					任务处于停止中
*/
typedef enum
{
		eStopped,
		eAdding,
		eAdded,
		eStopping,
} TASKSTAT;


/*================================================================================*
 *                                全局变量定义                                    *
 *================================================================================*/
/*普通任务*/
static TASKSTAT taskStats[MAX_TASK_COUNT]; // 0:已停止，1:adding, 2:added, 3:stopping, 0:stopped
static TASKOBJ taskObj[MAX_TASK_COUNT];    //----全局数组，所有任务都出于这里--------
volatile uint8_t nValidTaskCount;   // 有效的任务数

///*紧急任务*/
//pTASKFUN p1MsTask[MAX_TASK_COUNT];      // 紧急任务数组
//uint8_t task1MsEnable[MAX_TASK_COUNT];  // 0:已停止，1:adding, 2:added, 3:stopping, 0:stopped
//uint8_t nValid1MsTaskCount;             // 有效紧急的任务数

///* 系统滴答任务 */
//PSYSTICKFUN pSysTickTaskFun[MAX_SYSTICKFUN_COUNT];
//uint8_t nSysTickTaskFunCount;

/*================================================================================*
 *                               局部变量定义                                     *
 *================================================================================*/


/*================================================================================*
 *                                 函数声明                                       *
 *================================================================================*/

void Test_Task_state(void)
{
	int i = 0;
	for(i=0;i<MAX_TASK_COUNT;i++)
	{
		//printf("task i = %d   state:%x\r\n",i,taskStats[i]);
	}
}


/*================================================================================*
 *                                 函数原型                                       *
 *================================================================================*/
/*================================================================================*
 * 函数名称:    void TaskInit(void)
 * 功能描述:
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:    任务初始化
 * 创建历史:
 *
 *================================================================================*/
void TaskInit(void)
{
    nValidTaskCount = 0;
    memset(taskStats,0,sizeof(taskStats));
//    Task1MsTaskInit();
}

/*================================================================================*
 * 函数名称:    uint32_t AddTask(pINITFUN pInit, pTASKFUN pFun, pUNINITFUN pUninit)
 * 功能描述:
 * 作    者:
 * 输入参数:    任务初始化函数，任务运行函数，任务卸载函数
 * 输出参数:    添加成功 返回任务ID   添加失败 返回0
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *
 *================================================================================*/
uint32_t AddTask(pINITFUN pInit, pTASKFUN pFun, pUNINITFUN pUninit)
{
		static uint32_t nId=0;
		uint8_t i = 0;
		for(i=0; i<nValidTaskCount; i++)
		{
				if(taskObj[i].pTaskFun == pFun && taskObj[i].pInit == pInit)
				{
						return 0;
				}
		}

		if (nValidTaskCount < MAX_TASK_COUNT)
		{
			taskObj[nValidTaskCount].nTaskId = (++nId);
			taskObj[nValidTaskCount].pInit = pInit;
			taskObj[nValidTaskCount].pTaskFun = pFun;
			taskObj[nValidTaskCount].pUninit = pUninit;

			taskStats[nValidTaskCount] = eAdding;
			nValidTaskCount++;
			return nId;
		}
		return 0;
}

/*================================================================================*
 * 函数名称:    uint32_t SetTaskToStop(uint32_t nTaskId)
 * 功能描述:    挂起任务
 * 作    者:
 * 输入参数:    挂起任务ID
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *
 *================================================================================*/
uint32_t SetTaskToStop(uint32_t nTaskId)
{
    uint8_t i;

    for (i=0; i<nValidTaskCount; i++)
    {
        if (nTaskId == taskObj[i].nTaskId)
        {
            if (taskStats[i] != eStopped)
            {
                    taskStats[i] = eStopping;
            }
            break;
        }
    }
    return 0;
}


/*================================================================================*
 * 函数名称:    void StopAllExcept(uint32_t nTaskId)
 * 功能描述:    挂起本ID之外所有的任务
 * 作    者:
 * 输入参数:    任务ID
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *
 *================================================================================*/
void StopAllExcept(uint32_t nTaskId)
{
	uint8_t i;

	for (i=0; i<nValidTaskCount; i++)
	{
		if (nTaskId != taskObj[i].nTaskId)
		{
			taskStats[i] = eStopping;
		}
	}
}

/*================================================================================*
 * 函数名称:    void TaskRun(void)
 * 功能描述:    普通任务运行
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:    主函数中运行
 * 创建历史:
 *
 *================================================================================*/
void TaskRun(void)
{
  uint8_t i, nCount;

  for (i=0; i<nValidTaskCount;)
  {
    //--------任务状态更新，增加或者删除任务--------
    if (taskStats[i] == eAdding)
    {// init
      taskObj[i].pInit();
      taskStats[i] = eAdded;
    }
    else if (taskStats[i] == eStopping)
    {
      // uinit  挂起任务
      taskObj[i].pUninit();
      taskStats[i] = eStopped;

      // delet task 卸载任务
      nCount = nValidTaskCount-i-1;
      memcpy(taskStats+i, taskStats+i+1, sizeof(taskStats[0])*nCount);
      memcpy(taskObj+i, taskObj+i+1, sizeof(taskObj[0])*nCount);
      nValidTaskCount--;
      continue;
    }
    //--------运行任务----------------

    taskObj[i].pTaskFun();

    i++ ;
  }

}

/*================================================================================*
 *                                End of file                                     *
 *================================================================================*/



