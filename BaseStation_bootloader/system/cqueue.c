/**
  ******************************************************************************
  * @file    cqueue.c
  * @version 1.0
  * @date    20171222
  * @brief   C Queue(FIFO)
  ******************************************************************************
  * @attention  COPYRIGHT(C) AUTELROBTICS 2018
  * @�����㷨
  * 1.���г�ʼ״̬--front=0; rear=0;
    2.����--rear=(rear+1)%M; buf[rear]=x;
    3.����--front=(front+1)%M; x=buf[front];
    4.�ж϶���Ϊ��--pqueue->count == 0
    5.�ж϶�������--pqueue->count == pqueue->maxsize
    ˵����M-���л����С��x-������һ����
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------------------*/
#include "cqueue.h"
//#include <intrinsics.h>

/* Private typedef -----------------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------------------*/

#if CFG_OS_MULTITASK_EN
    #define QUEUE_CREATE_LOCK(p)    queue_create_lock(&(p->pmutex))
    #define QUEUE_RELEASE_LOCK(p)   queue_release_lock(p->pmutex)
    #define QUEUE_LOCK(p)           queue_lock(p->pmutex)
    #define QUEUE_UNLOCK(p)         queue_unlock(p->pmutex)
#else
    #define QUEUE_CREATE_LOCK(p) 	
    #define QUEUE_RELEASE_LOCK(p) 
		#define QUEUE_LOCK(p)          
    #define QUEUE_UNLOCK(p)   
    //#define QUEUE_LOCK(p)             taskENTER_CRITICAL_FROM_ISR()
   // #define QUEUE_UNLOCK(p)           taskEXIT_CRITICAL_FROM_ISR(p)
	//	#define QUEUE_LOCK(p)           taskENTER_CRITICAL()//__disable_interrupt() //NVIC_DisableIRQ(DMA1_Channel2_3_IRQn); NVIC_DisableIRQ(USART3_4_IRQn)
   // #define QUEUE_UNLOCK(p)         taskEXIT_CRITICAL()//__enable_interrupt()  //NVIC_EnableIRQ(DMA1_Channel2_3_IRQn);  NVIC_EnableIRQ(USART3_4_IRQn)
#endif /*CFG_OS_MULTITASK_EN*/

#ifndef NULL
#define NULL (void *)0
#endif

#ifndef MAX
#define MAX(a,b) (a>b ? a : b)
#endif

#ifndef MIN
#define MIN(a,b) (a<b ? a : b)
#endif

/* Private variables ---------------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------------------*/
/* Private functions ---------------------------------------------------------------------*/
#if CFG_OS_MULTITASK_EN
static int32_t queue_create_lock(OS_EVENT **pmutex)
{
	INT8U err;
	*pmutex = OSMutexCreate(5, &err);
	return err==OS_ERR_NONE ? 0 : -1;
}

static int32_t queue_release_lock(OS_EVENT *pmutex)
{
	INT8U err;
	OSMutexDel(pmutex, OS_DEL_ALWAYS, &err);
	return err==OS_ERR_NONE ? 0 : -1;
}

static int32_t queue_lock(OS_EVENT *pmutex)
{
	INT8U err;
	OSMutexPend(pmutex, 0, &err);
	return err==OS_ERR_NONE ? 0 : -1;
}

static int32_t queue_unlock(OS_EVENT *pmutex)
{
	INT8U err;
	err = OSMutexPost(pmutex);
	return err==OS_ERR_NONE ? 0 : -1;
}
#endif


/* Public functions ---------------------------------------------------------------------*/

/******************************************************************************************
 Function Name: �������к���
 Description  : ��ϵͳ�д���һ������
 Input Params ��@*pqueue--���нṹָ��
                @buf[]--���л����ַ��һ��Ϊ�û��������ֵ�׵�ַ��
				@size--���л����С���ֽ�����
 Output Params: @return--ʧ�ܷ��ظ������ɹ�����0
 Note         : None
 Usage        : queue_t queue;
                uint8_t buf[QUEUE_MAX_SIZE];
                ret = queue_create(&queue, buf, QUEUE_MAX_SIZE);
******************************************************************************************/
int32_t queue_create(queue_t *pqueue, uint8_t buf[], uint32_t size)
{
	uint32_t i;
	if(pqueue==NULL || buf==NULL || size==0){
		return -1;
	}
	pqueue->front = 0;
	pqueue->rear = 0;
	pqueue->pbuf = buf;
	pqueue->maxsize = size;
	pqueue->count = 0;
	for(i=0; i<size; i++){
		pqueue->pbuf[i] = 0;
	}
	QUEUE_CREATE_LOCK(pqueue);
	return 0;
}

/******************************************************************************************
 Function Name: ɾ�����к���
 Description  : ��һ�����д�ϵͳ��ɾ��
 Input Params ��@pqueue--���нṹָ��
 Output Params: @return--ʧ�ܷ��ظ������ɹ�����0
 Note         : None
 Usage        : ret = queue_destroy(&queue);
******************************************************************************************/
int32_t queue_destroy(queue_t *pqueue)
{
	if(pqueue == NULL){
		return -1;
	}
	pqueue->front = 0;
	pqueue->rear = 0;
	pqueue->pbuf = NULL;
	pqueue->maxsize = 0;
	pqueue->count = 0;
	QUEUE_RELEASE_LOCK(pqueue);
	return 0;
}

/******************************************************************************************
 Function Name: ���к���
 Description  : ��һ���ֽ����ݲ������β��
 Input Params ��@*pqueue--���нṹָ��
                @ch--Ҫ������е�����
 Output Params: @return--ʧ�ܷ��ظ������ɹ����ز�����ֽ���������Ϊ1��
 Note         : None
 Usage        : if(queue_push(&queue, 0xAA) > 0){}
******************************************************************************************/
int32_t queue_push(queue_t *pqueue, const uint8_t ch)
{
	if(pqueue == NULL){
		return -1;
	}
	QUEUE_LOCK(pqueue);
	
	/* �����Ƿ�����? */
	if(pqueue->count == pqueue->maxsize){
		QUEUE_UNLOCK(pqueue);
		return 0;
	}
	
	/* �����ݲ������ */
	pqueue->pbuf[pqueue->rear] = ch;
	pqueue->rear = (pqueue->rear + 1) % pqueue->maxsize;

	pqueue->count++;
	
	QUEUE_UNLOCK(pqueue);
	return 1;
}

/******************************************************************************************
 Function Name: ���ֽ��������к���
 Description  : ��һ������򻺴����е����ݲ������β��
 Input Params ��@*pqueue--���нṹָ��
                @*buf--����ָ��
                @len--����Ҫ������е��ֽ���
 Output Params: @return--ʧ�ܷ��ظ������ɹ�����ʵ�ʲ�����е��ֽ���
 Note         : None
 Usage        : if((ret = queue_push_buf(&queue, buf, SIZE)) > 0){}
******************************************************************************************/
int32_t queue_push_buf(queue_t *pqueue, const uint8_t *buf, uint32_t len)
{
	uint32_t i,nlen;
	if(pqueue==NULL || buf==NULL || len==0){
		return -1;
	}
	QUEUE_LOCK(pqueue);
	
	/* �����Ƿ�����? */
	if(pqueue->count == pqueue->maxsize){
		QUEUE_UNLOCK(pqueue);
		return 0;
	}
	
	nlen = pqueue->maxsize - pqueue->count; //���и���
	nlen = MIN(nlen, len);
	
	/* �����ݲ������ */
	for(i=0; i<nlen; i++){
		pqueue->pbuf[pqueue->rear] = buf[i];
		pqueue->rear = (pqueue->rear + 1) % pqueue->maxsize;

	}
	pqueue->count += nlen;
	
	QUEUE_UNLOCK(pqueue);
	return (int32_t)nlen; //����ʵ�ʲ�������еĸ���
}

/******************************************************************************************
 Function Name: ���к���
 Description  : �Ӷ���ͷ��ȡ��һ���ֽ�����
 Input Params ��@*pqueue--���нṹָ��
                @*ch--�������ݵ�ָ��
 Output Params: @return--ʧ�ܷ��ظ������ɹ�����ʵ�ʶ�ȡ���ֽ���������Ϊ1��
 Note         : None
 Usage        : uint8_t ch;
                if(queue_pop(&queue, &ch) > 0){}
******************************************************************************************/
int32_t queue_pop(queue_t *pqueue, uint8_t *ch)
{
	if(pqueue==NULL || ch==NULL){
		return -1;
	}
	QUEUE_LOCK(pqueue);
	
	/* �����Ƿ�Ϊ��? */
	if(pqueue->count == 0){
		QUEUE_UNLOCK(pqueue);
		return 0;
	}
	
	/* �Ӷ��ж�ȡ���� */
	*ch = pqueue->pbuf[pqueue->front];
	pqueue->front = (pqueue->front + 1) % pqueue->maxsize;
	pqueue->count--;
	
	QUEUE_UNLOCK(pqueue);
	return 1;
}

/******************************************************************************************
 Function Name: ��ȡ������Ԫ�أ�������������
 Description  : �Ӷ���ͷ��ȡ��һ���ֽ�����(ע�⣬�Ǵ�ͷ����ǰȡ�������Ǵ�ͷ�����ȡ�������෴)
 Input Params ��@*pqueue--���нṹָ��
								@pos--�����ͷ�������λ��
                @*ch--�������ݵ�ָ��
 Output Params: @return--ʧ�ܷ��ظ���
 Note         : None
 Usage        : uint8_t ch;
                if(queue_pop(&queue, &ch) > 0){}
******************************************************************************************/
int32_t queue_get_element(queue_t *pqueue, uint8_t pos, uint8_t *ch)
{
	if(pqueue==NULL || ch==NULL){
		return -1;
	}
	QUEUE_LOCK(pqueue);
	
	/* �����Ƿ�Ϊ��? */
	if(pqueue->count == 0){
		QUEUE_UNLOCK(pqueue);
		return 0;
	}
	
	/* �Ӷ��ж�ȡ���� */
	if(pqueue->front >= pos )
		*ch = pqueue->pbuf[pqueue->front-pos];
	else 
		*ch = pqueue->pbuf[pqueue->maxsize+pqueue->front-pos];;
	
	QUEUE_UNLOCK(pqueue);
	return 1;
}

/******************************************************************************************
 Function Name: ���ֽ����ݳ��к���
 Description  : �Ӷ��е�ͷ����ȡ����ֽ�����
 Input Params ��@*pqueue--���нṹָ��
                @*buf--�������ݵ�ָ��
                @len--������ȡ���ֽ���
 Output Params: @return--ʧ�ܷ��ظ������ɹ�����ʵ�ʶ�ȡ���ֽ���
 Note         : None
 Usage        : uint8_t buf[SIZE];
                if((ret = queue_pop_buf(&queue, buf, SIZE)) > 0){}
******************************************************************************************/
int32_t queue_pop_buf(queue_t *pqueue, uint8_t *buf, uint32_t len)
{
	uint32_t i,nlen;
	if(pqueue==NULL || buf==NULL || len==0){
		return -1;
	}
	
	QUEUE_LOCK(pqueue);
	
	/* �����Ƿ�Ϊ��? */
	if(pqueue->count == 0){
		QUEUE_UNLOCK(pqueue);
		return 0;
	}
	nlen = MIN(len, pqueue->count);  //ʵ�ʿ��Զ�ȡ���ֽ���
	
	/* �Ӷ��ж�ȡ���� */
	for(i=0; i<nlen; i++){
		buf[i] = pqueue->pbuf[pqueue->front];
		pqueue->front = (pqueue->front + 1) % pqueue->maxsize;
	}
	pqueue->count -= nlen;
	
	QUEUE_UNLOCK(pqueue);
	return (int32_t)nlen;
}

/******************************************************************************************
 Function Name: �ж϶����Ƿ�Ϊ�պ���
 Description  : �����ж�ָ�������Ƿ�Ϊ��
 Input Params ��@*pqueue--���нṹָ��
 Output Params: @return--��������Ƿ����ظ���������Ϊ�շ���1�����в�Ϊ�շ���0
 Note         : None
 Usage        : if(queue_empty(&queue) > 0){}
******************************************************************************************/
int32_t queue_empty(queue_t *pqueue)
{
	int32_t ret = 0;
	if(pqueue == NULL){
		return -1;
	}
	QUEUE_LOCK(pqueue);
	if( pqueue->count == 0)
		ret = 1;
	//ret = (pqueue->count == 0) ? 1 : 0;
	QUEUE_UNLOCK(pqueue);
	return ret;
}

/******************************************************************************************
 Function Name: �ж϶����Ƿ�Ϊ������
 Description  : �ж�ָ�������Ƿ�����
 Input Params ��@*pqueue--���нṹָ��
 Output Params: @return--��������Ƿ����ظ�����������������1������δ������0
 Note         : None
 Usage        : if(queue_full(&queue) > 0){}
******************************************************************************************/
int32_t queue_full(queue_t *pqueue)
{
	int32_t ret;
	if(pqueue == NULL){
		return -1;
	}
	QUEUE_LOCK(pqueue);
	ret = (pqueue->count == pqueue->maxsize) ? 1 : 0;
	QUEUE_UNLOCK(pqueue);
	return ret;
}

/******************************************************************************************
 Function Name: ��ȡ���д�С����������Ŀ������
 Description  : ��ȡ���е�ǰ�Ѳ�������ݸ���
 Input Params ��@*pqueue--���нṹָ��
 Output Params: @return--��������Ƿ����ظ��������򷵻ص�ǰ������Ч���ݸ���
 Note         : None
 Usage        : int32_t count = queue_size(&queue);
******************************************************************************************/
int32_t queue_size(queue_t *pqueue)
{
	int32_t count;
	if(pqueue == NULL){
		return -1;
	}
	QUEUE_LOCK(pqueue);
	count = pqueue->count;
	QUEUE_UNLOCK(pqueue);
	return count;
}

/******************************************************************************************
 Function Name: ����������ݺ���
 Description  : ���������������������
 Input Params ��@*pqueue--���нṹָ��
 Output Params: @return--�ɹ�����0��ʧ�ܷ���-1
 Note         : None
 Usage        : int32_t count = queue_size(&queue);
******************************************************************************************/
int32_t queue_clear(queue_t *pqueue)
{
	uint32_t i;

	if(pqueue == NULL){
		return -1;
	}

	QUEUE_LOCK(pqueue);
	pqueue->front = 0;
	pqueue->rear = 0;
	pqueue->count = 0;
	for(i=0; i<pqueue->maxsize; i++){
		pqueue->pbuf[i] = 0;
	}
	QUEUE_UNLOCK(pqueue);

	return 0;
}


/*--------------------------------- The End ----------------------------------------------*/
