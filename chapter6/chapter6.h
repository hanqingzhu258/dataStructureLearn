//
// Description:递归
// Created by hanqing zhu on 2018/11/17.
//

/*------------------------------------------------------
 *
 * 递归设计的步骤如下：
 * （1）对原问题f(s)进行分析，假设出合理的“较小问题”f(s')
 *     （与数学归纳法中假设n=k-1时等式成立相似）。
 * （2）假设是f(s')可解的，在此基础上确定f(s)的解，即给出f(s)与
 *      f(s')之间的关系（与数学归纳法中求证n=k时等式成立的过程相似）。
 * （3）确定一个特殊情况（如f(1)或f(0)）的解，由此作为递归出口
 *     （与数学归纳法中求证n=1时等式成立相似）。
 *
 * author： hanqing zhu 2018/11/17 16:57
 * -----------------------------------------------------*/

#ifndef CHAPTER6_CHAPTER6_H
#define CHAPTER6_CHAPTER6_H

#include "main.h"
#include "string/unit2_1.h"
#include "list/list.h"

//最多皇后个数
#define N 20
extern int q[];
extern int count;


//exa6-1
int fun(int n);

//unit1.2-定义是递归的
//求Fibonacci数列
int fib(int n);

//unit1.2-数据结构是递归的
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LinkList;
//求一个不带头结点的单链表head的所有data域（假设为int型）之和
int sum(LinkList *head);

//unit1.2-问题的求解方法是递归的
//Hanio问题
void Hanio(int n,char X, char Y, char Z);

//unit3.1-递归求数组的最小值
float f(float A[],int i);

//exa6-2
//利用串的基本运算写出对串求逆的递归算法
SqString invert(SqString s);

//exa6-3
//求顺序表{a1,a2,...,an}中的最大元素
ElemType max_exa6_3(SqList L,int i,int j);

//exa6-5
//求解皇后问题：在nxn的方格棋盘上，放置n个皇后，要求每个皇后不同行、
//            不同列、不同左右对角线。
//输出一个解
void print(int n);
//测试第k列的第i行上能否摆放皇后
int find(int i,int k);
//将第k个皇后摆放在第k列上
void place(int k,int n);


#endif //CHAPTER6_CHAPTER6_H
