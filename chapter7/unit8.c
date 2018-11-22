//
// Description: 
// Created by hanqing zhu on 2018/11/22.
//

#include "unit8.h"

/*------------------------------------------------------
 * 函数名：createHT
 *
 * 功  能：构造哈夫曼树
 *
 * 描  述：n个结点叶子（存放在ht[0]~ht[n-1]中）只有data和weight
 *        域值，先将所有2n-1个结点的parent、lchild、rchild域置
 *        为初值-1。处理每个非叶子节点ht[i]（存放在ht[n]~ht[2n-2]中）
 *        ：从ht[0]~ht[i-1]中找出根结点（即其parent域为-1）最小的
 *        两个结点ht[lnode]和ht[rnode]，将它们作为ht[i]的左右子树，
 *        ht[lnode]和ht[rnode]的双亲结点置为ht[i]，并且
 *        ht[i].weight=ht[lnode].weight+ht[rnode].weight。
 *        如此这样直到2n-1个非叶子节点处理完毕。
 *
 * 参  数：ht，存放哈夫曼树；
 *        n，叶子结点的个数。
 *
 * 返回值：无
 *
 * 时间复杂度：O(n^2)
 *
 * author： hanqing zhu 2018/11/22 16:26
 * -----------------------------------------------------*/
void createHT(HTNode ht[],int n){
    int i,j,k,lnode,rnode;
    double min1,min2;
    //所有结点的相关域值初值-1
    for(i=0;i<2*n-1;i++){
        ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
    }
    //构造哈夫曼树
    for(i=n;i<2*n-1;i++){
        min1=min2=32767;
        //lnode和rnode为最小权重的两个结点位置
        lnode=rnode=-1;
        //在ht中找权值最小的两个结点位置
        for(j=0;j<=i-1;j++){
            //只在尚未构造二叉树的结点中查找
            if (ht[j].parent==-1){
                if(ht[j].weight<min1){
                    min2=min1;rnode=lnode;
                    min1=ht[j].weight;lnode=j;
                }else if(ht[j].weight<min2){
                    min2=ht[j].weight;
                    rnode=j;
                }
            }
        }
        ht[i].weight=ht[lnode].weight+ht[rnode].weight;
        //ht[i]作为双亲结点
        ht[i].lchild=lnode;
        ht[i].rchild=rnode;
        ht[lnode].parent=i;
        ht[rnode].parent=i;
    }
}

/*------------------------------------------------------
 * 函数名：createHCode
 *
 * 功  能：根据哈夫曼树求哈弗曼编码
 *
 * 描  述：对于当前的叶子结点ht[i]，先将对应的哈夫曼编码hcd[i]的
 *        start域值置初值n，找其双亲结点ht[f]，若当前结点是双亲
 *        结点的左孩子结点，则在hcd[i]的cd数组中添加0，若当前结点
 *        是双亲结点的右孩子结点，则在hcd[i]的cd数组中添加1，并将
 *        start域减1。再对双亲结点进行同样的操作，如此这样直到无
 *        双亲结点即到达根结点，最后让start指向哈夫曼编码最开始的
 *        字符。
 *
 * 参  数：ht，哈夫曼树；
 *        hcd，叶子结点对应的哈夫曼编码；
 *        n，叶子结点的个数。
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/22 16:55
 * -----------------------------------------------------*/
void createHCode(HTNode ht[],HCode hcd[],int n){
    int i,f,c;
    HCode hc;
    //根据哈夫曼树求哈夫曼编码
    for (i=0;i<n;i++){
        hc.start=n;
        c=i;
        f=ht[i].parent;
        //循环直到无双亲结点即到达树根结点
        while (f!=-1){
            //当前结点是双亲结点的左孩子结点
            if(ht[f].lchild==c){
                hc.cd[hc.start--]='0';
            }
            //当前结点是双亲结点的右孩子结点
            else{
                hc.cd[hc.start--]='1';
            }
            //再对双亲结点进行同样的操作
            c=f;
            f=ht[f].parent;
        }
        hc.start++;
        hcd[i]=hc;
    }
}