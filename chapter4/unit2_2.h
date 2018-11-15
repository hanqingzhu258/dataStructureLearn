//
// Created by hanqing zhu on 2018/11/13.
//

#ifndef CHAPTER4_UNIT2_2_H
#define CHAPTER4_UNIT2_2_H

//链串的结点类型定义
//为方便起见，这里规定链串结点大小均为1
typedef struct snode{
    char data;
    struct snode *next;
}LiString;

//将一个字符串常量赋给串s，即生成一个其值等于cstr的串s
void liStrAssign(LiString **s, char cstr[]);

//将串t赋值给串s
void liStrCopy(LiString **s,LiString *t);

//判断串相等：若两个串s与t相等返回真（1）；否则返回假（0）
int liStrEqual(LiString *s,LiString *t);

//求串长：返回串s中的字符个数
int liStrLength(LiString *s);

//串连接：返回由两个串s和t连接在一起形成的新串
LiString * liConcat(LiString *s,LiString *t);

//求子串：返回串s中从第i（1<=i<=strLength(s)）个字符开始的、由连续j个字符组成的子串
//参数不正确时返回一个空串
LiString * subLiStr(LiString *s, int i, int j);

//将串s2插入到串s1的第i（1<=i<=strLength(s)+1）个字符中，即将s2的第一个字符作为s1的
//第i个字符，并返回产生的新串。参数不正确时返回一个新串。
LiString * insLiStr(LiString *s1, int i,LiString *s2);

//从串s中删去第i（1<=i<=strLength(s)）个字符开始的、由连续j个字符组成的子串，并返回
//产生的新串。参数不正确时返回一个空串。
LiString * delLiStr(LiString *s,int i, int j);

//在串s中，将第i（1<=i<=strLength(s)）个字符开始的、由连续j个字符组成的子串，用串t
//代替，并返回产生的新串。参数不正确时返回一个空串。
LiString * repLiStr(LiString *s,int i, int j,LiString *t);

//输出串s的所有元素值
void dispLiString(LiString *s);

//exa4-3
void exa4_3_repl(LiString **s);






#endif //CHAPTER4_UNIT2_2_H
