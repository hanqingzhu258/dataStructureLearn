//
// Description:
// Created by hanqing zhu on 2018/12/3.
//

#include "unit4.h"

/*------------------------------------------------------
 * 函数名：searchHT
 *
 * 功  能：在哈希表中查找关键字k
 *
 * 描  述：开放地址法中的线性探查法思路
 *
 * 参  数：ha，哈希表；
 *        p，除留余数法中的除数；
 *        k，待查找关键字。
 *
 * 返回值：-1(查找失败)或关键字所在地址(查找成功)
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/12/3 10:21
 * -----------------------------------------------------*/
int searchHT(HashTable ha,int p,KeyType k){
    //i表示探查次数
    int i=0,adr;
    adr=k%p;
    while (ha[adr].key!=NULLKEY&&ha[adr].key!=k){
        i++;
        adr=(adr+1)%p;
    }
    //查找失败
    if(ha[adr].key!=k){
        return -1;
    }
    //查找成功
    else{
        return adr;
    }
}

/*------------------------------------------------------
 * 函数名：deleteHT
 *
 * 功  能：删除哈希表中的关键字k
 *
 * 描  述：采用开放地址法处理冲突的哈希表上执行删除操作，只能在
 *        被删记录上做删除标记，而不能真正删除记录。在这里设删
 *        除标记DELKEY。
 *
 * 参  数：ha，哈希表；
 *        p，除留余数法中的除数；
 *        k，待查找关键字；
 *        n，记录个数。
 *
 * 返回值：0(删除失败)或1(删除成功)
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/12/3 10:30
 * -----------------------------------------------------*/
int deleteHT(HashTable ha,int p,int k,int *n){
    int adr;
    adr=searchHT(ha,p,k);
    //在哈希表中找到改关键字
    if (adr!=-1){
        ha[adr].key=DELKEY;
        //记录个数减一
        (*n)--;
        return 1;
    }
    //在哈希表中未找到该关键字
    else{
        return 0;
    }
}

/*------------------------------------------------------
 * 函数名：insertHT
 *
 * 功  能：将k插入到哈希表中
 *
 * 描  述：
 *
 * 参  数：ha，哈希表；
 *        p，除留余数法中的除数；
 *        k，待查找关键字；
 *        n，记录个数。
 *
 * 返回值：
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/12/3 10:40
 * -----------------------------------------------------*/
void insertHT(HashTable ha,int p,int k,int *n){
    int i,adr;
    adr=k%p;
    //k直接放在哈希表中
    if(ha[adr].key==NULLKEY||ha[adr].key==DELKEY){
        ha[adr].key=k;
        ha[adr].count=1;
    }
    //发生冲突时采用线性探查法解决冲突
    else{
        //i记录插入k时发生冲突的次数
        i++;
        do{
            adr=(adr+1)%p;
            i++;
        }while (ha[adr].key!=NULLKEY&&ha[adr].key!=DELKEY);
        ha[adr].key=k;
        ha[adr].count=i;
    }
    n++;
}

/*------------------------------------------------------
 * 函数名：createHT
 *
 * 功  能：创建哈希表
 *
 * 描  述：
 *
 * 参  数：ha，哈希表；
 *        x，关键字序列；
 *        n，关键字个数；
 *        m，哈希表大小；
 *        p，除留余数法中的除数。
 *
 * 返回值：
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/12/3 10:44
 * -----------------------------------------------------*/
void createHT(HashTable ha,KeyType x[],int n,int m,int p){
    int i,n1=0;
    //哈希表置初值
    for (i=0;i<m;i++){
        ha[i].key=NULLKEY;
        ha[i].count=0;
    }
    for (i=0;i<n;i++){
        insertHT(ha,p,x[i],n1);
    }
}