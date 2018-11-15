//
// Created by hanqing zhu on 2018/11/13.
//

#include "unit2_1.h"

#ifndef CHAPTER4_UNIT3_H
#define CHAPTER4_UNIT3_H



//brute-force算法：BF算法
int index(SqString s,SqString t);

//KMP算法
void getNext(SqString t,int next[]);
int KMPIndex(SqString s,SqString t);

//修正的KMP算法
void getNextVal(SqString t,int nextVal[]);
int KMPIndex1(SqString s,SqString t);



#endif //CHAPTER4_UNIT3_H
