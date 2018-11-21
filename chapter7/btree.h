//
// Description:二叉树的存储结构
// Created by hanqing zhu on 2018/11/18.
//

#ifndef CHAPTER7_UNIT3_H
#define CHAPTER7_UNIT3_H


#include "main.h"

/*------------------------------------------------------
 *
 * 对于完全二叉树来说，其顺序存储是十分合适的，它能够充分利用存储
 * 空间。但对于一般的二叉树，特别是对于那些单分支结点较多的二叉树
 * 来说是很不合适的，因为可能只有少数存储单元被利用，特别是对退化
 * 的二叉树（即每个分支结点都是单分支的），空间浪费更是惊人。由于
 * 顺序存储结构这种固有的缺陷，使得二叉树的插入、删除等运算十分不
 * 方便。因此，对于一般二叉树通常采用链式存储结构。
 *
 * 定义“构造”类型名（typedef的第二种用法）
 * SqBTree t;//定义大小为Maxsize的ElemType类型的数组t
 *
 * author： hanqing zhu 2018/11/18 21:22
 * -----------------------------------------------------*/
typedef ElemType SqBTree[MaxSize];

/*------------------------------------------------------
 *
 * 二叉树的链式存储结构
 *
 * author： hanqing zhu 2018/11/18 21:32
 * -----------------------------------------------------*/
typedef struct node{
    //数据元素
    ElemType data;
    //指向左孩子结点
    struct node *lchild;
    //指向右孩子结点
    struct node *rchild;
}BTNode;




#endif //CHAPTER7_UNIT3_H
