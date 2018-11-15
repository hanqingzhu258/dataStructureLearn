//
// Description:
// Created by hanqing zhu on 2018/11/15.
//

#include <stdio.h>
#include "unit2_1.h"

/*------------------------------------------------------
 * 函数名：createMat
 *
 * 功  能：从一个二维矩阵创建其三元组表示
 *
 * 描  述：以行序方式扫描二维矩阵A，将其非零的元素插入到三元组t中
 *
 * 参  数：t，存储稀疏矩阵三元组顺序表；
 *        A，稀疏矩阵。
 *
 * 返回值：无
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void createMat(TSMatrix *t, ElemType A[M][N]) {
    int i, j;
    t->rows = M;
    t->cols = N;
    t->nums = 0;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (A[i][j] != 0) {
                t->data[t->nums].r = i;
                t->data[t->nums].c = j;
                t->data[t->nums].d = A[i][j];
                t->nums++;
            }
        }
    }
}

/*------------------------------------------------------
 * 函数名：value
 *
 * 功  能：三元组元素赋值
 *
 * 描  述：先在三元组t中找到适当的位置k，将k~t.nums个元素后移一
 *        个位置，将指定元素x插入到t.data[k]处。
 *
 * 参  数：t，三元组顺序表；
 *        x，待赋值；
 *        rs，行号；
 *        cs，列号。
 *
 * 返回值：0(赋值失败)或1(赋值成功)
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int value(TSMatrix *t, ElemType x, int rs, int cs) {
    int i = 0, j;
    //参数错误返回0
    if (rs >= t->rows || cs >= t->cols) {
        return 0;
    }
    //查找行
    while (i < t->nums && t->data[i].r < rs) {
        i++;
    }
    //查找列
    while (i < t->nums && t->data[i].c < cs && t->data[i].r == rs) {
        i++;
    }
    //如果已存在这样的元素，直接进行值的替换
    if (t->data[i].r == rs && t->data[i].c == cs) {
        t->data[i].d = x;
    }
    //如果不存在这样的元素
    else {
        //将第i个及其后面的元素向后移一位
        for (j = t->nums - 1; j > i; j--) {
            t->data[j + 1] = t->data[j];
        }
        t->data[i].r = rs;
        t->data[i].c = cs;
        t->data[i].d = x;
        //非零元素的个数加1
        t->nums++;
    }
    return 1;
}

/*------------------------------------------------------
 * 函数名：assign
 *
 * 功  能：将指定位置的元素赋给变量
 *
 * 描  述：现在三元组中找到指定的位置，将该处的元素值赋给x。
 *
 * 参  数：t，三元组顺序表；
 *        x，指定位置的值；
 *        rs，cs，指定位置的行、列号。
 *
 * 返回值：0(位置不存在)或1(赋值成功)
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int assign(TSMatrix t,ElemType *x, int rs, int cs){
    int i=0;
    //参数不正确返回0
    if(rs>=t.rows||cs>=t.cols){
        return 0;
    }
    //查找行
    while (i<t.nums&&t.data[i].r<rs){
        i++;
    }
    //查找列
    while (i<t.nums&&t.data[i].r==rs&&t.data[i].c<cs){
        i++;
    }
    //如果这样的元素存在
    if(t.data[i].r==rs&&t.data[i].c==cs){
        *x=t.data[i].d;
        return 1;
    } else{
        return 0;
    }
}

/*------------------------------------------------------
 * 函数名：dispMat
 *
 * 功  能：输出三元组
 *
 * 描  述：从头到尾扫描三元组t，依次输出元素值
 *
 * 参  数：t，三元组线性表。
 *
 * 返回值：无
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void dispMat(TSMatrix t){
    int i;
    if(t.nums<=0) return;
    printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.nums);
    printf("  -------------------------\n");
    for(i=0;i<t.nums;i++){
        printf("\t%d\t%d\t%d\n",t.data[i].r,t.data[i].c,t.data[i].d);
    }
}

/*------------------------------------------------------
 * 函数名：tranTat
 *
 * 功  能：矩阵转置
 *
 * 描  述：常规的非稀疏矩阵应采用二维数组存储，只有当矩阵中非零
 *        元素的个数远小于mn时，才可采用三元组顺序表存储结构
 *
 * 参  数：t，原矩阵；
 *        tb，转置矩阵。
 *
 * 返回值：无
 *
 * 时间复杂度：O(t.cols X t.nums)
 * -----------------------------------------------------*/
void tranTat(TSMatrix t,TSMatrix *tb){
    int p,q=0,v;
    tb->rows=t.cols;
    tb->cols=t.rows;
    tb->nums=t.nums;
    if(t.nums!=0){
        for(v=0;v<t.cols;v++){
            for(p=0;p<t.nums;p++){
                if(t.data[p].c==v){
                    tb->data[q].r=t.data[p].c;
                    tb->data[q].c=t.data[p].r;
                    tb->data[q].d=t.data[p].d;
                    q++;
                }
            }
        }
    }
}

/*------------------------------------------------------
 * 函数名：matAdd
 *
 * 功  能：两个用三元组存储的稀疏矩阵相加
 *
 * 描  述：用i和j作为两个三元组的指针，以行序对他们的当前值进行
 *        相加运算，并将结果存放在c中。
 *
 * 参  数：a，b，待相加的稀疏矩阵；
 *        c，结果矩阵。
 *
 * 返回值：0(相加失败)或1(相加成功)
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int matAdd(TSMatrix a,TSMatrix b,TSMatrix *c){
    int i=0,j=0,k=0;
    ElemType v;
    if (a.rows!=b.rows||a.cols!=b.cols){
        return 0;
    }
    c->rows=a.rows;
    c->cols=a.cols;
    while (i<a.nums&&j<b.nums){
        if(a.data[i].r==b.data[j].r){
            if (a.data[i].c<b.data[j].c){
                c->data[k].r=a.data[i].r;
                c->data[k].c=a.data[i].c;
                c->data[k].d=a.data[i].d;
                k++;
                i++;
            }else if (a.data[i].c==b.data[j].c){
                v=a.data[i].d+b.data[j].d;
                if (v!=0){
                    c->data[k].r=a.data[i].r;
                    c->data[k].c=a.data[i].c;
                    c->data[k].d=v;
                    k++;
                }
                i++;
                j++;
            } else {
                c->data[k].r=b.data[j].r;
                c->data[k].c=b.data[j].c;
                c->data[k].d=b.data[j].d;
                k++;
                j++;
            }
        } else if (a.data[i].r<b.data[j].r){
            c->data[k].r=a.data[i].r;
            c->data[k].c=a.data[i].c;
            c->data[k].d=a.data[i].d;
            k++;
            i++;
        }else{
            c->data[k].r=b.data[j].r;
            c->data[k].c=b.data[j].c;
            c->data[k].d=b.data[j].d;
            k++;
            j++;
        }
        c->nums=k;
    }
    return 1;
}