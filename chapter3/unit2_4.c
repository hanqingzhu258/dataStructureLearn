//
// Created by hanqing zhu on 2018/11/12.
//

#include <stdio.h>
#include "unit2_4.h"
#include "main.h"
#include "unit2_2.h"

/*------------------------------------------------------
 * 函数名：number
 *
 * 功  能：设有n个人站成一排，从左向右的编号分别为1~n，现在从左往右报数
 *        “1,2,1,2，...”，数到1的人出列，数到2的立即站到队伍的最右端。
 *        报数过程反复进行，直到n个人都出列为止。给出他们的出列顺序。
 *
 * 描  述：使用队列实现
 *
 * 参  数：n，n个人从1~n编号
 *
 * 返回值：无
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void number(int n){
    int i;
    ElemType e;
    SqQueue q;
    q.front=q.rear=0;
    for (i=1;i<=n;i++){
        q.rear=(q.rear+1)%MaxSize;
        q.data[q.rear]=i;
    }
    printf("输出出队序列：\n");
    while (q.front!=q.rear){
        q.front=(q.front+1)%MaxSize;
        e=q.data[q.front];
        printf("%d ",e);
        if (q.front!=q.rear){
            q.front=(q.front+1)%MaxSize;
            e=q.data[q.front];
            q.rear=(q.rear+1)%MaxSize;
            q.data[q.rear]=e;
        }
    }
    printf("\n");
}

/*------------------------------------------------------
 * 函数名：mgpath
 *
 * 功  能：求解迷宫问题
 *
 * 描  述：使用队列求解
 *
 * 参  数：xi,yi:起始位置的坐标；
 *        xe,ye:出口位置的坐标。
 *
 * 返回值：
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int mgpathInQueue(int xi,int yi,int xe,int ye,int mg[M+2][N+2]){

    //分别为队首指针和队尾指针
    int front=-1,rear=-1;
    int i,j,find=0,di;
    //(xi,yi)进队
    rear++;
    Qu[rear].i=xi;
    Qu[rear].j=yi;
    Qu[rear].pre=-1;
    //将其赋值-1，以避免回过来重复搜索
    mg[xi][yi]=-1;
    //队列不为空且未找到路径时循环
    while(front<=rear&&!find){
        front++;
        i=Qu[front].i;
        j=Qu[front].j;
        //找到了出口，输出路径
        if (i==xe&&j==ye){
            find=1;
            print(front);
            return 1;
        }
        for(di=0;di<4;di++){
            switch (di){
                case 0:
                    i=Qu[front].i-1;
                    j=Qu[front].j;
                    break;
                case 1:
                    i=Qu[front].i;
                    j=Qu[front].j+1;
                    break;
                case 2:
                    i=Qu[front].i+1;
                    j=Qu[front].j;
                    break;
                case 3:
                    i=Qu[front].i;
                    j=Qu[front].j-1;
                    break;
            }
            if (mg[i][j]==0){
                rear++;
                Qu[rear].i=i;
                Qu[rear].j=j;
                //指向路径中上一个方块的下标
                Qu[rear].pre=front;
                mg[i][j]=-1;
            }
        }
    }
    return 0;
}

/*------------------------------------------------------
 * 函数名：print
 *
 * 功  能：输出迷宫路径
 *
 * 描  述：
 *
 * 参  数：
 *
 * 返回值：
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void print(int front){
    int k=front,j,ns=0;
    printf("\n");
    do{
        j=k;
        k=Qu[k].pre;
        Qu[j].pre=-1;
    }while (k!=0);
    printf("迷宫路径如下：\n");
    k=0;
    while (k<MaxSize){
        if (Qu[k].pre==-1){
            ns++;
            printf("\t(%d,%d)",Qu[k].i,Qu[k].j);
            if (ns%5==0){
                printf("\n");
            }
        }
        k++;
    }
    printf("\n");
}