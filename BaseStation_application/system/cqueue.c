/**
  ******************************************************************************
  * @file    cqueue.c
  * @version 1.0
  * @date    20171222
  * @brief   C Queue(FIFO)
  ******************************************************************************
  * @attention  COPYRIGHT(C) AUTELROBTICS 2018
  * @队列算法
  * 1.队列初始状态--front=0; rear=0;
    2.入列--rear=(rear+1)%M; buf[rear]=x;
    3.出列--front=(front+1)%M; x=buf[front];
    4.判断队列为空--pqueue->count == 0
    5.判断队列已满--pqueue->count == pqueue->maxsize
    说明：M-队列缓存大小，x-代表任一变量
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
 Function Name: 创建队列函数
 Description  : 在系统中创建一个队列
 Input Params ：@*pqueue--队列结构指针
                @buf[]--队列缓存地址（一般为用户定义的数值首地址）
				@size--队列缓存大小（字节数）
 Output Params: @return--失败返回负数，成功返回0
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
 Function Name: 删除队列函数
 Description  : 将一个队列从系统中删除
 Input Params ：@pqueue--队列结构指针
 Output Params: @return--失败返回负数，成功返回0
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
 Function Name: 入列函数
 Description  : 将一个字节数据插入队列尾部
 Input Params ：@*pqueue--队列结构指针
                @ch--要插入队列的数据
 Output Params: @return--失败返回负数，成功返回插入的字节数（这里为1）
 Note         : None
 Usage        : if(queue_push(&queue, 0xAA) > 0){}
******************************************************************************************/
int32_t queue_push(queue_t *pqueue, const uint8_t ch)
{
	if(pqueue == NULL){
		return -1;
	}
	QUEUE_LOCK(pqueue);
	
	/* 队列是否已满? */
	if(pqueue->count == pqueue->maxsize){
		QUEUE_UNLOCK(pqueue);
		return 0;
	}
	
	/* 将数据插入队列 */
	pqueue->pbuf[pqueue->rear] = ch;
	pqueue->rear = (pqueue->rear + 1) % pqueue->maxsize;

	pqueue->count++;
	
	QUEUE_UNLOCK(pqueue);
	return 1;
}

/******************************************************************************************
 Function Name: 多字节数据入列函数
 Description  : 将一个数组或缓存区中的数据插入队列尾部
 Input Params ：@*pqueue--队列结构指针
                @*buf--数据指针
                @len--期望要插入队列的字节数
 Output Params: @return--失败返回负数，成功返回实际插入队列的字节数
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
	
	/* 队列是否已满? */
	if(pqueue->count == pqueue->maxsize){
		QUEUE_UNLOCK(pqueue);
		return 0;
	}
	
	nlen = pqueue->maxsize - pqueue->count; //空闲个数
	nlen = MIN(nlen, len);
	
	/* 将数据插入队列 */
	for(i=0; i<nlen; i++){
		pqueue->pbuf[pqueue->rear] = buf[i];
		pqueue->rear = (pqueue->rear + 1) % pqueue->maxsize;

	}
	pqueue->count += nlen;
	
	QUEUE_UNLOCK(pqueue);
	return (int32_t)nlen; //返回实际插入队列中的个数
}

/******************************************************************************************
 Function Name: 出列函数
 Description  : 从队列头部取出一个字节数据
 Input Params ：@*pqueue--队列结构指针
                @*ch--保存数据的指针
 Output Params: @return--失败返回负数，成功返回实际读取的字节数（这里为1）
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
	
	/* 队列是否为空? */
	if(pqueue->count == 0){
		QUEUE_UNLOCK(pqueue);
		return 0;
	}
	
	/* 从队列读取数据 */
	*ch = pqueue->pbuf[pqueue->front];
	pqueue->front = (pqueue->front + 1) % pqueue->maxsize;
	pqueue->count--;
	
	QUEUE_UNLOCK(pqueue);
	return 1;
}

/******************************************************************************************
 Function Name: 获取队列内元素，并不操作队列
 Description  : 从队列头部取出一个字节数据(注意，是从头部向前取，出队是从头部向后取，方向相反)
 Input Params ：@*pqueue--队列结构指针
								@pos--距队列头部的相对位置
                @*ch--保存数据的指针
 Output Params: @return--失败返回负数
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
	
	/* 队列是否为空? */
	if(pqueue->count == 0){
		QUEUE_UNLOCK(pqueue);
		return 0;
	}
	
	/* 从队列读取数据 */
	if(pqueue->front >= pos )
		*ch = pqueue->pbuf[pqueue->front-pos];
	else 
		*ch = pqueue->pbuf[pqueue->maxsize+pqueue->front-pos];;
	
	QUEUE_UNLOCK(pqueue);
	return 1;
}

/******************************************************************************************
 Function Name: 多字节数据出列函数
 Description  : 从队列的头部读取多个字节数据
 Input Params ：@*pqueue--队列结构指针
                @*buf--保存数据的指针
                @len--期望读取的字节数
 Output Params: @return--失败返回负数，成功返回实际读取的字节数
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
	
	/* 队列是否为空? */
	if(pqueue->count == 0){
		QUEUE_UNLOCK(pqueue);
		return 0;
	}
	nlen = MIN(len, pqueue->count);  //实际可以读取的字节数
	
	/* 从队列读取数据 */
	for(i=0; i<nlen; i++){
		buf[i] = pqueue->pbuf[pqueue->front];
		pqueue->front = (pqueue->front + 1) % pqueue->maxsize;
	}
	pqueue->count -= nlen;
	
	QUEUE_UNLOCK(pqueue);
	return (int32_t)nlen;
}

/******************************************************************************************
 Function Name: 判断队列是否为空函数
 Description  : 用于判断指定队列是否为空
 Input Params ：@*pqueue--队列结构指针
 Output Params: @return--传入参数非法返回负数，队列为空返回1，队列不为空返回0
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
 Function Name: 判断队列是否为满函数
 Description  : 判断指定队列是否已满
 Input Params ：@*pqueue--队列结构指针
 Output Params: @return--传入参数非法返回负数，队列已满返回1，队列未满返回0
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
 Function Name: 获取队列大小（已入列数目）函数
 Description  : 获取队列当前已插入的数据个数
 Input Params ：@*pqueue--队列结构指针
 Output Params: @return--传入参数非法返回负数，否则返回当前队列有效数据个数
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
 Function Name: 清除队列内容函数
 Description  : 将队列中是所有数据清除
 Input Params ：@*pqueue--队列结构指针
 Output Params: @return--成功返回0，失败返回-1
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
