//
// Description:广义表（递归的数据结构）：动态链式结构
// Created by hanqing zhu on 2018/11/15.
//

#ifndef CHAPTER5_UNIT3_H
#define CHAPTER5_UNIT3_H


#include "main.h"

//广义表结点类型定义
typedef struct lnode{
    int tag;
    union {
        //原子值
        ElemType data;
        //指向子表的指针
        struct lnode *sublist;
    }val;
    //指向下一个元素
    struct lnode *link;
}GLNode;

//求广义表的长度
int glLength(GLNode *g);

//求广义表的深度
int glDepth(GLNode *g);

//建立广义表的链式存储结构
GLNode * createGL(char **s);

//输出广义表
void dispGL(GLNode *g);





#endif //CHAPTER5_UNIT3_H
