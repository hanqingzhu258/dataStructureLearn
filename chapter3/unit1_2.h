//
// Created by hanqing zhu on 2018/11/10.
//

#ifndef CHAPTER3_UNIT1_2_H
#define CHAPTER3_UNIT1_2_H

#endif //CHAPTER3_UNIT1_2_H


#include <stdlib.h>
#include <stdio.h>
#include "main.h"

//顺序栈定义
typedef struct {
    ElemType data[MaxSize];
    //栈顶指针
    int top;
}SqStack;

//初始化栈
void initStack(SqStack **s);

//清空栈
void clearStack(SqStack **s);

//栈长度
int stackLength(SqStack *s);

//栈是否为空
int stackEmpty(SqStack *s);

//进栈
int push(SqStack **s,ElemType e);

//出栈
int pop(SqStack **s,ElemType *e);

//获取栈顶元素
int getTop(SqStack **s,ElemType *e);

//输出栈
void dispStack(SqStack *s);

//exa3-4
int symmetry_exa3_4(ElemType str[]);