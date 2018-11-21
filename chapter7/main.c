#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "unit4.h"
#include "unit5.h"
#include "unit6.h"

void main() {

    //test_unit4
//    BTNode *b;
//    createBTNode(&b,"A(B(D(,G)),C(E,F))");
//    dispBTNode(b);
//    printf("\nheight:%d\n",BTNodeHeight(b));

    //test_unit5_pre|in|post Order
//    BTNode *b;
//    createBTNode(&b,"A(B(D(,G)),C(E,F))");
//    dispBTNode(b);
//    printf("\n");
//    //先序
//    preOrder(b);
//    printf("\n");
//    //先序非递归
//    preOrder_nonRecursion(b);
//    //中序
//    inOrder(b);
//    printf("\n");
//    inOrder_nonRecursion(b);
//    inOrder_nonRecursion_book(b);
//    //后序
//    postOrder(b);
//    printf("\n");
//    postOrder_nonRecursion(b);
//    //层次遍历
//    levelOrder(b);

    //test_unit5_exa7_8
//    BTNode *b;
//    createBTNode(&b, "A(B(D(,G)),C(E,F))");
//    dispBTNode(b);
//    printf("\n");
//    printLeafNode_exa7_8(b);

    //test_unit5_exa7_9
//    BTNode *b;
//    ElemType x;
//    int level=1;
//    createBTNode(&b, "A(B(D(,G)),C(E,F))");
//    dispBTNode(b);
//    printf("\n");
//    //接受用户输入x
//    while (1){
//        printf("请输入x:");
//        scanf("%c%*c",&x);
//        //如果输入空格，终止程序
//        if (x==' ') {
//            return;
//        }
//        level=level_exa7_9(b,x,level);
//        printf("x=%c的结点在该二叉树第%d层\n",x,level);
//        level=1;
//    }


    //test_unit5_exa7_11
//    BTNode *b;
//    BTNode * ancs[MaxSize];
//    ElemType x='G';
//    createBTNode(&b, "A(B(D(,G)),C(E,F))");
//    dispBTNode(b);
//    printf("\n");
//    ancestor_exa7_11(b,x,ancs,0);
//    printf("\n");
//    ancestor_exa7_11_book(b,x);

    //test_unit5_exa7_12
//    BTNode *b;
//    createBTNode(&b,"A(B(D(,G)),C(E,F))");
//    dispBTNode(b);
//    printf("\n");
//    allPath_exa7_12(b);
//    allPath_exa7_12_level(b);

    //test_unit6_createBT1
    BTNode *b;
    b=createBT1_unit6("ABDGCEF","DGBAECF",7);
    dispBTNode(b);

}