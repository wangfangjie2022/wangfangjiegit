/**
  ******************************************************************************
  * @file    cqueue.h
  * @version 1.0
  * @date    20171222
  * @brief   C Queue(FIFO)
  ******************************************************************************
  * @attention  COPYRIGHT(C) AUTELROBTICS 2018
  ******************************************************************************
  */

#ifndef __CQUEUE_H__
#define __CQUEUE_H__

#ifdef __cplusplus
extern "C" {
#endif

#define CFG_OS_MULTITASK_EN	  0

#if CFG_OS_MULTITASK_EN
 #include <ucos_ii.h>
#endif

#include "stdint.h"
  
/* 队列（FIFO）数据结构 */
typedef struct queue{
  uint32_t  front;    /* 队列头部指针 */
  uint32_t  rear;     /* 队列尾部指针 */
  uint8_t   *pbuf;    /* 队列缓存区指针 */
  uint32_t  maxsize;  /* 队列缓存区大小 */
  uint32_t  count;    /* 队列已入列计数 */
#if CFG_OS_MULTITASK_EN
  OS_EVENT  *pmutex;  /* 队列互斥信号量 */
#endif
}queue_t;



/* API函数 */
extern int queue_create(queue_t *pqueue, uint8_t buf[], uint32_t size);
extern int queue_destroy(queue_t *pqueue);
extern int queue_push(queue_t *pqueue, const uint8_t ch);
extern int queue_push_buf(queue_t *pqueue, const uint8_t *buf, uint32_t len);
extern int queue_pop(queue_t *pqueue, uint8_t *ch);
extern int queue_pop_buf(queue_t *pqueue, uint8_t *buf, uint32_t len);
extern int queue_empty(queue_t *pqueue);
extern int queue_full(queue_t *pqueue);
extern int queue_size(queue_t *pqueue);
extern int queue_clear(queue_t *pqueue);
extern int32_t queue_get_element(queue_t *pqueue, uint8_t pos, uint8_t *ch);

#ifdef __cplusplus
}
#endif

#endif /* __CQUEUE_H__ */
/*--------------------------------- The End ----------------------------------------------*/
