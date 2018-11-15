//
// Description:稀疏矩阵的十字链表表示
// Created by hanqing zhu on 2018/11/15.
//

#ifndef CHAPTER5_UNIT2_2_H
#define CHAPTER5_UNIT2_2_H

#include "main.h"

//十字链表类型定义
typedef struct mtxn{
    //行号
    int row;
    //列号
    int col;
    //向右和向下的指针
    struct mtxn *right,*down;
    union {
        ElemType value;
        struct mtxn *link;
    }tag;
}MatNode;

//从一个二维矩阵创建其十字链表表示
void createCLLMat(MatNode **mh,ElemType a[M][N]);

//输出十字链表矩阵
void dispCLLMat(MatNode *mh);

//exa5-4
//设计一个用于存储双层集合的存储结构，所谓双层集合是指这样的集合，
//其中每个元素又是一个集合（称为集合元素），该集合元素由普通的元
//素构成。例如，s={{1,3},{1,7,8},{5,6}}

//数据结点类型定义
typedef struct dnode{
    ElemType data;
    struct dnode *next;
}DType;
//集合元素头结点类型定义
typedef struct hnode{
    DType *next;
    struct hnode *link;
}HType;
//集合头结点和集合元素头结点的类型相同




#endif //CHAPTER5_UNIT2_2_H
