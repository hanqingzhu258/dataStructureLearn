//
// Description:
// Created by hanqing zhu on 2018/11/18.
//

#include <stddef.h>
#include "unit1.h"

/*------------------------------------------------------
 * 函数名：treeHeight_exa7_3
 *
 * 功  能：以孩子兄弟链作为树的存储结构，编写一个求树高度的递归算法
 *
 * 描  述：递归求解
 *
 * 参  数：t，树根节点指针
 *
 * 返回值：树的高度
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/18 16:59
 * -----------------------------------------------------*/
int treeHeight_exa7_3(TSBNode *t){
    int max=0,height;
    TSBNode *bro;
    //空树返回0
    if(t==NULL){
        return 0;
    }
    //没有孩子结点时返回1
    if (t->vp==NULL){
        return 1;
    }
    //指向第一个孩子结点
    bro=t->vp;
    //从所有孩子结点中找出高度最大的孩子结点
    while (bro!=NULL){
        height=treeHeight_exa7_3(bro);
        if (height>max){
            max=height;
        }
        //继续求其它兄弟的高度
        bro=bro->hp;
    }

    return(max+1);
}
