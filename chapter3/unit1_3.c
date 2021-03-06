//
// Created by hanqing zhu on 2018/11/10.
//
#include <stdlib.h>
#include <stdio.h>
#include "unit1_3.h"

/*------------------------------------------------------
* 函数名：initStack
*
* 功  能：初始化栈
*
* 描  述：建立一个空栈，实际上是创建链栈的头结点，并将其next域置空
*
* 参  数：s，链栈的头结点指针
*
* 返回值：无
*
* 时间复杂度：
* -----------------------------------------------------*/
void initLiStack(LiStack **s){
    *s=(LiStack *)malloc(sizeof(LiStack));
    (*s)->next=NULL;
}

/*------------------------------------------------------
* 函数名：clearStack
*
* 功  能：销毁栈
*
* 描  述：释放栈s占用的全部存储空间
*
* 参  数：s，链栈的头结点
*
* 返回值：无
*
* 时间复杂度：
* -----------------------------------------------------*/
void clearLiStack(LiStack **s){
    LiStack *p=*s,*q;
    while(p!=NULL){
        q=p->next;
        free(p);
        p=q;
    }
}

/*------------------------------------------------------
* 函数名：stackLength
*
* 功  能：求栈的长度
*
* 描  述：从第一个数据节点开始扫描单链表，用n保存访问的数据结点的个数，
         最后返回n值
*
* 参  数：s，链栈的头结点指针
*
* 返回值：栈的长度
*
* 时间复杂度：
* -----------------------------------------------------*/
int liStackLength(LiStack *s){
    int n=0;
    LiStack *p=s;
    while(p->next!=NULL){
        p=p->next;
        n++;
    }
    return n;
}

/*------------------------------------------------------
* 函数名：stackEmpty
*
* 功  能：判断链栈是否为空
*
* 描  述：栈s为空的条件是s->next==NULL,即单链表中没有数据结点。
*
* 参  数：s，链栈的头结点
*
* 返回值：0(非空)或1(空)
*
* 时间复杂度：
* -----------------------------------------------------*/
int liStackEmpty(LiStack *s){
    return (s->next==NULL);
}

/*------------------------------------------------------
* 函数名：push
*
* 功  能：进栈
*
* 描  述：将数据结点插入到头结点之后
*
* 参  数：s，链栈的头结点指针；
          e，待进栈元素的值
*
* 返回值：
*
* 时间复杂度：
* -----------------------------------------------------*/
void liPush(LiStack **s,ElemType e){
    LiStack *p;
    p=(LiStack *)malloc(sizeof(LiStack));
    p->data=e;
    p->next=(*s)->next;
    (*s)->next=p;
}

/*------------------------------------------------------
* 函数名：pop
*
* 功  能：出栈
*
* 描  述：在栈不为空的条件下，将头结点的指针域所指数据结点的数据域赋给e，
          然后将其删除。
*
* 参  数：s，链栈的头结点指针
          e，出栈元素的值
*
* 返回值：0(栈为空)或1(出栈成功)
*
* 时间复杂度：
* -----------------------------------------------------*/
int liPop(LiStack **s,ElemType *e){
    LiStack *p;
    p=(*s)->next;
    if (p==NULL){
        return 0;
    }
    *e=p->data;
    (*s)->next=p->next;
    free(p);
    return 1;
}

/*------------------------------------------------------
* 函数名：getTop
*
* 功  能：取栈顶元素
*
* 描  述：在栈不为空的条件下，将头结点的指针域所指数据结点的数据域赋给e
*
* 参  数：s，链栈的头结点的指针；
         e，栈顶元素值
*
* 返回值：0(栈空)或1(取值成功)
*
* 时间复杂度：
* -----------------------------------------------------*/
int getLiTop(LiStack *s,ElemType *e){
    if(s->next==NULL){
        return 0;
    }
    *e=s->next->data;
    return 1;
}

/*------------------------------------------------------
* 函数名：dispStack
*
* 功  能：显示栈中元素
*
* 描  述：从第一个数据结点开始扫描单链表，并输出当前访问结点的数据域值。
*
* 参  数：s，链栈的头结点的指针
*
* 返回值：
*
* 时间复杂度：
* -----------------------------------------------------*/
void dispLiStack(LiStack *s){
    LiStack *p=s->next;
    while(p!=NULL){
        printf("%c ",p->data);
        p=p->next;
    }
    printf("\n");
}

/*------------------------------------------------------
 * 函数名：match_exa3_5
 *
 * 功  能：判断输入的表达式中括号是否配对（假设只含有左、右圆括号）
 *
 * 描  述：设置一个栈st，扫描表达式exp，遇到左括号时进栈；遇到右括号时：
 *        若栈顶为左括号，则出栈，否则返回0.当表达式扫描完毕，栈为空时
 *        返回1；否则返回0.
 *
 * 参  数：exp，待判断表达式
 *        n，表达式的长度
 *
 * 返回值：0(不配对)或1(配对)
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int match_exa3_5(char exp[],int n){
    int i=0;
    LiStack *s;
    ElemType e;

    initLiStack(&s);
    while (i<n){
        if (exp[i]=='('){
            liPush(&s,exp[i]);
        }
        if (exp[i]==')'){
            if(getLiTop(s,&e)==1){
                if (e!='('){
                    return 0;
                }
                liPop(&s,&e);
            }else{
                return 0;
            }
        }
        i++;
    }
    if (liStackEmpty(s)==1){
        return 1;
    }

    return 0;
}