//
// Description:二叉树的遍历
// Created by hanqing zhu on 2018/11/20.
//

#include <stddef.h>
#include <stdio.h>
#include "unit5.h"


/*------------------------------------------------------
 * 函数名：preOrder
 *
 * 功  能：先序遍历二叉树
 *
 * 描  述：（1）访问根结点；
 *        （2）先序遍历左子树；
 *        （3）先序遍历右子树。
 *
 * 参  数：b，二叉树根结点指针
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/20 9:43
 * -----------------------------------------------------*/
void preOrder(BTNode *b) {
    if (b == NULL) {
        return;
    }
    //输出该结点的值
    printf("%c ", b->data);
    //先序遍历左子树
    preOrder(b->lchild);
    //先序遍历右子树
    preOrder(b->rchild);
}

/*------------------------------------------------------
 * 函数名：inOrder
 *
 * 功  能：中序遍历二叉树
 *
 * 描  述：（1）中序遍历左子树
 *        （2）访问根结点
 *        （3）中序遍历右子树
 *
 * 参  数：b，二叉树根结点指针
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/20 9:51
 * -----------------------------------------------------*/
void inOrder(BTNode *b) {
    if (b == NULL) {
        return;
    }
    //遍历左子树
    inOrder(b->lchild);
    //访问根结点
    printf("%c ", b->data);
    //遍历右子树
    inOrder(b->rchild);
}

/*------------------------------------------------------
 * 函数名：postOrder
 *
 * 功  能：后序遍历二叉树
 *
 * 描  述：（1）后序遍历左子树
 *        （2）后序遍历右子树
 *        （3）访问根结点
 *
 * 参  数：b，二叉树根结点指针
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/20 9:57
 * -----------------------------------------------------*/
void postOrder(BTNode *b) {
    if (b == NULL) {
        return;
    }
    //遍历左子树
    postOrder(b->lchild);
    //遍历右子树
    postOrder(b->rchild);
    //访问根结点
    printf("%c ", b->data);
}

/*------------------------------------------------------
 * 函数名：printLeafNode_exa7_8
 *
 * 功  能：输出一颗二叉树的所有叶子结点
 *
 * 描  述：二叉树采用二叉链存储结构存储
 *        采用先序遍历递归算法输出所有叶子结点（从左向右输出）
 *        若要改成从右向左输出，只需要将先序遍历中左右子树访问
 *        次序倒过来。
 *
 * 参  数：b，二叉树根结点指针
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/20 10:03
 * -----------------------------------------------------*/
void printLeafNode_exa7_8(BTNode *b) {
    if (b == NULL) {
        return;
    }
    if (b->lchild == NULL && b->rchild == NULL) {
        printf("%c ", b->data);
    }
    printLeafNode_exa7_8(b->lchild);
    printLeafNode_exa7_8(b->rchild);

}

/*------------------------------------------------------
 * 函数名：level_exa7_9
 *
 * 功  能：求二叉树中结点值为x的结点的层数（假设二叉树结点值均不相同）
 *
 * 描  述：二叉树采用二叉链存储结构存储
 *
 * 参  数：b，二叉树根结点指针
 *
 * 返回值：值为x的结点所在的层数
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/20 10:22
 * -----------------------------------------------------*/
int level_exa7_9(BTNode *b, ElemType x, int level) {
    int lev;
    //二叉树为空返回0
    if (b == NULL) {
        return 0;
    }
    if (b->data == x) {
        return level;
    }
    lev = level_exa7_9(b->lchild, x, level + 1);
    if (lev == 0) {
        lev = level_exa7_9(b->rchild, x, level + 1);
    }
    return lev;
}

/*------------------------------------------------------
 * 函数名：ancestor_exa7_11
 *
 * 功  能：输出值为x的结点的所有祖先
 *
 * 描  述：二叉树采用二叉链存储结构
 *
 * 参  数：b，二叉树根结点指针；
 *        x，待查找值；
 *        ancs，祖先结点集合；
 *        count，祖先数量
 *
 * 返回值：0(未能找到)或1(找到该值)
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/20 20:55
 * -----------------------------------------------------*/
int ancestor_exa7_11(BTNode *b, ElemType x, BTNode *ancs[], int count) {
    int find = 0;
    if (b == NULL) {
        return 0;
    }
    if (b->data == x) {
        for (int i = 0; i < count; ++i) {
            printf("%c ", ancs[i]->data);
        }
        return 1;
    } else {
        ancs[count] = b;
        find = ancestor_exa7_11(b->lchild, x, ancs, count + 1);
        if (find == 0) {
            find = ancestor_exa7_11(b->rchild, x, ancs, count + 1);
        }
        return find;
    }
}

/*------------------------------------------------------
 * 函数名：ancestor_exa7_11_book
 *
 * 功  能：输出值为x的结点的所有祖先
 *
 * 描  述：求x结点的所有祖先的递归模型f(b,x)模型如下。的值表示
 *        *b结点是不是值为x的结点或其祖先结点，若是f(b,x)=1，
 *        否则f(b,x)=0当为1时，输出*b结点的双亲结点。
 *
 * 参  数：b，二叉树根结点指针；
 *        x，待查找值；
 *
 * 返回值：0(未能找到)或1(找到该值)
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/20 21:08
 * -----------------------------------------------------*/
int ancestor_exa7_11_book(BTNode *b, ElemType x) {
    if (b == NULL) {
        return 0;
    }
    if (b->data == x) {
        return 1;
    }
    if (ancestor_exa7_11_book(b->lchild, x) || ancestor_exa7_11_book(b->rchild, x)) {
        printf("%c ", b->data);
        return 1;
    }
}

/*------------------------------------------------------
 * 函数名：preOrder_nonRecursion
 *
 * 功  能：先序遍历非递归算法
 *
 * 描  述：先将根结点进栈，栈不为空时循环：出栈p，访问p结点，若
 *        右孩子不空将该右孩子结点进栈，若左孩子不空再将该左孩子
 *        结点进栈。
 *
 * 参  数：b，二叉树根结点指针
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/21 9:29
 * -----------------------------------------------------*/
void preOrder_nonRecursion(BTNode *b) {
    BTNode *st[MaxSize], *p;
    int top = -1;
    if (b == NULL) {
        return;
    }
    //根结点进栈
    top++;
    st[top] = b;
    //栈不为空时循环
    while (top != -1) {
        //退栈并访问该结点
        p = st[top];
        top--;
        printf("%c ", p->data);
        if (p->rchild != NULL) {
            top++;
            st[top] = p->rchild;
        }
        if (p->lchild != NULL) {
            top++;
            st[top] = p->lchild;
        }
    }
    printf("\n");
}

/*------------------------------------------------------
 * 函数名：inOrder_nonRecursion
 *
 * 功  能：中序遍历非递归算法
 *
 * 描  述：
 *
 * 参  数：b，二叉树根结点指针
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/21 9:45
 * -----------------------------------------------------*/
void inOrder_nonRecursion(BTNode *b) {
    BTNode *st[MaxSize], *p, *q;
    int top = -1;
    if (b == NULL) {
        return;
    }
    //将根结点到最左侧结点的路径上所有结点进栈
    p = b;
    while (p != NULL) {
        top++;
        st[top] = p;
        p = p->lchild;
    }
    //栈不空时循环
    while (top > -1) {
        //将栈顶元素出栈
        q = st[top];
        top--;
        //输出该栈顶元素值
        printf("%c ", q->data);
        //将其右子树的根结点到最左侧结点的路径上所有结点进栈
        p = q->rchild;
        while (p != NULL) {
            top++;
            st[top] = p;
            p = p->lchild;
        }
        //循环上述过程
    }
    printf("\n");
}
void inOrder_nonRecursion_book(BTNode *b){
    BTNode *st[MaxSize],*p;
    int top=-1;
    if (b!=NULL) {
        p = b;
        //处理b结点的左子树
        while (top > -1 || p != NULL) {
            //扫描p的所有左结点并进栈
            while(p!=NULL) {
                top++;
                st[top] = p;
                p = p->lchild;
            }
            //执行到此处时，栈顶元素没有左孩子或左子树均已访问过
            if (top > -1) {
                //出栈p结点
                p = st[top];
                top--;
                //访问之
                printf("%c ", p->data);
                //转向处理p的右孩子结点
                p = p->rchild;
            }
        }
        printf("\n");
    }
}

/*------------------------------------------------------
 * 函数名：postOrder_nonRecursion
 *
 * 功  能：后序遍历非递归算法
 *
 * 描  述：
 *
 * 参  数：b，二叉树根结点的指针
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/21 10:37
 * -----------------------------------------------------*/
void postOrder_nonRecursion(BTNode *b){
    BTNode *st[MaxSize],*p;
    int top=-1,flag;
    if (b!=NULL){
        do{
            //将b的所有左结点进栈
            while(b!=NULL){
                top++;
                st[top]=b;
                b=b->lchild;
            }
            //执行到此处时，栈顶元素没有左孩子或左子树均已访问过
            //p指向栈顶结点的前一个已访问的结点
            p=NULL;
            //表示b的左孩子已访问过或为空
            flag=1;
            while(top!=-1&&flag){
                b=st[top];
                /*
                 * 若p=null，表示b的右孩子不存在，而其左子树不存在或已访问，所以可以访问*b；
                 * 若p!=null，表示b的右子树已访问（原因是p是指向b的右子树中刚访问过的结点，
                 * 而p是b的右孩子，p一定是b的右子树中后序序列的最后一个结点），所以可以访问b。
                 * */
                if (b->rchild==p){
                    printf("%c ",b->data);
                    top--;
                    p=b;
                } else{
                    b=b->rchild;
                    flag=0;
                }
            }

        }while (top!=-1);
        printf("\n");
    }

}

/*------------------------------------------------------
 * 函数名：allPath_exa7_12
 *
 * 功  能：输出从根结点到每个叶子结点的路径之逆
 *
 * 描  述：采用后序遍历非递归算法
 *
 * 参  数：b，二叉树根结点指针
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/21 16:47
 * -----------------------------------------------------*/
void allPath_exa7_12(BTNode *b){
    BTNode * st[MaxSize],*p;
    int top=-1,flag,tmp;
    if (b!=NULL){
        do{
            while (b!=NULL){
                top++;
                st[top]=b;
                b=b->lchild;
            }
            p=NULL;
            flag=1;
            while (top!=-1&&flag){
                b=st[top];
                if (b->rchild==p){
                    top--;
                    p=b;
                    //若为叶子结点
                    //输出所有的祖先结点
                    if (b->lchild==NULL&&b->rchild==NULL){
                        tmp=top;
                        printf("叶子结点 %c 的祖先结点如下：",b->data);
                        while(tmp!=-1){
                            printf("%c ",st[tmp]->data);
                            tmp--;
                        }
                        printf("\n");
                    }

                }else{
                    b=b->rchild;
                    flag=0;
                }
            }

        }while (top!=-1);
        printf("\n");
    }

}

/*------------------------------------------------------
 * 函数名：levelOrder
 *
 * 功  能：层次遍历算法
 *
 * 描  述：先将根结点进队，在队不空时循环：从队列中出列一个结点p，
 *        访问它；若他有左孩子结点，将左孩子结点进队；若他有右孩
 *        子结点，将右孩子结点进队，如此操作直到队空为止。
 *
 * 参  数：b，二叉树根结点的指针
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/21 17:11
 * -----------------------------------------------------*/
void levelOrder(BTNode *b){

    BTNode * qu[MaxSize],*p;
    int front,rear;
    //初始化队列
    front=rear=1;
    //将根结点进队
    qu[rear]=b;
    rear++;
    //队不空时循环
    while(rear!=front){
        //出队一个元素
        p=qu[front];
        front++;
        printf("%c ",p->data);
        if (p->lchild!=NULL){
            qu[rear]=p->lchild;
            rear=(rear+1)%MaxSize;
        }
        if (p->rchild!=NULL){
            qu[rear]=p->rchild;
            rear=(rear+1)%MaxSize;
        }
    }

}

/*------------------------------------------------------
 * 函数名：allPath_exa7_12_level
 *
 * 功  能：层次遍历输出所有叶子节点的祖先结点
 *
 * 描  述：
 *
 * 参  数：
 *
 * 返回值：
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/21 17:23
 * -----------------------------------------------------*/
void allPath_exa7_12_level(BTNode *b){
    struct snode{
        BTNode *node;
        int parent;
    }qu[MaxSize];
    BTNode *q;
    int front,rear,p;
    front=rear=-1;
    rear++;
    qu[rear].node=b;
    qu[rear].parent=-1;
    while (front<rear){
        front++;
        q=qu[front].node;
        if (q->lchild==NULL&&q->rchild==NULL){
            p=front;
            while(qu[p].parent!=-1){
                printf("%c ->",qu[p].node->data);
                p=qu[p].parent;
            }
            printf("%c\n",qu[p].node->data);
        }
        if (q->lchild!=NULL){
            rear++;
            qu[rear].node=q->lchild;
            qu[rear].parent=front;
        }
        if (q->rchild!=NULL){
            rear++;
            qu[rear].node=q->rchild;
            qu[rear].parent=front;
        }
    }
}