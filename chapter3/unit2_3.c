//
// Created by hanqing zhu on 2018/11/11.
//

#include <stdlib.h>
#include "unit2_3.h"


/*------------------------------------------------------
 * 函数名：initLiQueue
 *
 * 功  能：初始化队列
 *
 * 描  述：构造一个空队列，即创建一个链队结点，其front和rear域均置为NULL。
 *
 * 参  数：q，队列指针
 *
 * 返回值：无
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void initLiQueue(LiQueue **q) {
    *q = (LiQueue *) malloc(sizeof(LiQueue));
    (*q)->front = (*q)->rear = NULL;
}

/*------------------------------------------------------
 * 函数名：clearLiQueue
 *
 * 功  能：销毁队列
 *
 * 描  述：释放队列q占用的存储空间，包括链队结点和所有数据结点的存储空间。
 *
 * 参  数：q，队列指针
 *
 * 返回值：无
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void clearLiQueue(LiQueue **q) {
    QNode *p = (*q)->front, *s;
    while (p != NULL) {
        s = p->next;
        free(p);
        p = s;
    }
    free(*q);
}

/*------------------------------------------------------
 * 函数名：liQueueEmpty
 *
 * 功  能：判断队列是否为空
 *
 * 描  述：若链队结点的rear域值为NULL，表示队列为空，返回1；否则返回0。
 *
 * 参  数：q，队列指针
 *
 * 返回值：0(非空)或1(空)
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int liQueueEmpty(LiQueue *q) {
    return (q->rear == NULL);
}

/*------------------------------------------------------
 * 函数名：enLiQueue
 *
 * 功  能：入队列
 *
 * 描  述：创建data域为e的数据结点*s。若原队列为空，则将链队结点
 *        的两个域均指向*s结点，否则，将*s链到单链表的末尾，并让
 *        链队结点的rear域指向它
 *
 * 参  数：q，队列指针；
 *        e，待入队元素值。
 *
 * 返回值：无
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void enLiQueue(LiQueue **q, ElemType e) {
    QNode *s = (QNode *) malloc(sizeof(QNode));
    s->data = e;
    s->next = NULL;
    //若链队为空，则新结点既是队首节点又是队尾结点
    if ((*q)->rear == NULL) {
        (*q)->rear = (*q)->front = s;
    }
        //将*s结点链到队尾，并将rear指向它
    else {
        (*q)->rear->next = s;
        (*q)->rear = s;
    }

}

/*------------------------------------------------------
 * 函数名：deLiQueue
 *
 * 功  能：出队列
 *
 * 描  述：若原队列不为空，则将第一个数据结点的data域值赋给e，并删除之。
 *        若出队之前队列中只有一个结点，则需将链队结点的两个域均置为NULL，
 *        表示队列已空。
 *
 * 参  数：q，队列指针；
 *        e，待出队元素值
 *
 * 返回值：0(队空)或1(出队成功)
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int deLiQueue(LiQueue **q, ElemType *e) {
    QNode *s;
    if ((*q)->rear == NULL) {
        return 0;
    }
    s = (*q)->front;
    *e = s->data;
    if ((*q)->front == (*q)->rear) {
        (*q)->front = (*q)->rear = NULL;
    } else {
        (*q)->front = s->next;
    }
    free(s);
    return 1;
}


//采用一个带头结点的循环双链表存储队列，设计初始化、进队和出队的算法
//DLinkList为双链表结点类型
void initDLQueue(DLinkList **q) {
    *q = (DLinkList *) malloc(sizeof(DLinkList));
    (*q)->prior = (*q)->next = *q;
}

int dlQueueEmpty(DLinkList *q) {
    return (q->next == q);
}

//出队在链表的表头进行，入队在链表的表尾进行
void enDLQueue(DLinkList **q, ElemType e) {
    DLinkList *s = (DLinkList *) malloc(sizeof(DLinkList));
    s->data = e;
    //如果当前循环双链队为空
    if ((*q)->next==*q){
        (*q)->next=s;
    }
    //将s添加到当前尾结点的后面
    (*q)->prior->next = s;
    //s与当前尾结点建立联系
    s->prior = (*q)->prior;
    s->next = (*q);
    //头结点重新指向新的尾结点
    (*q)->prior = s;
}

int deDLQueue(DLinkList **q,ElemType *e){
    DLinkList *p=(*q)->next;
    //为空
    if (p==*q){
        return 0;
    }
    (*q)->next=p->next;
    p->next->prior=*q;
    *e=p->data;
    free(p);
    return 1;
}