//
// Created by hanqing zhu on 2018/11/11.
//

#include "main.h"

#ifndef CHAPTER3_UNIT1_4_H
#define CHAPTER3_UNIT1_4_H

#endif //CHAPTER3_UNIT1_4_H

//定义运算符的个数
#define MaxOp 7

//设定运算符优先级
struct OPS{
    //运算符
    char ch;
    //优先级
    int pri;
};

//定义外部变量
//避免出现error:"multiple definition of xxx"
extern struct OPS lpri[],rpri[];

//求左运算符op的优先级
int leftpri(char op);

//求右运算符op的优先级
int rightpri(char op);

//判断ch是否为运算符
int inOp(char ch);

//op1和op2运算符优先级的比较结果
int precede(char op1, char op2);

//将算数表达式exp转换成后缀表达式postexp
void trans(char *exp,char postexp[]);

//对后缀表达式进行求值
float compvalue(char *postexp);

//迷宫求解算法
int mgpath(int xi,int yi,int xe,int ye,int mg[M+2][N+2]);


