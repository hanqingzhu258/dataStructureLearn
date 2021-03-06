//
// Description: 最短路径：图中某一顶点到其余各顶点的最短路径、图中每一对顶点之间的最短路径
// Created by hanqing zhu on 2018/11/27.
//

#ifndef CHAPTER8_UNIT5_H
#define CHAPTER8_UNIT5_H


#include "unit2.h"
/*------------------------------------------------------
 *
 * 求图中某一点到其它顶点的最短路径长度
 *
 * author： hanqing zhu 2018/11/27 17:23
 * -----------------------------------------------------*/
/*------------------------------------------------------
 *
 * Dijkstra算法
 *
 * author： hanqing zhu 2018/11/27 15:51
 * -----------------------------------------------------*/
void Dijkstra(MGraph g,int v);

/*------------------------------------------------------
 *
 * 输出顶点到其余顶点的最短路径
 *
 * author： hanqing zhu 2018/11/27 16:22
 * -----------------------------------------------------*/
void dispPath(int dist[],int path[],int s[],int n,int v);

/*------------------------------------------------------
 *
 * 输出源点到某一顶点的最短路径
 *
 * author： hanqing zhu 2018/11/27 16:30
 * -----------------------------------------------------*/
void vpPath(int path[],int v,int x);



/*------------------------------------------------------
 *
 * 求每对顶点之间的最短路径
 *
 * author： hanqing zhu 2018/11/27 17:23
 * -----------------------------------------------------*/

/*------------------------------------------------------
 *
 * 弗洛伊德算法
 *
 * author： hanqing zhu 2018/11/28 16:06
 * -----------------------------------------------------*/
void Floyd(MGraph g);

void dispPath_Floyd(int A[][MAXV],int path[][MAXV],int n);

void pPath_Floyd(int path[][MAXV],int u,int v);

#endif //CHAPTER8_UNIT5_H
