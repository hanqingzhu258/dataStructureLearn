//
// Description: 
// Created by hanqing zhu on 2018/11/29.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "unit3.h"

//m阶B-树，这里的，m，max和min三个变量均定义为全局变量
int m;
//m阶B-树中每个结点的至多关键字个数，max=m-1
int max;
//m阶B-树非叶子结点的至少关键字个数，min=[m/2]-1=【(m-1)/2】
int min;


/*------------------------------------------------------
 * 函数名：insertBST
 *
 * 功  能：在二叉排序树中插入一个新纪录
 *
 * 描  述：在以r为根结点的BST中插入一个关键字为k的结点，插入成功
 *        返回1，否则返回0
 *
 * 参  数：r，BST的根结点；
 *        k，待插入关键字。
 *
 * 返回值：0(插入失败)或1(插入成功)
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/29 15:57
 * -----------------------------------------------------*/
int insertBST(BSTNode **r,KeyType k){
    if(*r==NULL){
        *r=(BSTNode *)malloc(sizeof(BSTNode));
        (*r)->key=k;
        (*r)->lchild=(*r)->rchild=NULL;
        return 1;
    } else{
        if (k<(*r)->key){
            //递归插入左子树
            return insertBST(&(*r)->lchild,k);
        }
        //存在相同的关键字，返回0
        else if (k==(*r)->key){
            return 0;
        }else{
            //递归插入右子树
            return insertBST(&(*r)->rchild,k);
        }
    }
}

/*------------------------------------------------------
 * 函数名：createBST
 *
 * 功  能：从关键字数组A[0..n-1]生成二叉排序树
 *
 * 描  述：
 *
 * 参  数：A，关键字数组；
 *        n，关键字个数。
 *
 * 返回值：BST的根结点
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/29 16:13
 * -----------------------------------------------------*/
BSTNode * createBST(KeyType A[],int n){
    BSTNode *r=NULL;
    int i;
    for (i=0;i<n;i++){
        insertBST(&r,A[i]);
    }
    return r;
}

/*------------------------------------------------------
 * 函数名：searchBST
 *
 * 功  能：在二叉排序树上查找关键字为k的记录
 *
 * 描  述：
 *
 * 参  数：r，BST根结点；
 *        k，待查找关键字。
 *
 * 返回值：待查找关键字所在结点的指针
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/29 16:25
 * -----------------------------------------------------*/
BSTNode * searchBST(BSTNode *r,KeyType k){
    if (r==NULL||r->key==k){
        return r;
    }
    if (k<r->key){
        //在左子树中递归查找
        return searchBST(r->lchild,k);
    }else{
        //在右子树中递归查找
        return searchBST(r->rchild,k);
    }
}
/*------------------------------------------------------
 * 函数名：searchBST1
 *
 * 功  能：在searchBST的基础上，返回其双亲结点的指针
 *
 * 描  述：
 *
 * 参  数：r，BST根结点；
 *        k，待查找关键字；
 *        f1，指向双亲结点（作为中介）；
 *        f，待查找关键字所在结点的双亲结点。
 *
 * 返回值：待查找关键字所在结点的指针
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/29 16:34
 * -----------------------------------------------------*/
BSTNode * searchBST1(BSTNode *r,KeyType k,BSTNode *f1,BSTNode **f){
    if (r==NULL||k==r->key){
        *f=f1;
        return r;
    }
    if (k<r->key){
        //在左子树中递归查找
        return searchBST1(r->lchild,k,r,f);
    } else{
        //在左子树中递归查找
        return searchBST1(r->rchild,k,r,f);
    }
}


/*------------------------------------------------------
 * 函数名：maxMinNode
 *
 * 功  能：
 *
 * 描  述：对于给定的二叉排序树中的结点*p，找出其左子树中的最大
 *        结点和右子树中的最小结点
 *
 * 参  数：p，待操作结点。
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/30 16:05
 * -----------------------------------------------------*/
void maxMinNode(BSTNode *p){
    if (p!=NULL){
        if (p->lchild!=NULL){
            printf("左子树的最大结点为：%d\n",maxNode(p->lchild));
        }
        if (p->rchild!=NULL){
            printf("右子树的最小结点为：%d\n",minNode(p->rchild));
        }
    }
}
//返回一颗二叉排序树中最大结点关键字
KeyType maxNode(BSTNode *p){
    while (p->rchild!=NULL){
        p=p->rchild;
    }
    return (p->key);
}
//返回一颗二叉排序树中的最小结点关键字
KeyType minNode(BSTNode *p){
    while (p->lchild!=NULL){
        p=p->lchild;
    }
    return (p->key);
}

/*------------------------------------------------------
 * 函数名：deleteBST
 *
 * 功  能：二叉排序树的删除
 *
 * 描  述：
 *
 * 参  数：r，二叉排序树的根结点；
 *        k，待删除结点的关键字。
 *
 * 返回值：0(删除失败)或1(删除成功)
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/11/30 16:18
 * -----------------------------------------------------*/
int deleteBST(BSTNode **r,KeyType k){

    if (*r==NULL){
        return 0;
    }
    //递归在左子树中删除为k的结点
    if (k<(*r)->key){
        return deleteBST(&(*r)->lchild,k);
    }
    //递归在右子树中删除为k的结点
    else if (k>(*r)->key){
        return deleteBST(&(*r)->rchild,k);
    }
    //找到了要删除的结点
    else{
        //删除结点
        deleteNode(r);
        return 1;
    }
}

void deleteNode(BSTNode **p){
    BSTNode *q;
    //p结点没有右子树的情况
    if ((*p)->rchild==NULL){
        q=*p;
        *p=(*p)->lchild;
        free(q);
    }
    //p结点没有左子树的情况
    if ((*p)->lchild==NULL){
        q=*p;
        *p=(*p)->rchild;
        free(q);
    }
    //p结点既有右子树又有左子树
    else{
        deleteNode1(p,&(*p)->lchild);
    }
}

//使用递归的原因是因为要对二叉树进行改变，需要地址传递
void deleteNode1(BSTNode **p,BSTNode **r){
    BSTNode *q;
    //递归找到最右下结点
    if ((*r)->rchild!=NULL){
        deleteNode1(p,&(*r)->rchild);
    }else{
        //将r的关键字赋给p
        (*p)->key=(*r)->key;
        q=*r;
        //直接将其左子树的根结点放在被删结点的位置上
        *r=(*r)->lchild;
        free(q);
    }
}

/*------------------------------------------------------
 * 函数名：searchBTree
 *
 * 功  能：B-树的查找（多路查询）
 *
 * 描  述：在一棵B-树上顺序查找关键字为k的方法为将k与根结点中的
 *        key[i]进行比较：
 *        （1）若k=key[i]，查找成功；
 *        （2）若k<key[1]，则沿着指针ptr[0]所指的子树继续查找；
 *        （3）若key[i]<k<key[i+1]，则沿着指针ptr[i]所指的子
 *        树继续查找；
 *        （4）若k>key[n]，则沿指针ptr[n]所指的子树继续查找。
 *
 * 参  数：t，m阶B-树的根结点；
 *        k，待查找关键字。
 *
 * 返回值：
 *
 * 时间复杂度：O(log[m/2]((n+1)/2))：含n个关键字的B-树上查找
 *
 * author： hanqing zhu 2018/12/2 17:01
 * -----------------------------------------------------*/
Result searchBTree(BTNode *t,KeyType k){
    //初始化，p指向待查结点，q指向p的双亲
    BTNode *p=t,*q=NULL;
    int found=0,i=0;
    Result r;
    while (p!=NULL&&found==0){
        //在p->key[1..keynum]中查找i，使得p->key[i]<=k<p->k[i+1]
        i=search_BTNode(p,k);
        if (i>0&&p->ptr[i]==k){
            found=1;
        } else{
            q=p;
            p=p->ptr[i];
        }
    }
    r.i=i;
    if (found==1){
        r.tag=1;
        r.pt=p;
    }
    //查找不成功，返回k的插入位置信息
    else{
        r.pt=q;
        r.tag=0;
    }
    return r;
}
//被searchBTree（）调用在一个结点中查找
//在p->key[1..keynum]中查找i，使得p->key[i]<=k<p->k[i+1]
int search_BTNode(BTNode *p,KeyType k){
    int i;
    for (i = 0; i < p->keynum && p->key[i+1]<=k; i++);
    return i;
}
