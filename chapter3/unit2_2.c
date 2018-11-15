//
// Created by hanqing zhu on 2018/11/11.
//
#include <stdlib.h>
#include "unit2_2.h"

//通常约定在入队时少用一个数据元素空间
//以队尾指针加1等于队首指针判断队满

/*------------------------------------------------------
 * 函数名：initQueue
 *
 * 功  能：初始化队列
 *
 * 描  述：构造一个空队列q。将front和rear指针均设置成初始状态即0值。
 *
 * 参  数：q，队列指针
 *
 * 返回值：无
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void initQueue(SqQueue **q){
    *q=(SqQueue *)malloc(sizeof(SqQueue));
    (*q)->front=(*q)->rear=0;
}

/*------------------------------------------------------
 * 函数名：clearQueue
 *
 * 功  能：销毁队列
 *
 * 描  述：释放队列q占用的存储空间
 *
 * 参  数：q，队列指针
 *
 * 返回值：无
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void clearQueue(SqQueue **q){
    free(*q);
}

/*------------------------------------------------------
 * 函数名：queueEmpty
 *
 * 功  能：判断队列是否为空
 *
 * 描  述：若队列q满足q->front==q->rear条件，则返回1；否则返回0。
 *
 * 参  数：q，队列指针
 *
 * 返回值：0(非空)或1(空)
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int queueEmpty(SqQueue *q){
    return(q->front==q->rear);
}

/*------------------------------------------------------
 * 函数名：enQueue
 *
 * 功  能：入队列
 *
 * 描  述：在队列不满的条件下，先将队尾指针rear循环增1，然后将元素添加到该位置
 *
 * 参  数：q，队列指针；
 *        e，待入队元素值。
 *
 * 返回值：0(队满)或1(入队成功)
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int enQueue(SqQueue **q,ElemType e){
    //队满
    if (((*q)->rear+1)%MaxSize==(*q)->front){
        return 0;
    }
    //入队列
    (*q)->rear=((*q)->rear+1)%MaxSize;
    (*q)->data[(*q)->rear]=e;
    return 1;
}

/*------------------------------------------------------
 * 函数名：deQueue
 *
 * 功  能：出队列
 *
 * 描  述：在队列不为空的条件下，将队首指针front循环增1，并将该位置的元素值赋给e。
 *
 * 参  数：q，队列指针；
 *        e，待出队元素值
 *
 * 返回值：0(队空)或1(出队成功)
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int deQueue(SqQueue **q,ElemType *e){
    //队空
    if ((*q)->rear==(*q)->front){
        return 0;
    }
    //出队
    *e=(*q)->data[(*q)->front];
    (*q)->front=((*q)->front+1)%MaxSize;
}

/*------------------------------------------------------
 * 函数名：deInRear
 *
 * 功  能：从队尾删除
 *
 * 描  述：双端队列：在环形队列的两端都可以进行插入和删除操作。
 *
 * 参  数：q，队列指针；
 *        e，待出队元素值
 *
 * 返回值：0(队空)或1(出队成功)
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int deInRear(SqQueue **q,ElemType *e){
    //队空
    if ((*q)->rear==(*q)->front){
        return 0;
    }
    //从队尾删除
    *e=(*q)->data[(*q)->rear];
    (*q)->rear=((*q)->rear-1+MaxSize)%MaxSize;
    return 1;
}

/*------------------------------------------------------
 * 函数名：enInFront
 *
 * 功  能：从队首插入
 *
 * 描  述：双端队列：在环形队列的两端都可以进行插入和删除操作。
 *
 * 参  数：q，队列指针；
 *        e，待入队元素值
 *
 * 返回值：0(队满)或1(入队成功)
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int enInFront(SqQueue **q,ElemType e){
    //队满
    if (((*q)->rear+1)%MaxSize==(*q)->front){
        return 0;
    }
    (*q)->data[(*q)->front]=e;
    (*q)->front=((*q)->front-1+MaxSize)%MaxSize;
    return 1;
}