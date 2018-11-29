//
// Description: 
// Created by hanqing zhu on 2018/11/28.
//

#include <stddef.h>
#include <stdio.h>
#include "unit6.h"


/*------------------------------------------------------
 * 函数名：topSort
 *
 * 功  能：拓扑排序
 *
 * 描  述：（1）从有向图中选择一个没有前驱（即入度为0）的顶点并且输出它；
 *        （2）从网中删去该顶点，并且删去从该顶点出发的全部有向边；
 *        （3）重复上述两步，直到剩余的网中不再存在没有前驱的顶点为止。
 *
 * 参  数：G，图的邻接表存储
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/28 16:46
 * -----------------------------------------------------*/
void topSort(ALGraph *G) {
    int i, j;
    //栈的指针为top
    int st[MAXV], top = -1;
    ArcNode *p;
    //入度置为0
    for (i = 0; i < G->n; i++) {
        G->adjList[i].count = 0;
    }
    //求所有顶点的入度
    for (i = 0; i < G->n; i++) {

        p = G->adjList[i].firstarc;
        while (p != NULL) {

            G->adjList[p->adjvex].count++;

            p=p->nextarc;
        }

    }
    //入度为0的顶点进栈
    for (i = 0; i < G->n; i++) {
        if (G->adjList[i].count == 0) {
            top++;
            st[top] = i;
        }
    }
    //栈不为空时循环
    while (top > -1) {
        //出栈
        i = st[top];
        top--;
        //输出顶点
        printf("%d ", i);
        //将所有相邻顶点的入度-1
        p = G->adjList[i].firstarc;
        while (p != NULL) {
            G->adjList[p->adjvex].count--;
            //入度为0的相邻结点进栈
            if (G->adjList[p->adjvex].count == 0) {
                top++;
                st[top] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
}