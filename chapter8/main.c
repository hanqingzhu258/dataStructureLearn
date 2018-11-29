#include <stdio.h>

#include "unit2.h"
#include "unit3.h"
#include "unit4.h"
#include "unit5.h"
#include "unit6.h"

void main() {

    //initGraph-graph8.3-page199

    /*int n=5,es=5;
    int e[MAXV][MAXV]={
            {0,8,0,5,0},
            {0,0,3,0,0},
            {0,0,0,0,6},
            {0,9,0,0,0},
            {0,0,0,0,0}
    };
    int v[MAXV]={0,1,2,3,4};

    MGraph g;
    ALGraph *G;

    initMGraph(&g,e,v,n,es);
    matToList_exa8_2(g,&G);

    //深度优先遍历测试
    initVisited(visited,MAXV);
    DFS_MAT(g,0);
    printf("\n");
    initVisited(visited,MAXV);
    DFS_AL(G,0);
    printf("\n");

    //广度优先遍历测试
    initVisited(visited,MAXV);
    BFS_AL(G,0);
    initVisited(visited,MAXV);
    BFS_MAT(g,0);

    //非连通图遍历算法测试
    initVisited(visited,MAXV);
    BFS_AL_NO(G);
    initVisited(visited,MAXV);
    DFS_AL_NO(G);*/

    //test_pathAll_exa8_4
    /*int path[MAXV],u=1,v=4,d=3,i,j;
    MGraph g;
    ALGraph *G;
    g.n=5;
    g.e=6;
    int A[MAXV][MAXV]={
            {0,1,0,1,0},
            {1,0,1,0,0},
            {0,1,0,1,1},
            {1,0,1,0,1},
            {0,0,1,1,0}
    };
    for(i=0;i<g.n;i++){
        for (j=0;j<g.n;j++){
            g.edges[i][j]=A[i][j];
        }
    }
    matToList_exa8_2(g,&G);
    initVisited(visited,g.n);
    printf("图G:\n");
    dispAdj(G);
    printf("从%d到%d的所有长度为%d路径：\n",u,v,d);
    pathAll_exa8_4(G,u,v,d,path,-1);
    printf("\n");*/

    //test_DFSPath_exa8_5
    /*MGraph g;
    ALGraph *G;
    int path[MAXV];
    int V[MAXV]={0,1,2,3,4};
    int A[MAXV][MAXV]={
            {0,1,1,0,0},
            {0,0,1,0,0},
            {0,0,0,1,1},
            {0,0,0,0,1},
            {1,0,0,0,0}
    };
    initMGraph(&g,A,V,5,7);
    matToList_exa8_2(g,&G);
    printf("该图的邻接表如下：");
    dispAdj(G);
    printf("通过顶点0的所有回路如下：\n");
    initVisited(visited,g.n);
    DFSPath_exa8_5(G,0,0,path,-1);*/

    //test_unit4_prim
    /*MGraph g;
    int V[MAXV]={0,1,2,3,4,5};
    int E[MAXV][MAXV]={
            {0,6,1,5,INF,INF},
            {6,0,5,INF,3,INF},
            {1,5,0,5,6,4},
            {5,INF,5,0,INF,2},
            {INF,3,6,INF,0,6},
            {INF,INF,4,2,6,0}
    };
    initMGraph(&g,E,V,6,10);
    prim(g,0);*/

    //test_unit5_dijkstra
    /*MGraph g;
    int v[MAXV]={0,1,2,3,4,5,6};
    int a[MAXV][MAXV]={
            {0,4,6,6,INF,INF,INF},
            {INF,0,1,INF,7,INF,INF},
            {INF,INF,0,INF,6,4,INF},
            {INF,INF,2,0,INF,5,INF},
            {INF,INF,INF,INF,0,INF,6},
            {INF,INF,INF,INF,1,0,8},
            {INF,INF,INF,INF,INF,INF,0}
    };
    int u=0;
    initMGraph(&g,a,v,7,12);

    Dijkstra(g,u);*/

    //test_unit5_Floyd_exa8.9
    /*MGraph g;
    int v[MAXV]={0,1,2,3};
    int a[MAXV][MAXV]={
            {0,5,INF,7},
            {INF,0,4,2},
            {3,3,0,2},
            {INF,INF,1,0}
    };
    initMGraph(&g,a,v,4,8);
    Floyd(g);*/

    //test_unit6_topSort
    /*MGraph g;
    ALGraph *G;
    int v[MAXV]={0,1,2,3,4,5};
    int a[MAXV][MAXV]={
            {0,1,INF,INF,INF,INF},
            {INF,0,1,INF,INF,INF},
            {INF,INF,0,1,INF,INF},
            {INF,INF,INF,0,INF,INF},
            {INF,1,INF,INF,0,1},
            {INF,INF,INF,1,INF,0},
    };
    initMGraph(&g,a,v,6,6);
    matToList_exa8_2(g,&G);
    topSort(G);*/


}