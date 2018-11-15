//
// Created by hanqing zhu on 2018/11/10.
//

#include "unit1_2.h"
#include "unit1_3.h"
#include "string.h"
#include "unit1_4.h"
#include "unit2_4.h"

void main() {

    //exa3_4
//    symmetry_exa3_4("I am a good boy!");
//    symmetry_exa3_4("aaabaaa");

    //exa3-5
//    char str[]="(ssdfafa(dfgvsdf())";
//    int n=match_exa3_5(str,strlen(str));
//    if (n==0){
//        printf("该表达式括号不匹配！");
//    } else{
//        printf("该表达式括号匹配！");
//    }


    //exa_unit1_4.1 表达式求值
    //可将exp改为键盘输入
//    char exp[]="(56-20)/(4+2)";
//    char exp[MaxSize];
//    scanf("%s",exp);
//    char postexp[MaxSize];
//    trans(exp,postexp);
//    printf("中缀表达式：%s\n",exp);
//    printf("后缀表达式：%s\n",postexp);
//    printf("表达式的值：%f\n",compvalue(postexp));
//    printf("强制转换：%d",(int)compvalue(postexp));

    //exa_unit1_4.2 求解迷宫问题
//    int mg[M+2][N+2]={
//            {1,1,1,1,1,1,1,1,1,1},
//            {1,0,0,1,0,0,0,1,0,1},
//            {1,0,0,1,0,0,0,1,0,1},
//            {1,0,0,0,0,1,1,0,0,1},
//            {1,0,1,1,1,0,0,0,0,1},
//            {1,0,0,0,1,0,0,0,0,1},
//            {1,0,1,0,0,0,1,0,0,1},
//            {1,0,1,1,1,0,1,1,0,1},
//            {1,1,0,0,0,0,0,0,0,1},
//            {1,1,1,1,1,1,1,1,1,1}
//    };
//    mgpath(1,1,M,N,mg);

    //exa_unit2_4.1 求解报数问题
//    int i,n=8;
//    printf("初始序列：\n");
//    for (i=1;i<=n;i++) {
//        printf("%d ",i);
//    }
//    printf("\n");
//    number(n);

    //exa_unit2_4.2 求解迷宫问题（队列方式）
    //运用广度优先搜索算法
    int mg[M+2][N+2]={
            {1,1,1,1,1,1,1,1,1,1},
            {1,0,0,1,0,0,0,1,0,1},
            {1,0,0,1,0,0,0,1,0,1},
            {1,0,0,0,0,1,1,0,0,1},
            {1,0,1,1,1,0,0,0,0,1},
            {1,0,0,0,1,0,0,0,0,1},
            {1,0,1,0,0,0,1,0,0,1},
            {1,0,1,1,1,0,1,1,0,1},
            {1,1,0,0,0,0,0,0,0,1},
            {1,1,1,1,1,1,1,1,1,1}
    };
    mgpathInQueue(1,1,M,N,mg);

}
