//
// Description: 
// Created by hanqing zhu on 2018/11/21.
//

#include <stdlib.h>
#include "unit6.h"

/*------------------------------------------------------
 * 函数名：createBT1_unit6
 *
 * 功  能：根据先序序列和中序序列构造二叉树
 *
 * 描  述：
 *
 * 参  数：pre，先序序列；
 *        in，中序序列；
 *        n，结点的个数。
 *
 * 返回值：二叉树根结点指针
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/21 20:44
 * -----------------------------------------------------*/
BTNode * createBT1_unit6(char *pre,char *in,int n){
    char ch1,lpre[n],lin[n],rpri[n],rin[n];
    int index1,index2,i;
    BTNode *p;
    //根据先序序列找到根结点
    index1=0;
    ch1=pre[index1];
    p=(BTNode *)malloc(sizeof(BTNode));
    p->data=ch1;
    //递归出口
    if (n<=1){
        p->lchild=p->rchild=NULL;
        return p;
    }
    //在中序序列中根据根结点找到左右子树
    for(index2=0; index2<n;index2++){
        if(in[index2]==ch1){
            break;
        }
    }
    //此时index2的值即为中序中根结点的下标
    //左子树中序序列
    for (i=0;i<index2;i++){
        lin[i]=in[i];
    }
    //右子树中序序列
    for (i=index2+1;i<n;i++){
        rin[i-index2-1]=in[i];
    }
    //左子树先序序列
    for(i=index1+1;i<=index1+index2;i++){
        lpre[i-index1-1]=pre[i];
    }
    //右子树先序序列
    for(i=index1+index2+1;i<n;i++){
        rpri[i-index1-index2-1]=pre[i];
    }
    //根据左右子树的先序和中序重复以上过程
    p->lchild=createBT1_unit6(lpre,lin,index2);
    p->rchild=createBT1_unit6(rpri,rin,n-1-index2);
    return p;
}
/*------------------------------------------------------
 *
 * 该算法比上算法在左右子树先序和中序序列的构造上有所优化
 * 优化的关键在于指针的灵活运用
 * 指针可以进行运算
 *
 * author： hanqing zhu 2018/11/21 22:11
 * -----------------------------------------------------*/
BTNode * createBT1_unit6_book(char *pre, char *in,int n){
    /*
     * pre存放先序序列，in存放中序序列，n为二叉树结点个数，
     * 本算法执行后返回构造的二叉链的根节点指针。
     **/
    BTNode *s;
    char *p;
    int k;
    if (n<=0){
        return NULL;
    }
    //创建二叉树结点
    s=(BTNode *)malloc(sizeof(BTNode));
    s->data=*pre;
    for(p=in;p<in+n;p++){
        //pre指向根结点
        if (*p==*pre){
            //在in中找到后退出
            break;
        }
    }
    //确定根节点在in中的位置
    k=p-in;
    //递归构造左子树
    s->lchild=createBT1_unit6_book(pre+1,in,k);
    //递归构造右子树
    s->rchild=createBT1_unit6_book(pre+k+1,p+1,n-k-1);
    return s;
}

/*------------------------------------------------------
 * 函数名：createBT2_unit6_book
 *
 * 功  能：根据先序序列和中序序列构造二叉树
 *
 * 描  述：
 *
 * 参  数：post，后序序列；
 *        in，中序序列；
 *        n，结点的个数。
 *
 * 返回值：二叉树根结点指针
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/21 22:15
 * -----------------------------------------------------*/
BTNode * createBT2_unit6_book(char *post, char *in,int n){
    BTNode *s;
    char r,*p;
    int k;
    if (n<=0){
        return NULL;
    }
    //根结点值
    r=*(post+n-1);
    //创建二叉树结点s
    s=(BTNode *)malloc(sizeof(BTNode));
    s->data=r;
    //在in中查找根结点
    for (p=in;p<in+n;p++){
        if (*p==r){
            break;
        }
    }
    //k为根结点在in中的下标
    k=p-in;
    s->lchild=createBT2_unit6_book(post,in,k);
    s->rchild=createBT2_unit6_book(post+k,p+1,n-k-1);
    return s;
}

/*------------------------------------------------------
 * 函数名：trans_unit6
 *
 * 功  能：将二叉树的顺序存储结构转换成二叉链存储结构
 *
 * 描  述：
 *
 * 参  数：a，顺序树；
 *        i，结点索引。
 *
 * 返回值：二叉树根结点指针
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/21 22:40
 * -----------------------------------------------------*/
BTNode * trans_unit6(SqBTree a, int i){
    BTNode *b;
    if (i>MaxSize){
        return NULL;
    }
    if (a[i]=='#'){
        return NULL;
    }
    b=(BTNode *)malloc(sizeof(BTNode));
    b->data=a[i];
    b->lchild=trans_unit6(a,2*i);
    b->rchild=trans_unit6(a,2*i+1);
    return b;
}