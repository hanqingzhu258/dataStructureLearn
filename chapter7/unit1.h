//
// Description: 树的存储结构
// Created by hanqing zhu on 2018/11/18.
//

#ifndef CHAPTER7_UNIT1_H
#define CHAPTER7_UNIT1_H

#include "main.h"

/*------------------------------------------------------
 *
 * 双亲存储结构
 *
 * author： hanqing zhu 2018/11/18 15:54
 * -----------------------------------------------------*/
typedef struct {
    //结点的值
    ElemType data;
    //指向双亲的位置
    int parent;
} PTree[MaxSize];

/*------------------------------------------------------
 *
 * 孩子链存储结构
 *
 * author： hanqing zhu 2018/11/18 15:59
 * -----------------------------------------------------*/
typedef struct node{
    //结点的值
    ElemType data;
    //指向孩子结点
    struct node *sons[MaxSons];
};

/*------------------------------------------------------
 *
 * 孩子兄弟链存储结构：
 *                  数据元素域
 *                  指向该结点的第一个孩子结点的指针域
 *                  指向该结点的下一个兄弟结点的指针域
 *
 * 实际上是把该树转换为二叉树的存储结构
 *
 * 优点：可方便地实现树和二叉树的相互转换
 *
 * 缺点：从当前结点查找双亲结点比较麻烦，需要从树根结点开始逐个比较
 *
 * author： hanqing zhu 2018/11/18 16:22
 * -----------------------------------------------------*/
typedef struct tnode{
    //结点的值
    ElemType data;
    //指向兄弟结点
    struct tnode *hp;
    //指向孩子结点
    struct tnode *vp;
} TSBNode;

//exa7-3
int treeHeight_exa7_3(TSBNode *t);




#endif //CHAPTER7_UNIT1_H
