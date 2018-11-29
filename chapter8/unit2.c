//
// Description: 
// Created by hanqing zhu on 2018/11/22.
//

#include <stdlib.h>
#include <stdio.h>
#include "unit2.h"

/*------------------------------------------------------
 * 函数名：matToList_exa8_2
 *
 * 功  能：对于具有n个结点的无向图：将一个邻接矩阵转换为邻接表
 *
 * 描  述：在邻接矩阵上查找值不为0的元素，找到这样的元素后创建一
 *        个表结点并在邻接表对应的单链表中采用头插法插入该结点。
 *
 * 参  数：g，邻接矩阵；
 *        G，邻接表。
 *
 * 返回值：无
 *
 * 时间复杂度：O(n^2)
 *
 * author： hanqing zhu 2018/11/23 9:15
 * -----------------------------------------------------*/
void matToList_exa8_2(MGraph g,ALGraph **G){
    int i,j,n=g.n;
    ArcNode *p;
    *G=(ALGraph *)malloc(sizeof(ALGraph));
    //给邻接表中所有头结点的指针域置初值
    for (i=0;i<n;i++){
        (*G)->adjList[i].firstarc=NULL;
    }
    //检查邻接矩阵的每个元素
    for (i=0;i<n;i++){
        for (j=n-1;j>=0;j--){
            if (g.edges[i][j]!=0&&g.edges[i][j]<INF){
                //创建一个结点p
                p=(ArcNode *)malloc(sizeof(ArcNode));
                p->adjvex=j;
                //采用头插法将p插入链表中
                p->nextarc=(*G)->adjList[i].firstarc;
                (*G)->adjList[i].firstarc=p;
            }
        }
    }
    (*G)->n=n;
    (*G)->e=g.e;
}

/*------------------------------------------------------
 * 函数名：listToMat
 *
 * 功  能：对于具有n个结点的无向图：将一个邻接矩阵转换为邻接表
 *
 * 描  述：在邻接表上查找相邻结点，找到后修改相应邻接矩阵元素的值。
 *
 * 参  数：g，邻接矩阵；
 *        G，邻接表。
 *
 * 返回值：无
 *
 * 时间复杂度：O(n+2e)，e为图的边数
 *
 * author： hanqing zhu 2018/11/23 9:15
 * -----------------------------------------------------*/
void listToMat(ALGraph *G,MGraph *g){
    int i,n=G->n;
    ArcNode *p;
    for(i=0;i<n;i++){
        p=G->adjList[i].firstarc;
        while (p!=NULL){
            g->edges[i][p->adjvex]=1;
            p=p->nextarc;
        }
    }
    g->n=n;
    g->e=G->e;
}

/*------------------------------------------------------
 * 函数名：initMGraph
 *
 * 功  能：根据二维数组e和数组v初始化邻接矩阵图
 *
 * 描  述：
 *
 * 参  数：g，邻接矩阵图
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/23 10:43
 * -----------------------------------------------------*/
void initMGraph(MGraph *g,int e[MAXV][MAXV],int v[MAXV],int n,int es){
    int i,j;
    VertexType vex;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            g->edges[i][j]=e[i][j];
            vex.no=v[i];
            g->vexs[i]=vex;
        }
    }
    g->e=es;
    g->n=n;
}

/*------------------------------------------------------
 * 函数名：dispAdj
 *
 * 功  能：输出邻接表
 *
 * 描  述：格式：“元素值：邻接元素值1 邻接元素值2 ...  ”
 *
 * 参  数：G，图的邻接表存储
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/26 15:55
 * -----------------------------------------------------*/
void dispAdj(ALGraph *G){
    int i;
    ArcNode *p;
    for(i=0;i<G->n;i++){
        printf("%d：",i);
        p=G->adjList[i].firstarc;
        while (p!=NULL){
            printf("%2d ",p->adjvex);
            p=p->nextarc;
        }
        printf("\n");
    }
}