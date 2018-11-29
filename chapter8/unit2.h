//
// Description: 图的存储结构
// Created by hanqing zhu on 2018/11/22.
//

#ifndef CHAPTER8_UNIT2_H
#define CHAPTER8_UNIT2_H

#include "main.h"

/*------------------------------------------------------
 *
 * 邻接矩阵存储方法
 * 特点：
 *      1.图的邻接矩阵表示是惟一的
 *      2.无向图的邻接矩阵一定是一个对称矩阵。因此按照压缩存储的思想，
 * 在具体存放邻接矩阵时只需存放上（或下）三角形阵的元素即可。
 *      3.不带权的有向图的邻接矩阵一般是稀疏矩阵，因此，当图的顶点较
 * 多时，可以采用三元组表的方法存储邻接矩阵。
 *      4.对于无向图，邻接矩阵的第i行（或第i列）非零元素（或非00元素）
 * 的个数正好是第i个顶点vi的度。
 *      5.对于有向图，邻接矩阵的第i行（或第i列）非零元素（或非00元素）
 * 的个数正好是第i个顶点vi的出度（入度）。
 *      6.用邻接矩阵方法存储图，很容易确定图中任意两个顶点之间是否有
 * 边相连。但是要确定图中有多少条边，则必须按行和按列对每个元素进行检
 * 测，所花费的时间代价很大。这是用邻接矩阵存储图的局限性。
 *
 * author： hanqing zhu 2018/11/22 20:22
 * -----------------------------------------------------*/
//邻接矩阵的数据类型定义
typedef struct {
    //顶点编号
    int no;
    //顶点其他信息
    InfoType info;
}VertexType;

//图的定义
typedef struct {
    //邻接矩阵的边数组
    int edges[MAXV][MAXV];
    //顶点数、弧数
    int n,e;
    //存放顶点信息
    VertexType vexs[MAXV];
}MGraph;

/*------------------------------------------------------
 *
 * 邻接表存储方法
 * 特点：
 *      1.邻接表表示不唯一。这是因为在每个顶点对应的单链表中，各
 * 边结点的链接次序可以是任意的，取决于建立邻接表的算法以及边的输
 * 入次序。
 *      2.对于有n个顶点和e条边的无向图，其邻接表有n个顶点结点和
 * 2e个边结点。显然，对于稀疏图，邻接表比邻接矩阵要节省空间。
 *      3.对于无向图，邻接表的顶点vi对应的第i个链表的边结点数正
 * 好是顶点vi的度。
 *      4.对于有向图，邻接表的顶点vi对应的第i个链表的边结点数目
 * 仅仅是vi的出度。其入度为邻接表中所有adjvex域值为i的边结点数目。
 *
 * author： hanqing zhu 2018/11/22 20:47
 * -----------------------------------------------------*/
//邻接表存储定义如下：
//弧的结点结构类型
typedef struct ANode{
    //该弧的终点位置
    int adjvex;
    //指向下一条弧的指针
    struct ANode *nextarc;
    //该弧的相关信息
    InfoType info;
}ArcNode;

//邻接表头结点的类型
typedef struct {
    //顶点信息
    VertexType data;
    //指向第一条弧
    ArcNode *firstarc;
    //存放顶点入度
    int count;
}VNode;

//邻接表类型
typedef VNode AdjList[MAXV];

//图的类型
typedef struct {
    //邻接表
    AdjList adjList;
    //图中顶点数n和边数e
    int n,e;
}ALGraph;

/*------------------------------------------------------
 *
 * 对于具有n个结点的无向图：将一个邻接矩阵转换为邻接表
 *
 * author： hanqing zhu 2018/11/22 21:07
 * -----------------------------------------------------*/
void matToList_exa8_2(MGraph g,ALGraph **G);

/*------------------------------------------------------
 *
 * 对于具有n个结点的无向图：将一个邻接表转换为邻接矩阵
 *
 * author： hanqing zhu 2018/11/22 21:27
 * -----------------------------------------------------*/
void listToMat(ALGraph *G,MGraph *g);

/*------------------------------------------------------
 *
 * 根据二维数组e和数组v初始化邻接矩阵图
 *
 * author： hanqing zhu 2018/11/23 10:41
 * -----------------------------------------------------*/
void initMGraph(MGraph *g,int e[MAXV][MAXV],int v[MAXV],int n,int es);

/*------------------------------------------------------
 *
 * 输出邻接表
 *
 * author： hanqing zhu 2018/11/26 15:54
 * -----------------------------------------------------*/
void dispAdj(ALGraph *G);


#endif //CHAPTER8_UNIT2_H