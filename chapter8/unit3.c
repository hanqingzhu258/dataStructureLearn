//
// Description: 图的遍历
// Created by hanqing zhu on 2018/11/23.
//

#include <stddef.h>
#include <stdio.h>
#include "unit3.h"

/*------------------------------------------------------
 *
 * 存储某一顶点是否已被访问过
 * 
 * author： hanqing zhu 2018/11/23 10:11
 * -----------------------------------------------------*/
int visited[MAXV] /*= {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0
}*/;

/*------------------------------------------------------
 * 函数名：DFS_AL
 *
 * 功  能：深度优先搜索遍历
 *
 * 描  述：从图中某个初始顶点v出发，首先访问初始顶点v，然后选择
 *        一个与顶点v相邻且没被访问过的顶点w为初始顶点，再从w
 *        出发进行深度优先搜索，直到图中与当前顶点v邻接的所有顶
 *        点都被访问过为止。
 *
 * 参  数：G，邻接表；
 *        v，顶点编号。
 *
 * 返回值：无
 *
 * 时间复杂度：O(n+e)
 *
 * author： hanqing zhu 2018/11/23 10:09
 * -----------------------------------------------------*/
void DFS_AL(ALGraph *G, int v) {
    ArcNode *p;
    //标记v已访问过
    visited[v] = 1;
    printf("%d ", v);
    //寻找v的一个未被访问过的邻接点
    p = G->adjList[v].firstarc;
    while (p != NULL) {
        //如果该邻接点未被访问过
        if (visited[p->adjvex] != 1) {
            //递归访问该临界点
            DFS_AL(G, p->adjvex);
        }
        //p指向顶点v的下一条弧的弧头结点
        p = p->nextarc;

    }

}

/*------------------------------------------------------
 *
 * 邻接矩阵的深度优先遍历
 *
 * author： hanqing zhu 2018/11/23 10:35
 * -----------------------------------------------------*/
void DFS_MAT(MGraph g, int v) {
    int i, n = g.n;
    //标记顶点v已被访问过
    visited[v] = 1;
    printf("%d ", v);
    //在邻接矩阵第v行寻找未被访问过的邻接顶点
    for (i = 0; i < n; i++) {
        if (g.edges[v][i] != 0 && visited[i] != 1) {
            //递归访问该邻接顶点
            DFS_MAT(g, i);
        }
    }
    //所有的邻接顶点都被访问过时退出
    if (i == n) {
        return;
    }
}

/*------------------------------------------------------
 * 函数名：initVisited
 *
 * 功  能：初始化visited数组
 *
 * 描  述：如果直接将visited设置为全局变量并初始化，会出现错误。。
 *
 * 参  数：visited，保存顶点是否已被访问过的数组；
 *        N，一维数组的大小。
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/23 17:01
 * -----------------------------------------------------*/
void initVisited(int *visited, int N) {
    int i;
    for (i = 0; i < N; i++) {
        visited[i] = 0;
    }
}

/*------------------------------------------------------
 * 函数名：BFS_AL
 *
 * 功  能：广度优先搜索遍历
 *
 * 描  述：首先访问初始点vi，接着访问v的所有未被访问过的邻接点v1，
 *        v2，...，vt，然后再按照v1，v2，...，vt的次序访问每一
 *        个顶点的所有未被访问的邻接点，以此类推，直到图中所有和
 *        初始点v有路径相通的顶点都被访问过为止。
 *
 * 参  数：G，邻接表；
 *        v，顶点编号。
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/26 10:13
 * -----------------------------------------------------*/
void BFS_AL(ALGraph *G, int v) {
    ArcNode *p;
    //定义循环队列并初始化
    int queue[MAXV], rear = 0, front = 0;
    //定义存放结点的访问标志的数组
    int w;
    //输出被访问的结点的编号
    printf("%2d ", v);
    //置已访问标记
    visited[v] = 1;
    //v进队
    rear = (rear + 1) % MAXV;
    queue[rear] = v;
    //若队列不空时循环
    while (front != rear) {
        //出队并赋给w
        front = (front + 1) % MAXV;
        w = queue[front];
        //找出与顶点w邻接的第一个顶点
        p = G->adjList[w].firstarc;
        while (p != NULL) {
            //若当前结点未被访问
            if (visited[p->adjvex] == 0) {
                //访问相邻结点
                printf("%2d ", p->adjvex);
                //置该顶点已被访问的标志
                visited[p->adjvex] = 1;
                //将该顶点进队
                rear = (rear + 1) % MAXV;
                queue[rear] = p->adjvex;
            }
            //找下一个相邻顶点
            p = p->nextarc;
        }
    }
    printf("\n");
}

/*------------------------------------------------------
 *
 * 邻接矩阵的广度优先遍历
 *
 * author： hanqing zhu 2018/11/26 10:31
 * -----------------------------------------------------*/
void BFS_MAT(MGraph g, int v) {
    int i, j, w;
    int queue[MAXV], rear = 0, front = 0;
    //访问v
    printf("%2d ", v);
    //置v为已访问标志
    visited[v] = 1;
    //将v进队
    rear = (rear + 1) % MAXV;
    queue[rear] = v;
    //队不为空时循环
    while (front != rear) {
        //出队一个元素并赋给w
        front = (front + 1) % MAXV;
        w = queue[front];
        //循环w的所有的相邻结点
        for (i = 1; i < g.n; i++) {
            //找w的未被访问过的结点
            if (g.edges[w][i] != 0 && visited[i] != 1) {
                //访问该结点并修改访问标志
                printf("%2d ", i);
                visited[i] = 1;
                //将该结点进队
                rear = (rear + 1) % MAXV;
                queue[rear] = i;
            }
        }
    }
    printf("\n");
}

/*------------------------------------------------------
 * 函数名：DFS_AL_NO
 *
 * 功  能：采用深度优先搜索遍历非连通无向图
 *
 * 描  述：
 *
 * 参  数：G，图的邻接表存储
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/26 10:54
 * -----------------------------------------------------*/
void DFS_AL_NO(ALGraph *G) {
    int i;
    for (i = 0; i < G->n; i++) {
        if (visited[i] == 0) {
            DFS_AL(G, i);
        }
    }
}

/*------------------------------------------------------
 * 函数名：BFS_AL_NO
 *
 * 功  能：采用广度优先搜索遍历非连通无向图
 *
 * 描  述：
 *
 * 参  数：G，图的邻接表存储
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/26 10:54
 * -----------------------------------------------------*/
void BFS_AL_NO(ALGraph *G) {
    int i;
    for (i = 0; i < G->n; i++) {
        if (visited[i] == 0) {
            BFS_AL(G, i);
        }
    }
}

/*------------------------------------------------------
 * 函数名：pathAll
 *
 * 功  能：假设图G采用邻接表存储，设计一个算法，输出图G中从顶点u到v的长
 *        度为l的所有简单路径。
 *
 * 描  述：
 *
 * 参  数：G，图的邻接表存储；
 *        u，目标起点；
 *        v，目标终点；
 *        l，目标长度；
 *        path，搜索路径；
 *        d，当前路径长度。
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/26 11:09
 * -----------------------------------------------------*/
void pathAll_exa8_4(ALGraph *G, int u, int v, int l, int path[], int d) {
    int i;
    ArcNode *p;
    visited[u] = 1;
    //将当前顶点添加到路径中
    d++;
    path[d] = u;
    //如果找到v，则输出path
    if (u == v && d == l) {
        printf("   ");
        for (i = 0; i <= d; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
    }
    p = G->adjList[u].firstarc;
    while (p != NULL) {
        if (visited[p->adjvex] == 0) {
            pathAll_exa8_4(G, p->adjvex, v, l, path, d);
        }
        p = p->nextarc;
    }
    //恢复环境：使该顶点可重新使用
    visited[u] = 0;
}

/*------------------------------------------------------
 * 函数名：DFSPath_exa8_5
 *
 * 功  能：假设图G采用邻接表存储，设计一个算法，求图中通过某顶点
 *        k的所有简单回路（若存在）。
 *
 * 描  述：
 *
 * 参  数：G，图的邻接表存储；
 *        u，目标起点；
 *        v，目标终点；
 *        l，目标长度；
 *        path，搜索路径；
 *        d，当前路径长度。
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/26 16:06
 * -----------------------------------------------------*/
void DFSPath_exa8_5(ALGraph *G,int u,int v,int path[],int d){
    ArcNode *p;
    int i,w;

    //将当前位置保存至path中并在visited数组中标记为已访问
    d++;
    path[d]=u;
    visited[u]=1;
    p=G->adjList[u].firstarc;

    while (p!=NULL){
        w=p->adjvex;
        //判断是否已找到一个简单回路
        //若是则输出该path路径
        if (w==v&&d>0){
            for (i=0;i<=d;i++){
                printf("%2d ",path[i]);
            }
            printf("%d\n",v);
        }
        //否则
        //寻找相邻的下一个结点，并递归调用
        //直到每一个顶点都已访问过
        if (visited[w]==0){
            DFSPath_exa8_5(G,w,v,path,d);
        }
        p=p->nextarc;
    }

    visited[u]=0;

}