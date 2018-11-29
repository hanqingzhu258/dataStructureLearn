//
// Description: 最短路径问题
// Created by hanqing zhu on 2018/11/27.
//

#include <stdio.h>
#include "unit5.h"


/*------------------------------------------------------
 * 函数名：Dijkstra
 *
 * 功  能：求图中某一点到其它点的最短路径
 *
 * 描  述：
 *
 * 参  数：g，图的邻接矩阵存储；
 *        v，源点。
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/27 15:52
 * -----------------------------------------------------*/
void Dijkstra(MGraph g,int v){
    //标记顶点是否已找到最短路径：0（U：未找到）或 1（S：已找到）
    int s[MAXV];
    //保存源点到某顶点的当前最短路径
    int dist[MAXV];
    //保存源点到某顶点的最短路径中，该顶点在路径上的前一顶点的编号
    int path[MAXV];
    //循环次数：n-1次（将U中的全部顶点添加到S中）
    int i,j,k,min,tl;
    //
    //初始化s，将源点添加到s中
    for (i=0;i<g.n;i++){
        s[i]=0;
    }
    s[v]=1;
    //距离初始化dist
    for (i=0;i<g.n;i++){
        dist[i]=g.edges[v][i];
    }
    //路径初始化path
    for(i=0;i<g.n;i++){
        if(g.edges[v][i]<INF){
            path[i]=v;
        }else{
            path[i]=-1;
        }
    }
    //循环n-1次，将U中顶点全部添加到S中，每次添加一个
    for(i=1;i<g.n;i++){
        //找出U中当前路径最短的
        min=INF;
        for (j=0;j<g.n;j++){
            if(s[j]==0&&dist[j]<min){
                min=dist[j];
                k=j;
            }
        }
        //将k添加至s中
        s[k]=1;
        //修改U中顶点的最短路径：v->k->x与v->x的比较
        for (j=0;j<g.n;j++){
            if(s[j]==0){
                tl=dist[k]+g.edges[k][j];
                if(g.edges[k][j]<INF&&tl<dist[j]){
                    dist[j]=tl;
                    path[j]=k;
                }
            }
        }
    }
    dispPath(dist,path,s,g.n,v);

}

/*------------------------------------------------------
 * 函数名：dispPath
 *
 * 功  能：输出顶点到其余顶点的最短路径
 *
 * 描  述：
 *
 * 参  数：dist，源点到某顶点的当前最短路径；
 *        path，顶点在源点到该点的最短路径上的前一顶点的编号；
 *        s，标记顶点是否已找到最短路径；
 *        n，顶点个数；
 *        v，源点编号。
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/27 16:23
 * -----------------------------------------------------*/
void dispPath(int dist[],int path[],int s[],int n,int v){
    int i;
    for(i=0;i<n;i++){
        if (s[i]==1){
            printf("%d->%d的最短路径长度为：%d，路径为：%d",v,i,dist[i],v);
            vpPath(path,v,i);
            printf("\n");
        }else{
            printf("%d->%d无路径",v,i);
            printf("\n");
        }

    }
}

/*------------------------------------------------------
 * 函数名：vpPath
 *
 * 功  能：输出源点到某一顶点的最短路径
 *
 * 描  述：
 *
 * 参  数：path，顶点在源点到该点的最短路径上的前一顶点的编号；
 *        n，顶点个数；
 *        v，源点编号；
 *        x，终点编号。
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/27 16:32
 * -----------------------------------------------------*/
void vpPath(int path[],int v,int x){
    //递归出口
    if (path[x]!=v){
        vpPath(path,v,path[x]);
    }
    printf("->%d",x);
}

/*------------------------------------------------------
 * 函数名：Floyd
 *
 * 功  能：求每对顶点之间的最短路径
 *
 * 描  述：
 *
 * 参  数：g，图的邻接矩阵表示
 *
 * 返回值：无
 *
 * 时间复杂度：O(n^3)
 *
 * author： hanqing zhu 2018/11/28 16:07
 * -----------------------------------------------------*/
void Floyd(MGraph g){
    int A[MAXV][MAXV],path[MAXV][MAXV];
    int i,j,k;
    for (i=0;i<g.n;i++){
        for (j=0;j<g.n;j++){
            A[i][j]=g.edges[i][j];
            path[i][j]=-1;
        }
    }
    for (k=0;k<g.n;k++){
        for (i=0;i<g.n;i++){
            for(j=0;j<g.n;j++){
                if (A[i][j]>A[i][k]+A[k][j]){
                    A[i][j]=A[i][k]+A[k][j];
                    path[i][j]=k;
                }
            }
        }
    }
    dispPath_Floyd(A,path,g.n);
}

/*------------------------------------------------------
 * 函数名：dispPath_Floyd
 *
 * 功  能：输出每两个顶点之间的最短路径
 *
 * 描  述：
 *
 * 参  数：A，保存两点间的最短路径的长度；
 *        path，保存从顶点i到j的最短路径上前一个结点的编号；
 *        n，顶点的个数。
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/28 16:19
 * -----------------------------------------------------*/
void dispPath_Floyd(int A[][MAXV],int path[][MAXV],int n){
    int i,j;
    for(i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (A[i][j]==INF){
                if (i!=j){
                    printf("从%d到%d没有路径\n",i,j);
                }
            }else{
                printf("从%d到%d的路径长度为：%d，路径为：",i,j,A[i][j]);
                printf("%d",i);
                pPath_Floyd(path,i,j);
                printf("\n");
            }
        }
    }
}

/*------------------------------------------------------
 * 函数名：pPath_Floyd
 *
 * 功  能：输出某两顶点间的最短路径
 *
 * 描  述：
 *
 * 参  数：path，保存从顶点i到j的最短路径上前一个结点的编号；
 *        u，源点编号；
 *        v，终点编号。
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/28 16:19
 * -----------------------------------------------------*/
void pPath_Floyd(int path[][MAXV],int u,int v){

    int k;

    //递归出口
    if (path[u][v]==-1){
        printf("->%d",v);
    }else{
        k=path[u][v];
        pPath_Floyd(path,u,k);
        pPath_Floyd(path,k,v);
    }
}