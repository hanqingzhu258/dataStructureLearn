//
// Description: 
// Created by hanqing zhu on 2018/11/26.
//

#include <stdio.h>
#include "unit4.h"

/*------------------------------------------------------
 * 函数名：prim
 *
 * 功  能：求连通无向图的最小生成树
 *
 * 描  述：（1）初始化U={v}。以v到其它顶点的所有边为侯选边。
 *        （2）重复一下步骤（n-1）次，使得其它（n-1）个顶点
 *        被加入到U中。
 *         1）从侯选边中挑选权值最小的边输出，设该边在V-U中的顶
 *         点是vk，将vk加入U中，删除和vk关联的边；
 *         2）考察当前V-U中的所有顶点vj，修改侯选边：若（vk，vj）
 *         的权值小于原来和 vj关联的侯选边，则用（vk，vj）取代后
 *         者作为候选边。
 *
 * 参  数：g，带权连接矩阵；
 *        v，开始顶点的编号。
 *
 * 返回值：无
 *
 * 时间复杂度：O(n^2)
 *
 * author： hanqing zhu 2018/11/27 9:44
 * -----------------------------------------------------*/
void prim(MGraph g,int v){
    int closeSet[MAXV],lowcost[MAXV];
    int min;
    int i,j,k;
    //上述步骤（1）
    for(i=0;i<g.n;i++){
        lowcost[i]=g.edges[v][i];
        closeSet[i]=v;
    }
    //重复以下步骤（n-1）次
    for (i=1;i<g.n;i++){
        //找出侯选边中权值最小的边
        min=INF;
        for (j=0;j<g.n;j++){
            if(lowcost[j]!=0&&lowcost[j]<min){
                min=lowcost[j];
                k=j;
            }
        }
        printf("边（%d,%d）权为：%d\n",closeSet[k],k,min);
        //将上述顶点加入U中
        lowcost[k]=0;
        //更改候选边的权值
        for (j=0;j<g.n;j++){
            if(lowcost[j]!=0&&g.edges[k][j]<lowcost[j]){
                lowcost[j]=g.edges[k][j];
                closeSet[j]=k;
            }
        }
    }
}

/*------------------------------------------------------
 * 函数名：Kruskal
 *
 * 功  能：求连通无向图的最小生成树
 *
 * 描  述：（1）置U的初值等于V（即包含有G中的全部顶点），TE的初
 *             值为空集（即图T中每一个顶点都构成一个分量）。
 *        （2）将图G中的边按权值从小到大的顺序依次选取：若选取的
 *            边未使生成树T形成回路，则加入TE，否则舍弃，直到TE
 *            中包含（n-1）条边为止。
 *
 *         该算法可以从如下两方面进行改进：
 *          （1）将边集排序改为堆排序
 *          （2）采用并查集进行顶点合并，先通过MAKE_SET(t,n)进行
 *          并查集树的初始化，即每个顶点作为一个分离集合树（其编
 *          号为该顶点的编号），当找到一条最小边(u,v)时，求出两者
 *          所在分离集合树的编号，若不同则将u和v所在的分离集合树按
 *          秩合并。
 *          （改进算法在此略过：e*log2[e]）
 *
 * 参  数：g，图的邻接矩阵存储
 *
 * 返回值：无
 *
 * 时间复杂度：O(e^2)
 *
 * author： hanqing zhu 2018/11/27 10:16
 * -----------------------------------------------------*/
void Kruskal(MGraph g){
    //判断两个顶点之间是否连通
    int vset[MAXV];
    //存放所有边
    Edge E[MaxSize];
    int i,j,u1,v1,sn1,sn2,k;

    //由图g产生边集E
    k=0;
    for(i=0;i<g.n;i++){
        for (j=0;j<g.n;j++){
            if (g.edges[i][j]>0&&g.edges[i][j]<INF){
                //再加一个判断该边是否存在会不会更好？
                E[k].u=i;
                E[k].v=j;
                E[k].w=g.edges[i][j];
                k++;
            }
        }
    }
    //采用直接插入排序对E数组按权值递增排序
    insertSort(E,g.e);

    //初始化辅助数组，即使每个顶点都构成一个分量
    for (i=0;i<g.n;i++){
        vset[i]=i;
    }

    //k表示当前构造生成树的第几条边，初值为1
    k=1;
    //E中边的下标，初值为0
    j=0;
    //生成的边数小于n时循环
    while (k<g.n){
        u1=E[j].u;
        v1=E[j].v;
        sn1=vset[u1];
        sn2=vset[v1];
        //如果新增的边没有构成回路
        //该边为最小生成树的一条边
        if (sn1!=sn2){
            printf("（%d,%d）:%d\n",u1,v1,E[j].w);
            k++;
            //修改u1和v1集合编号为同一编号
            for (i=0;i<g.n;i++){
                if (vset[i]==sn2){
                    vset[i]==sn1;
                }
            }
        }
        //扫描下一条边
        j++;
    }
}

/*------------------------------------------------------
 * 函数名：insertSort
 *
 * 功  能：对边数组进行插入排序
 *
 * 描  述：
 *
 * 参  数：E，边数组；
 *        e，边数目。
 *
 * 返回值：无
 *
 * 时间复杂度：O(e^2)
 *
 * author： hanqing zhu 2018/11/27 16:51
 * -----------------------------------------------------*/
void insertSort(Edge E[MaxSize],int e){

}