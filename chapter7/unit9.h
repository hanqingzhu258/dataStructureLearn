//
// Description: 用并查集求解等价问题
// Created by hanqing zhu on 2018/11/22.
//

#ifndef CHAPTER7_UNIT9_H
#define CHAPTER7_UNIT9_H

typedef struct node{
    int data;
    //秩
    int rank;
    int parent;
}UFSTree;

#define N 50

/*------------------------------------------------------
 *
 * 并查集树的初始化
 *
 * author： hanqing zhu 2018/11/22 17:33
 * -----------------------------------------------------*/
void MAKE_SET(UFSTree t[]);

/*------------------------------------------------------
 *
 * 查找一个元素所处的集合
 *
 * author： hanqing zhu 2018/11/22 17:33
 * -----------------------------------------------------*/
int FIND_SET(UFSTree t[],int x);

/*------------------------------------------------------
 *
 * 两个元素各自所属集合的合并
 *
 * author： hanqing zhu 2018/11/22 17:33
 * -----------------------------------------------------*/
void UNION(UFSTree t[],int x,int y);


#endif //CHAPTER7_UNIT9_H
