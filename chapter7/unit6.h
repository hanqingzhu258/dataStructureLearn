//
// Description: 二叉树的构造
// Created by hanqing zhu on 2018/11/21.
//

#ifndef CHAPTER7_UNIT6_H
#define CHAPTER7_UNIT6_H


#include "btree.h"

/*------------------------------------------------------
 *
 * 根据先序序列和中序序列构造二叉树
 * 
 * author： hanqing zhu 2018/11/21 20:44
 * -----------------------------------------------------*/
BTNode * createBT1_unit6(char *pre,char *in,int n);
BTNode * createBT1_unit6_book(char *pre, char *in,int n);

/*------------------------------------------------------
 *
 * 根据后序序列和中序序列构造二叉树
 * 
 * author： hanqing zhu 2018/11/21 22:14
 * -----------------------------------------------------*/
BTNode * createBT2_unit6_book(char *post, char *in,int n);

/*------------------------------------------------------
 *
 * 将二叉树的顺序存储结构转换成二叉链存储结构
 * 
 * author： hanqing zhu 2018/11/21 22:39
 * -----------------------------------------------------*/
BTNode * trans_unit6(SqBTree a, int i);

#endif //CHAPTER7_UNIT6_H
