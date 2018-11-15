//
// Created by hanqing zhu on 2018/11/12.
//

#include "main.h"

#ifndef CHAPTER4_UNIT2_1_H
#define CHAPTER4_UNIT2_1_H



//对于非紧缩格式的顺序串，其类型定义如下：
typedef struct {
    //存放字符串
    char data[MaxSize];
    //串长
    int length;
}SqString;

//将一个字符串常量赋给串s，即生成一个其值等于cstr的串s
void strAssign(SqString *s, char cstr[]);

//将串t赋值给串s
void strCopy(SqString *s,SqString t);

//判断串相等：若两个串s与t相等返回真（1）；否则返回假（0）
int strEqual(SqString s,SqString t);

//求串长：返回串s中的字符个数
int strLength(SqString s);

//串连接：返回由两个串s和t连接在一起形成的新串
SqString concat(SqString s,SqString t);

//求子串：返回串s中从第i（1<=i<=strLength(s)）个字符开始的、由连续j个字符组成的子串
//参数不正确时返回一个空串
SqString subStr(SqString s, int i, int j);

//将串s2插入到串s1的第i（1<=i<=strLength(s)+1）个字符中，即将s2的第一个字符作为s1的
//第i个字符，并返回产生的新串。参数不正确时返回一个新串。
SqString insStr(SqString s1, int i,SqString s2);

//从串s中删去第i（1<=i<=strLength(s)）个字符开始的、由连续j个字符组成的子串，并返回
//产生的新串。参数不正确时返回一个空串。
SqString delStr(SqString s,int i, int j);

//在串s中，将第i（1<=i<=strLength(s)）个字符开始的、由连续j个字符组成的子串，用串t
//代替，并返回产生的新串。参数不正确时返回一个空串。
SqString repStr(SqString s,int i, int j,SqString t);

//输出串s的所有元素值
void dispString(SqString s);

//exa4_1
//不能起名为strcmp,和stdio.h中的函数有冲突
int strcmp2(SqString s,SqString t);

//exa4_2
void longestString(SqString s,int *index,int *max);


#endif //CHAPTER4_UNIT2_1_H


