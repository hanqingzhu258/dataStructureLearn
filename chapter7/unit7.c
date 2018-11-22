//
// Description: 
// Created by hanqing zhu on 2018/11/22.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "unit7.h"

//全局变量
TBTNode *pre;

/*------------------------------------------------------
 * 函数名：thread_in
 *
 * 功  能：对二叉树b进行中序线索化
 *
 * 描  述：类似于中序遍历的递归算法，在p指针不为NULL时，先对p结点
 *        的左子树线索化。若p结点没有左孩子结点，则将其lchild指针
 *        线索化为指向其直接前驱结点pre，否则表示lchild指向其左孩
 *        子结点，将其ltag置为0；若pre结点的rchild指针为NULL，将
 *        其rchild指针线索化为指向其直接后继结点p，否则rchild表示
 *        指向其右孩子结点，将其rtag置为0，再将pre指向p；最后对p
 *        结点的右子树进行线索化。
 *
 * 参  数：p，二叉树结点
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/22 11:05
 * -----------------------------------------------------*/
void thread_in(TBTNode **p){
    if((*p)!=NULL){
        //左子树线索化
        thread_in(&(*p)->lchild);
        //此时p结点的左子树不存在或已线索化
        //左孩子不存在：进行直接前驱线索化
        if ((*p)->rchild==NULL){
            //建立当前结点的直接前驱线索
            (*p)->lchild=pre;
            (*p)->ltag=1;
        }
        //p结点的左子树已线索化
        else{
            (*p)->ltag=0;
        }
        //对pre的直接后继结点线索化
        if (pre->rchild==NULL){
            //建立直接前驱结点的直接后继线索
            pre->rchild=p;
            pre->rtag=1;
        }else{
            pre->rtag=0;
        }
        pre=p;
        //右子树线索化
        thread_in((*p)->rchild);
    }

}

/*------------------------------------------------------
 * 函数名：createThread_in
 *
 * 功  能：中序线索化二叉树
 *
 * 描  述：先创建头结点root，其rchild域为线索，lchild为链指针。
 *        将rchild指向b，如果b二叉树为空，则将其lchild指向自身；
 *        否则将root的lchild指向b结点，p指向b结点，pre指向root
 *        结点。再调用thread_in(b)对整个二叉树线索化。最后加入
 *        指向头结点的线索，并将头结点的rchild指针域线索化为指向
 *        最后一个结点（由于线索化直到p等于null为止，所以最后一个
 *        结点为pre）。
 *
 * 参  数：b，二叉树根结点指针。
 *
 * 返回值：线索二叉树头结点指针
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/22 10:59
 * -----------------------------------------------------*/
TBTNode * createThread_in(TBTNode *b){
    TBTNode * root;
    //创建头结点
    root=(TBTNode *)malloc(sizeof(TBTNode));
    root->ltag=0;
    root->rtag=1;
    root->rchild=b;
    if (b==NULL){
        root->lchild=root;
    }else{
        root->lchild=b;
        //pre是p的直接前驱结点，供加线索用
        pre=root;
        thread_in(&b);
        //最后处理，加入指向头结点的线索
        pre->rchild=root;
        pre->rtag=1;
        //头结点右线索化
        root->rchild=pre;
    }
    return root;
}

/*------------------------------------------------------
 * 函数名：thInOrder
 *
 * 功  能：遍历线索化二叉树
 *
 * 描  述：遍历某种次序的线索二叉树，就是从该次序下的开始结点出
 *        发，反复找到该结点在次序下的直接后继结点，直到终端结点。
 *
 * 参  数：tb，线索二叉树头结点指针
 *
 * 返回值：无
 *
 * 时间复杂度：O(n)
 *
 * author： hanqing zhu 2018/11/22 10:56
 * -----------------------------------------------------*/
void thInOrder(TBTNode *tb){
    //p指向根结点
    TBTNode *p=tb->lchild;
    while(p!=NULL){
        //找开始结点
        while(p->ltag==0){
            p=p->lchild;
        }
        //访问开始结点
        printf("%c ",p->data);
        while (p->rtag==1&&p->rchild!=tb){
            p=p->rchild;
            printf("%c ",p->data);
        }
        p=p->rchild;
    }
}