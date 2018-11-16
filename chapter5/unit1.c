//
// Created by hanqing zhu on 2018/11/15.
//

#include <stdio.h>
#include "unit1.h"
#include "main.h"

/*------------------------------------------------------
 * 函数名：josephus
 *
 * 功  能：约瑟夫问题
 *
 * 描  述：设有n个人站成一圈，其编号从1~n。从编号为1的人开始按
 *        顺时针方向“1,2,3,4，...”循环报数，数到m的人出列，
 *        然后从出列者的下一个人重新开始报数，数到m的人又出列，
 *        如此重复进行，直到n个人都出列为止。
 *        要求：输出这n个人的出列顺序。
 *
 * 参  数：n，总人数；
 *        m，出列标号。
 *
 * 返回值：无
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void josephus(int n, int m){
    int i,j,t;
    int p[MaxSize];
    //构建初始序列
    for(i=0;i<n;i++){
        p[i]=i+1;
    }
    //首次报数的起始位置
    t=0;
    printf("出列顺序为：");
    for(i=n;i>=1;i--){
        //t为出列者的标号
        t=(t+m-1)%i;
        //编号为t的元素出列
        printf("%d ",p[t]);
        //后面的元素前移一个位置
        for(j=t+1;j<i;j++){
            p[j-1]=p[j];
        }
    }
    printf("\n");
}