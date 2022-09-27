/*================================================================================*
 * Copyright(c) 2015-2017, Autel Intelligent Technology Corp., Ltd
 * All rights reserved
 *================================================================================*
 *
 * �ļ�����: SystemTask.c
 *
 * �ļ�����: ϵͳ����
 * ��    ��:
 * ����ʱ��:
 * �ļ��汾:
 * �޸���ʷ:
 *
 *================================================================================*/

/*================================================================================*
 *                                 ͷ�ļ�����                                     *
 *================================================================================*/
#include "Sys_cfg.h"
#include "includes.h"

/*================================================================================*
 *                                   �궨��                                       *
 *================================================================================*/


/*================================================================================*
 *                                ���ݽṹ����                                    *
 *================================================================================*/
/*
�ṹ��˵����TASKOBJ ����ṹ��
����˵����          ����ID
                    �����ʼ������ָ��
                    �������к���ָ��
                    ж��������ָ��
*/
typedef struct
{
        uint32_t nTaskId;
        pINITFUN pInit;     //��ʼ������ִֻ��һ��
        pTASKFUN pTaskFun;  //������
        pUNINITFUN pUninit;
} TASKOBJ;

/*
ö��˵����TASKSTAT ����״̬ö��
����˵���������Ѿ�ֹͣ
					�����ڼ�����
					�����Ѿ�����
					������ֹͣ��
*/
typedef enum
{
		eStopped,
		eAdding,
		eAdded,
		eStopping,
} TASKSTAT;


/*================================================================================*
 *                                ȫ�ֱ�������                                    *
 *================================================================================*/
/*��ͨ����*/
static TASKSTAT taskStats[MAX_TASK_COUNT]; // 0:��ֹͣ��1:adding, 2:added, 3:stopping, 0:stopped
static TASKOBJ taskObj[MAX_TASK_COUNT];    //----ȫ�����飬�������񶼳�������--------
volatile uint8_t nValidTaskCount;   // ��Ч��������

///*��������*/
//pTASKFUN p1MsTask[MAX_TASK_COUNT];      // ������������
//uint8_t task1MsEnable[MAX_TASK_COUNT];  // 0:��ֹͣ��1:adding, 2:added, 3:stopping, 0:stopped
//uint8_t nValid1MsTaskCount;             // ��Ч������������

///* ϵͳ�δ����� */
//PSYSTICKFUN pSysTickTaskFun[MAX_SYSTICKFUN_COUNT];
//uint8_t nSysTickTaskFunCount;

/*================================================================================*
 *                               �ֲ���������                                     *
 *================================================================================*/


/*================================================================================*
 *                                 ��������                                       *
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
 *                                 ����ԭ��                                       *
 *================================================================================*/
/*================================================================================*
 * ��������:    void TaskInit(void)
 * ��������:
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:    �����ʼ��
 * ������ʷ:
 *
 *================================================================================*/
void TaskInit(void)
{
    nValidTaskCount = 0;
    memset(taskStats,0,sizeof(taskStats));
//    Task1MsTaskInit();
}

/*================================================================================*
 * ��������:    uint32_t AddTask(pINITFUN pInit, pTASKFUN pFun, pUNINITFUN pUninit)
 * ��������:
 * ��    ��:
 * �������:    �����ʼ���������������к���������ж�غ���
 * �������:    ��ӳɹ� ��������ID   ���ʧ�� ����0
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
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
 * ��������:    uint32_t SetTaskToStop(uint32_t nTaskId)
 * ��������:    ��������
 * ��    ��:
 * �������:    ��������ID
 * �������:
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
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
 * ��������:    void StopAllExcept(uint32_t nTaskId)
 * ��������:    ����ID֮�����е�����
 * ��    ��:
 * �������:    ����ID
 * �������:
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
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
 * ��������:    void TaskRun(void)
 * ��������:    ��ͨ��������
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:    ������������
 * ������ʷ:
 *
 *================================================================================*/
void TaskRun(void)
{
  uint8_t i, nCount;

  for (i=0; i<nValidTaskCount;)
  {
    //--------����״̬���£����ӻ���ɾ������--------
    if (taskStats[i] == eAdding)
    {// init
      taskObj[i].pInit();
      taskStats[i] = eAdded;
    }
    else if (taskStats[i] == eStopping)
    {
      // uinit  ��������
      taskObj[i].pUninit();
      taskStats[i] = eStopped;

      // delet task ж������
      nCount = nValidTaskCount-i-1;
      memcpy(taskStats+i, taskStats+i+1, sizeof(taskStats[0])*nCount);
      memcpy(taskObj+i, taskObj+i+1, sizeof(taskObj[0])*nCount);
      nValidTaskCount--;
      continue;
    }
    //--------��������----------------

    taskObj[i].pTaskFun();

    i++ ;
  }

}

/*================================================================================*
 *                                End of file                                     *
 *================================================================================*/



