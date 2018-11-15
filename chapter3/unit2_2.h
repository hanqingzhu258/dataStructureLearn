//
// Created by hanqing zhu on 2018/11/11.
//

#include "main.h"

#ifndef CHAPTER3_UNIT2_2_H
#define CHAPTER3_UNIT2_2_H

#endif //CHAPTER3_UNIT2_2_H

//顺序队列类型定义
//为节约存储空间，一般采用环形队列方式
typedef struct {
    ElemType data[MaxSize];
    //队首和队尾指针
    int front,rear;
}SqQueue;

//初始化队列
void initQueue(SqQueue **q);

//销毁队列
void clearQueue(SqQueue **q);

//判断队列是否为空
int queueEmpty(SqQueue *q);

//入队列
int enQueue(SqQueue **q,ElemType e);

//出队列
int deQueue(SqQueue **q,ElemType *e);

//从队尾删除
int deInRear(SqQueue **q,ElemType *e);

//从队首插入
int enInFront(SqQueue **q,ElemType e);
