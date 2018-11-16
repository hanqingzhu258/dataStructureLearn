//
// Description:
// Created by hanqing zhu on 2018/11/15.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "unit3.h"

/*------------------------------------------------------
 * 函数名：glLength
 *
 * 功  能：求广义表的长度
 *
 * 描  述：非递归算法
 *
 * 参  数：g，广义表头结点
 *
 * 返回值：广义表的长度
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int glLength(GLNode *g){
    int n=0;
    g=g->val.sublist;
    while (g!=NULL){
        n++;
        g=g->link;
    }
    return n;
}

/*------------------------------------------------------
 * 函数名：glDepth
 *
 * 功  能：求广义表的深度
 *
 * 描  述：对于带头结点的广义表g，广义表深度的递归定义是它等于
 *        所有子表中表的最大深度加1.若g为原子，其深度为0。
 *
 * 参  数：g，广义表
 *
 * 返回值：广义表的深度
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int glDepth(GLNode *g){
    int max=0,dep;
    //为原子时返回0
    if (g->tag==0){
        return 0;
    }
    //g指向第一个元素
    g=g->val.sublist;
    //为空表时返回1
    if (g==NULL){
        return 1;
    }
    //遍历表中的每一个元素
    while(g!=NULL){
        //元素为字表的情况
        if(g->tag==1){
            //递归调用求出子表的深度
            dep=glDepth(g);
            //max为同一层所求过的子表中深度的最大值
            if (dep>max){
                max=dep;
            }
        }
        //使g指向下一个元素
        g=g->link;
    }
    //返回表的深度
    return(max+1);
}

/*------------------------------------------------------
 * 函数名：createGL
 *
 * 功  能：建立广义表的链式存储结构
 *
 * 描  述：递归算法
 *
 * 参  数：s，具有广义表格式的字符串参数
 *         （格式：元素之间用一个逗号分隔，表元素的起止符号分别
 *         为左右圆括号，空表在其圆括号内不包含任何字符）
 *
 * 返回值：由s生成的广义表存储结构的头结点指针h
 *
 * 时间复杂度：O(n),n为广义表中所有字符的个数
 * -----------------------------------------------------*/
GLNode * createGL(char **s){
    GLNode *h;
    //取一个扫描字符，取指针值后，指针自增
    char ch=*(*s)++;
    //串末结束判断
    if (ch!='\0'){
        //创建一个新结点
        h=(GLNode *)malloc(sizeof(GLNode));
        //当前字符为左括号时
        if (ch=='('){
            //新结点作为表头结点
            h->tag=1;
            //递归构造子表并链到表头结点
            h->val.sublist=createGL(s);
        }
        //遇到')'字符时，h置空
        else if(ch==')') {
            h=NULL;
        }
        //新结点作为原子结点
        else {
            h->tag=0;
            h->val.data=ch;
        }
    }
    //串结束，h置为空
    else{
        h=NULL;
    }
    //取下一个扫描字符
    ch=*(*s)++;
    //串未结束，继续构造兄弟结点
    if (h!=NULL){
        //当前字符为','
        if (ch==','){
            h->link=createGL(s);
        }
        //没有兄弟了，将兄弟指针置为NULL
        else {
            h->link=NULL;
        }
    }
    //返回广义表指针
    return h;
}

/*------------------------------------------------------
 * 函数名：dispGL
 *
 * 功  能：输出广义表
 *
 * 描  述：递归输出
 *
 * 参  数：g，广义表头结点
 *
 * 返回值：无
 *
 * 时间复杂度：O(n)，n为广义表中所有字符的个数
 * -----------------------------------------------------*/
void dispGL(GLNode *g){
    //表不为空判断
    if(g!=NULL){
        //为表结点时
        if (g->tag==1){
            printf("(");
            if (g->val.sublist==NULL){
                //输出空子表
                printf("");
            }else{
                //递归输出子表
                dispGL(g->val.sublist);
            }
        }else{
            printf("%c",g->val.data);
        }
        if (g->tag==1){
            printf(")");
        }
        if (g->link!=NULL){
            printf(",");
            //递归输出后续表的内容
            dispGL(g->link);
        }
    }
}