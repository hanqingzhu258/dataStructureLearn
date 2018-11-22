//
// Description: 线索二叉树：先序线索二叉树、中序线索二叉树、后序线索二叉树
// Created by hanqing zhu on 2018/11/22.
//

#ifndef CHAPTER7_UNIT7_H
#define CHAPTER7_UNIT7_H

#include "main.h"

/*------------------------------------------------------
 *
 * 线索树结点类型定义
 *
 * author： hanqing zhu 2018/11/22 10:15
 * -----------------------------------------------------*/
typedef struct node{
    //结点数据域
    ElemType data;
    //增加的线索标记
    int ltag,rtag;
    //左孩子或线索指针
    struct node * lchild;
    //右孩子或线索指针
    struct node * rchild;
}TBTNode;

/*------------------------------------------------------
 *
 * 中序线索化二叉树
 * pre：全局变量
 * thread_in：对二叉树b进行中序线索化
 * createThread_in：中序线索化二叉树
 * 
 * author： hanqing zhu 2018/11/22 10:15
 * -----------------------------------------------------*/
extern TBTNode *pre;
void thread_in(TBTNode **p);
TBTNode * createThread_in(TBTNode *b);

/*------------------------------------------------------
 *
 * 遍历线索二叉树
 *
 * author： hanqing zhu 2018/11/22 10:51
 * -----------------------------------------------------*/
void thInOrder(TBTNode *tb);


#endif //CHAPTER7_UNIT7_H
