//
// Description: 树表的查找
// Created by hanqing zhu on 2018/11/29.
//

#ifndef CHAPTER9_MAIN_H
#define CHAPTER9_MAIN_H


/*------------------------------------------------------
 *
 * 关键字类型
 *
 * author： hanqing zhu 2018/11/29 15:44
 * -----------------------------------------------------*/
#define KeyType int

/*------------------------------------------------------
 *
 * 其它数据域
 *
 * author： hanqing zhu 2018/11/29 15:45
 * -----------------------------------------------------*/
typedef struct {

} InfoType;

/*------------------------------------------------------
 *
 * BST记录类型（binary search tree）
 * 
 * author： hanqing zhu 2018/11/29 15:46
 * -----------------------------------------------------*/
typedef struct node{
    //关键字项
    KeyType key;
    //增加的平衡因子
    int bf;
    //其它数据域
    InfoType data;
    //左、右孩子指针
    struct node *lchild,*rchild;
} BSTNode;



/*------------------------------------------------------
 *
 * 定义B-树的最大阶数
 *
 * author： hanqing zhu 2018/12/2 16:29
 * -----------------------------------------------------*/
#define MAXM 10
/*------------------------------------------------------
 *
 * B-树结点类型定义
 *
 * author： hanqing zhu 2018/12/2 11:20
 * -----------------------------------------------------*/
typedef struct b_node{
    //结点当前拥有的关键字的个数
    int keynum;
    //key[1..keynum]存放关键字，key[0]不用
    KeyType key[MAXM];
    //双亲结点指针
    struct b_node *parent;
    //孩子结点指针数组ptr[0..keynum]
    struct b_node *ptr[MAXM];
}BTNode;
/*------------------------------------------------------
 *
 * B-树的查找结果类型
 *
 * 当查找返回值的tag为0时表示查找失败，当tag为1时表示查找的结果
 * *pt结点的key[i]关键字。
 *
 * author： hanqing zhu 2018/12/2 16:38
 * -----------------------------------------------------*/
typedef struct {
    //指向找到的结点
    BTNode * pt;
    //1..m，在结点中的关键字序号
    int i;
    //1：查找成功，0：查找失败
    int tag;
}Result;




#endif //CHAPTER9_MAIN_H
