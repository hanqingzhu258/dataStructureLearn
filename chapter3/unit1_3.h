//
// Created by hanqing zhu on 2018/11/10.
//

#ifndef CHAPTER3_UNIT1_3_H
#define CHAPTER3_UNIT1_3_H

#endif //CHAPTER3_UNIT1_3_H

#include "main.h"

//链栈类型定义
typedef struct linknode{
    //数据域
    ElemType data;
    //指针域
    struct linknode *next;
}LiStack;

//初始化栈
void initLiStack(LiStack **s);

//销毁栈
void clearLiStack(LiStack **s);

//求栈的长度
int liStackLength(LiStack *s);

//判断栈是否为空
int liStackEmpty(LiStack *s);

//进栈
void liPush(LiStack **s,ElemType e);

//出栈
int liPop(LiStack **s,ElemType *e);

//取栈顶元素
int getLiTop(LiStack *s,ElemType *e);

//显示栈中元素
void dispLiStack(LiStack *s);

//exa3-5
int match_exa3_5(char exp[],int n);