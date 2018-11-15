//
// Description:稀疏矩阵的十字链表表示
// Created by hanqing zhu on 2018/11/15.
//

#include <stdlib.h>
#include <stdio.h>
#include "unit2_2.h"

/*------------------------------------------------------
 * 函数名：createCLLMat
 *
 * 功  能：从一个二维矩阵创建其十字链表表示
 *
 * 描  述：先建立十字链表头结点的循环链表，然后以行序扫描二维矩阵A，
 *        将非零的元素插入到十字链表中。插入操作如下：
 *        1.创建一个结点*p；
 *        2.根据行号找到在行表中的插入位置并插入；
 *        3.根据列号找到在列表中的插入位置并插入。
 *
 * 参  数：mh，十字链表头结点；
 *        A，二维矩阵。
 *
 * 返回值：无
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void createCLLMat(MatNode **mh,ElemType A[M][N]){
    int i,j;
    MatNode *h[Max],*p,*q,*r;
    *mh=(MatNode *)malloc(sizeof(MatNode));
    (*mh)->col=N;
    (*mh)->row=M;
    r=*mh;
    //循环创建行列头结点
    for (i=0;i<Max;i++){
        h[i]=(MatNode *)malloc(sizeof(MatNode));
        h[i]->row=h[i]->col=-1;
        h[i]->down=h[i]->right=h[i];
        r->tag.link=h[i];
        r=h[i];
    }
    r->tag.link=*mh;
    //以行序创建数据结点
    for(i=0;i<M;i++){
        for (j=0;j<N;j++){
            if (A[i][j]!=0){
                p=(MatNode *)malloc(sizeof(MatNode));
                p->col=j;
                p->row=i;
                p->tag.value=A[M][N];
                //找到第i行的头结点，并找到该行链表的最尾端
                q=h[i];
                while (q->right!=h[i]&&q->right->col<j){
                    q=q->right;
                }
                //完成行表的插入
                p->right=q->right;
                q->right=p;
                //找到第j列的头结点，并找到该列链表的最尾端
                q=h[j];
                while (q->down!=h[j]&&q->down->row<i){
                    q=q->down;
                }
                //完成列表的插入
                p->down=q->down;
                q->down=p;
            }
        }
    }
}

/*------------------------------------------------------
 * 函数名：dispCLLMat
 *
 * 功  能：输出十字链表矩阵
 *
 * 描  述：以行序的方式从头到尾扫描十字链表h，依次输出元素值
 *
 * 参  数：mh，十字链表
 *
 * 返回值：无
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void dispCLLMat(MatNode *mh){
    MatNode *p,*q;
    printf("行=%d  列=%d\n",mh->row,mh->col);
    p=mh->tag.link;
    while (p!=mh){
        q=p->right;
        while (p!=q){
            printf("%d\t%d\t%d\n",q->row,q->col,q->tag.value);
            q=q->right;
        }
        p=p->tag.link;
    }
}