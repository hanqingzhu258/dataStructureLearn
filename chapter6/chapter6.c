//
// Description:
// Created by hanqing zhu on 2018/11/17.
//

#include <stddef.h>
#include <stdio.h>
#include "chapter6.h"


//存放各皇后所在的行号
int q[N];
//记录解个数
int count=0;

/*------------------------------------------------------
 * 函数名：fun
 *
 * 功  能：求n!(n为正整数)
 *
 * 描  述：直接递归，尾递归
 *
 * 参  数：n，待求正整数
 *
 * 返回值：n!
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int fun(int n){
    if(n==1){
        return 1;
    }else{
        return (fun(n-1)*n);
    }
}

/*------------------------------------------------------
 * 函数名：fib
 *
 * 功  能：求Fibonacci数列
 *
 * 描  述：定义是递归的
 *
 * 参  数：n，Fibonacci数列的第n项
 *
 * 返回值：Fibonacci数列的第n项的值
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int fib(int n){
    if (n==1||n==2){
        return 1;
    }else{
        return(fib(n-1)+fib(n-2));
    }
}

/*------------------------------------------------------
 * 函数名：sum
 *
 * 功  能：求一个不带头结点的单链表head的所有data域（假设为int型）之和
 *
 * 描  述：
 *
 * 参  数：head，单链表的第一个元素指针
 *
 * 返回值：单链表所有data域之和
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int sum(LinkList *head){
    if (head==NULL){
        return 0;
    }else{
        return (head->data+sum(head->next));
    }
}

/*------------------------------------------------------
 * 函数名：Hanio
 *
 * 功  能：将n个盘片从X通过Y移动到Z
 *
 * 描  述：规则：1.每次只能移动一个盘片
 *             2.不能将大直径的放到小直径上面
 *        分析：假设X上面有n的盘子，如果已经把n-1个盘子搬到了Y上面，
 *             我只需要将X盘子放到Z上面，第n个盘子的直径是最大的，
 *             在以后的搬动过程中是不需要动Z上第n个盘子的。以上搬
 *             动n个盘子的问题，就变为搬n-1个盘子的问题。如此规则
 *             执行下去，最后只有一个圆盘的时候，问题直接解决了。
 *
 *        思路：1.将n-1个盘子从X搬到Y上面（借助Z）
 *             2.将X柱子第N个盘子搬到Z柱子上面
 *             3.将Y柱子上n-1个盘子搬到Z柱子上面（借助X）
 *
 * 参  数：n，不同直径的盘子的个数；
 *        X,Y,Z,塔的编号。
 *
 * 返回值：无
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void Hanio(int n,char X, char Y, char Z){
    if (n==1){
        printf("\t将第%d个盘片从%c移动到%c\n",n,X,Z);
    }else{
        Hanio(n-1,X,Z,Y);
        printf("\t将第%d个盘片从%c移动到%c\n",n,X,Z);
        Hanio(n-1,Y,X,Z);
    }
}

/*------------------------------------------------------
 * 函数名：f
 *
 * 功  能：求实数数组A[0..n-1]中的最小值
 *
 * 描  述：假设f(A,i)函数求数组元素A[0]~A[i]中的最小值。当i=0时，
 *        有f(A,i)=A[0];假设f(A,i-1)已求出，则
 *        f(A,i)=min(f(A,i-1),A[i]),其中min()为求两个值较小值函数
 *
 * 参  数：A，实数数组；
 *        i,数组元素的个数。
 *
 * 返回值：数组A[0..i]的最小值
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/17 17:06
 * -----------------------------------------------------*/
float f(float A[],int i){
    float m;
    if (i==0){
        return A[0];
    }else{
        m=f(A,i-1);
        if (m>A[i]){
            return A[i];
        }else{
            return m;
        }
    }
}

/*------------------------------------------------------
 * 函数名：invert
 *
 * 功  能：利用串的基本运算写出对串求逆的递归算法
 *
 * 描  述：对于s="s1s2s3...sn"的串，假设"s2s3...sn"已求出其
 *        逆串即f(subStr(s,2,strLength(s)-1)),再将s1（为
 *        subStr(s,1,1)）连接到最后即得到s的逆串。
 *
 * 参  数：s，待求逆串
 *
 * 返回值：逆串
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/17 17:21
 * -----------------------------------------------------*/
SqString invert(SqString s){
    SqString s1,s2;
    if (strLength(s)>0){
        s1=invert((subStr(s,2,strLength(s)-1)));
        s2=concat(s1,subStr(s,1,1));
    }else{
        strCopy(&s2,s);
    }
    return s2;
}

/*------------------------------------------------------
 * 函数名：max_exa6_3
 *
 * 功  能：求顺序表{a1,a2,...,an}中的最大元素
 *
 * 描  述：将线性表分解成{a1,a2,...,am}和{a(m+1),...,an}两个
 *        子表，分别求得子表中的最大元素ai和aj，比较ai和aj中的
 *        大者，就可以求得整个线性表的最大元素。而求解子表中的最
 *        大元素方法与总表相同，即再分别将它们分成两个更小的子表，
 *        如此不断分解，直到表中只有一个元素为止（当只有一个元素
 *        时，该元素便是该表的最大元素）。
 *
 *
 * 参  数：L，顺序表
 *        i,j子表的上下界
 *
 * 返回值：顺序表的最大值
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/18 10:39
 * -----------------------------------------------------*/
ElemType max_exa6_3(SqList L, int i, int j){
    int mid;
    ElemType max,max1,max2;
    if (i==j){
        max=L.data[i];
    }else{
        mid=i+(j-i)/2;
        max1=max_exa6_3(L,i,mid);
        max2=max_exa6_3(L,mid+1,j);
        max=(max1>max2)?max1:max2;
    }
    return max;
}

/*------------------------------------------------------
 * 函数名：皇后问题
 *
 * 功  能：递归求解
 *
 * 描  述：在nxn的方格棋盘上，放置n个皇后，要求每个皇后不同行、
 *        不同列、不同左右对角线。
 *
 * 参  数：
 *
 * 返回值：
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/18 11:27
 * -----------------------------------------------------*/
void print(int n){
    int i;
    count++;
    printf("第%d个解：",count);
    for (i=1;i<=n;i++){
        printf("%d ",q[i]);
    }
    printf("\n");
}

int find(int i,int k){
    int j;
    j=1;
    while(j<k){
        if(q[j]==i||(abs(q[j]-i)==abs(j-k))){
            return 0;
        }
        j++;
    }
    return 1;
}

void place(int k,int n){
    if (k>n){
        print(n);
    }else{
        for(int i=1;i<=n;i++){
            if (find(i,k)){
                q[k]=i;
                place(k+1,n);
            }
        }
    }
}

