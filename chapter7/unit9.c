//
// Description: 
// Created by hanqing zhu on 2018/11/22.
//

#include "unit9.h"

/*------------------------------------------------------
 * 函数名：MAKE_SET
 *
 * 功  能：并查集树的初始化
 *
 * 描  述：
 *
 * 参  数：t，并查集树数组
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/22 17:29
 * -----------------------------------------------------*/
void MAKE_SET(UFSTree t[]){
    int i;
    for(i=1;i<=N;i++){
        t[i].data=i;
        t[i].rank=0;
        t[i].parent=i;
    }
}

/*------------------------------------------------------
 * 函数名：FIND_SET
 *
 * 功  能：查找一个元素所处的集合
 *
 * 描  述：
 *
 * 参  数：t，并查集树数组；
 *        x，待查找元素。
 *
 * 返回值：元素所处的集合的“代表”
 *
 * 时间复杂度：O(log2[n])
 *
 * author： hanqing zhu 2018/11/22 17:30
 * -----------------------------------------------------*/
int FIND_SET(UFSTree t[],int x){
    if (x!=t[x].parent){
        return FIND_SET(t,t[x].parent);
    }else{
        return x;
    }
}

/*------------------------------------------------------
 * 函数名：UNION
 *
 * 功  能：两个元素各自所属集合的合并
 *
 * 描  述：
 *
 * 参  数：t，并查集树数组；
 *        x，y，待合并元素。
 *
 * 返回值：无
 *
 * 时间复杂度：O(log2[n])
 *
 * author： hanqing zhu 2018/11/22 17:31
 * -----------------------------------------------------*/
void UNION(UFSTree t[],int x,int y){
    x=FIND_SET(t,x);
    y=FIND_SET(t,y);
    if(t[x].rank>t[y].rank){
        t[y].parent=x;
    } else{
        t[x].parent=y;
        if (t[x].rank==t[y].rank){
            t[y].rank++;
        }
    }
}
