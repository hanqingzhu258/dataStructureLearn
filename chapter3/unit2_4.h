//
// Created by hanqing zhu on 2018/11/12.
//

#include "main.h"

#ifndef CHAPTER3_UNIT2_4_H
#define CHAPTER3_UNIT2_4_H

#endif //CHAPTER3_UNIT2_4_H


//unit2_4.1 求解报数问题
void number(int n);

//unit2_4.2 求解迷宫问题
//定义存储栈
struct {
    //方块的位置
    int i,j;
    //本路径中上一方块在队列Qu中的下标
    int pre;
}Qu[MaxSize];

int mgpathInQueue(int xi,int yi,int xe,int ye,int mg[M+2][N+2]);
void print(int front);