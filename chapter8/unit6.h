//
// Description: 拓扑排序
// 设G=(V,E)是一个具有n个顶点的有向图，V中顶点序列v1，v2，...，vn称为一个拓扑序列，
// 当且仅当该顶点序列满足下列条件：若<vi,vj>是图中的边（即从vi到vj有一条路径），则
// 在序列中vi必须排在vj之间。
// Created by hanqing zhu on 2018/11/28.
//

#ifndef CHAPTER8_UNIT6_H
#define CHAPTER8_UNIT6_H


#include "unit2.h"

/*------------------------------------------------------
 *
 * 拓扑排序算法
 *
 * author： hanqing zhu 2018/11/28 16:46
 * -----------------------------------------------------*/
void topSort(ALGraph *G);



#endif //CHAPTER8_UNIT6_H
