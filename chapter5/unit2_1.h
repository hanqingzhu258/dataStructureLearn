//
// Description:稀疏矩阵的三元组顺序表
// Created by hanqing zhu on 2018/11/15.
//

#ifndef CHAPTER5_UNIT2_1_H
#define CHAPTER5_UNIT2_1_H


#include "main.h"

//三元组定义
typedef struct {
    //行号
    int r;
    //列号
    int c;
    //元素值
    ElemType d;
}TupNode;

//三元组顺序表定义
typedef struct {
    //行数值
    int rows;
    //列数值
    int cols;
    //非零元素个数
    int nums;
    //通常以行序为主序顺序排列，是一种下标按行有序的存储结构
    //可简化大多数稀疏矩阵运算算法
    TupNode data[MaxSize];
}TSMatrix;


//从一个二维矩阵创建其三元组表示
void createMat(TSMatrix *t,ElemType A[M][N]);

//三元组元素赋值
int value(TSMatrix *t,ElemType x,int rs,int cs);

//将指定位置的元素值赋给变量
int assign(TSMatrix t,ElemType *x,int rs,int cs);

//输出三元组
void dispMat(TSMatrix t);

//矩阵转置
void tranTat(TSMatrix t,TSMatrix *tb);

//矩阵相加
int matAdd(TSMatrix a,TSMatrix b,TSMatrix *c);


#endif //CHAPTER5_UNIT2_1_H
