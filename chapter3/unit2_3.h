//
// Created by hanqing zhu on 2018/11/11.
//

#include "main.h"
#include "linkList.h"

#ifndef CHAPTER3_UNIT2_3_H
#define CHAPTER3_UNIT2_3_H

#endif //CHAPTER3_UNIT2_3_H

//链队数据结点类型定义
typedef struct qnode{
    ElemType data;
    struct qnode *next;
}QNode;

//链队类型定义
typedef struct {
    QNode *front;
    QNode *rear;
}LiQueue;

//初始化队列
void initLiQueue(LiQueue **q);

//销毁队列
void clearLiQueue(LiQueue **q);

//判断队列是否为空
int liQueueEmpty(LiQueue *q);

//入队列
void enLiQueue(LiQueue **q,ElemType e);

//出队列
int deLiQueue(LiQueue **q,ElemType *e);

//采用一个带头结点的循环双链表存储队列，设计初始化、进队和出队的算法
void initDLQueue(DLinkList **q);

int dlQueueEmpty(DLinkList *q);

void enDLQueue(DLinkList **q,ElemType e);

int deDLQueue(DLinkList **q,ElemType *e);

