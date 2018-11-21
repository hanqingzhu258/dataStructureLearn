//
// Description: 二叉树的链式存储结构
// Created by hanqing zhu on 2018/11/19.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "unit4.h"

/*------------------------------------------------------
 * 函数名：createBTNode
 *
 * 功  能：创建二叉树
 *
 * 描  述：用ch扫描采用括号表示法表示二叉树的字符串。分为如下情况：
 *        .若ch='('。则将前面刚创建的结点作为双亲结点进栈，并置
 *         k=1，表示其后创建的结点将作为这个结点的左孩子结点；
 *        .若ch=')'。表示栈顶结点的左右孩子结点处理完毕，退栈；
 *        .若ch=','。表示其后创建的结点为右孩子结点，
 *        .其他情况，表示要创建一个结点，并根据k值建立它与栈顶结点
 *         之间的联系，当k=1时，表示这个结点作为栈顶结点的左孩子结
 *         点，当k=2时，表示这个结点作为栈顶结点的右孩子结点。如此
 *         循环直到str处理完毕。算法中使用一个栈st保存双亲结点，top
 *         为其栈指针，k指定其后处理的结点是双亲结点（保存在栈中）的
 *         左孩子结点（k=1）还是右孩子结点（k=2）。
 *
 * 参  数：b，二叉树的根结点；
 *        str，括号表示法表示二叉树的字符串。
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/19 10:13
 * -----------------------------------------------------*/
void createBTNode(BTNode **b, char *str) {
    BTNode *st[MaxSize], *p = NULL;
    int top = -1, k=0, j = 0;
    char ch;
    *b = NULL;
    ch = str[j];
    //扫描字符串中的每个字符
    while (ch != '\0') {

        switch (ch) {
            case '(':
                top++;
                st[top] = p;
                k = 1;
                break;
            case ')':
                top--;
                break;
            case ',':
                k = 2;
                break;
            default:
                p = (BTNode *) malloc(sizeof(BTNode));
                p->data = ch;
                p->lchild = p->rchild = NULL;
                //*p为二叉树的根结点
                if (*b == NULL) {
                    *b = p;
                }
                    //已建立二叉树的根结点
                else {
                    switch (k) {
                        case 1:
                            st[top]->lchild = p;
                            break;
                        case 2:
                            st[top]->rchild = p;
                            break;
                    }
                }

        }
        j++;
        ch = str[j];
    }
}

/*------------------------------------------------------
 * 函数名：findNode
 *
 * 功  能：在二叉树中查找值为x的结点，找到后返回其指针，否则返回NULL
 *
 * 描  述：递归算法
 *
 * 参  数：b，二叉树；
 *        x，待搜索值。
 *
 * 返回值：二叉树中值为x的结点的指针
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/19 10:45
 * -----------------------------------------------------*/
BTNode *findNode(BTNode *b, ElemType x) {
    BTNode *p;
    //如果b为空返回NULL
    if (b == NULL) {
        return NULL;
    }
    //如果当前二叉树的根结点的值为x
    if (b->data == x) {
        return b;
    } else {
        //在其左子树中寻找
        p = findNode(b->lchild, x);
        if (p != NULL) {
            return p;
        }
        //在其右子树中寻找
        return findNode(b->rchild, x);
    }
}

/*------------------------------------------------------
 * 函数名：lChildNode,rChildNode
 *
 * 功  能：找孩子结点
 *
 * 描  述：直接返回*p结点的左孩子结点或右孩子结点的指针
 *
 * 参  数：p，待找孩子的结点
 *
 * 返回值：*p的左孩子结点或右孩子结点的指针
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/19 10:48
 * -----------------------------------------------------*/
BTNode *lChildNode(BTNode *p) {
    return p->lchild;
}

BTNode *rChildNode(BTNode *p) {
    return p->rchild;
}

/*------------------------------------------------------
 * 函数名：BTNodeHeight
 *
 * 功  能：求二叉树的高度
 *
 * 描  述：递归求解
 *
 * 参  数：b，二叉树的根结点指针
 *
 * 返回值：二叉树的高度
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/19 10:58
 * -----------------------------------------------------*/
int BTNodeHeight(BTNode *b) {
    int lHeight, rHeight;
    //二叉树为空
    if (b == NULL) {
        return 0;
    }
    //二叉树只有根结点
//    if (b->lchild==NULL&&b->rchild==NULL){
//        return 1;
//    }
    //左子树的高度
    lHeight = BTNodeHeight(b->lchild);
    //右子树的高度
    rHeight = BTNodeHeight(b->rchild);
    //返回较高子树的高度加一
    return (lHeight > rHeight ? lHeight + 1 : rHeight + 1);
}

/*------------------------------------------------------
 * 函数名：dispBTNode
 *
 * 功  能：输出二叉树
 *
 * 描  述：对于非空二叉树b，先输出其元素值，当存在左孩子结点或
 *        右孩子结点时，输出一个“(”符号，然后递归处理左子树，
 *        输出一个“,”符号，递归处理右子树，最后输出一个“)”符号。
 *
 * 参  数：b，二叉树根结点
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/19 11:00
 * -----------------------------------------------------*/
void dispBTNode(BTNode *b) {
    if (b == NULL) {
        return;
    }
    printf("%c", b->data);
    if (b->lchild != NULL || b->rchild != NULL) {
        printf("(");
        //递归处理左子树
        dispBTNode(b->lchild);
        if (b->rchild != NULL) {
            printf(",");
        }
        //递归处理右子树
        dispBTNode(b->rchild);
        printf(")");
    }
}