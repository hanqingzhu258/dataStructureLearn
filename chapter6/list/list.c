#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*------------------------------------------------------
* 函数名：createList
*
* 功  能：由a中的n个元素创建顺序表
*
* 参  数：L，指向顺序表的指针；
		  a，创建顺序表的数组
		  n，数组a的长度
*
* 返回值：无
*
* 时间复杂度：
* -----------------------------------------------------*/
void createList(SqList **L,ElemType a[],int n){
	int i;

	printf("正在创建顺序表L...\n");

	//分配存放线性表的空间
	*L=(SqList *)malloc(sizeof(SqList));

	for(i=0;i<n;i++){
		(*L)->data[i]=a[i];
	}
	(*L)->length=n;
//	printf("length:%d",(*L)->length);
}
/*void createList(SqList *L,ElemType a[],int n){
	int i;

	printf("正在创建顺序表L...\n");

	//分配存放线性表的空间
	L=(SqList *)malloc(sizeof(SqList));

	for(i=0;i<n;i++){
		L->data[i]=a[i];
	}
	L->length=n;
}*/

/*------------------------------------------------------
* 函数名：initList
*
* 功  能：初始化线性表（分配存储空间并将length成员设置为0）
*
* 参  数：L，指向顺序表的指针；
*
* 返回值：无
*
* 时间复杂度：O(1)
* -----------------------------------------------------*/
void initList(SqList **L){
	*L=(SqList *)malloc(sizeof(SqList));
	(*L)->length=0;
}
/*void initList(SqList *L){
	L=(SqList *)malloc(sizeof(SqList));
	L->length=0;
}*/


/*------------------------------------------------------
* 函数名：destroyList
*
* 功  能：销毁线性表（释放线性表L占用的内存空间）
*
* 参  数：L，指向顺序表的指针；
*
* 返回值：无
*
* 时间复杂度：O(1)
* -----------------------------------------------------*/
void destroyList(SqList **L){
	free(*L);
}
/*void destroyList(SqList *L){
	free(L);
}*/


/*------------------------------------------------------
* 函数名：listEmpty
*
* 功  能：线性表是空表？1:0
*
* 参  数：L，指向顺序表的指针；
*
* 返回值：1(空表)或0(非空表)
*
* 时间复杂度：O(1)
* -----------------------------------------------------*/
int listEmpty(SqList *L){
	return(L->length==0);
}


/*------------------------------------------------------
* 函数名：listLength
*
* 功  能：求线性表的长度
*
* 参  数：L，指向顺序表的指针；
*
* 返回值：线性表的长度（整型）
*
* 时间复杂度：O(1)
* -----------------------------------------------------*/
int listLength(SqList *L){
	return(L->length);
}

/*------------------------------------------------------
* 函数名：dispList
*
* 功  能：输出线性表（顺序显示线性表中的各元素的值）
*
* 参  数：L，指向顺序表的指针；
*
* 返回值：无
*
* 时间复杂度：O(L->length)
* -----------------------------------------------------*/
void dispList(SqList *L){
	int i;

	printf("正在打印顺序表L...\n");
	/*printf("当前顺序表的长度为：%d\n",L->length);*/

	if(listEmpty(L)){
		return;
	}
	for(i=0;i<L->length;i++){
		printf("%d ",L->data[i]);
	}
	printf("\n");
}


/*------------------------------------------------------
* 函数名：getElem
*
* 功  能：求线性表中某个数据元素的值（用e返回第i个元素的值）
*
* 参  数：L，指向顺序表的指针；
		  i，要求元素的逻辑位置
		  e，要求元素的载体（值）
*
* 返回值：0(参数i错误)或1(获取成功)
*
* 时间复杂度：O(1)
* -----------------------------------------------------*/
int getElem(SqList *L,int i,ElemType *e){
	if(i<1||i>L->length){
		return 0;
	}
	*e=L->data[i-1];
	return 1;
}


/*------------------------------------------------------
* 函数名：locateElem
*
* 功  能：按元素查找（查找第一个与e相等的元素的逻辑位序）
*
* 参  数：L，指向顺序表的指针；
		  e，要查找的元素值
*
* 返回值：0(元素不存在)或元素逻辑位序(元素存在)
*
* 时间复杂度：O(L->length)
* -----------------------------------------------------*/
int locateElem(SqList *L,ElemType e){
	int i=0;
	while(i<L->length&&L->data[i]!=e){
		i++;
	}
	if(i>=L->length){
		return 0;
	}else{
		return i+1;
	}
}

/*------------------------------------------------------
* 函数名：listInsert
*
* 功  能：插入数据元素（在L的第i个位置上插入新的元素e）
*
* 参  数：L，指向顺序表的指针；
		  i，要插入的逻辑位置
		  e，新元素的值
*
* 返回值：0(参数i错误)或1(插入成功)
*
* 时间复杂度：O(n)
* -----------------------------------------------------*/
int listInsert(SqList **L,int i,ElemType e){
	int j;
	if(i<1||i>=(*L)->length+1){
		return 0;
	}
	i--;
	for(j=(*L)->length;j>i;j--){
		(*L)->data[j]=(*L)->data[j-1];
	}
	(*L)->data[i]=e;
	(*L)->length++;
	return 1;
}


/*------------------------------------------------------
* 函数名：listDelete
*
* 功  能：删除数据元素（删除L中的第i个元素）
*
* 参  数：L，指向顺序表的指针；
		  i，要删除元素的逻辑位置
		  e，删除的元素值
*
* 返回值：0(参数i错误)或1(删除成功)
*
* 时间复杂度：O(n)
* -----------------------------------------------------*/
int listDelete(SqList **L,int i,ElemType *e){
	int j;
	if(i<1||i>(*L)->length){
		return 0;
	}
	i--;//转换成物理位序
	*e=(*L)->data[i];
	for(j=i;j<=(*L)->length-2;j++){
		(*L)->data[j]=(*L)->data[j+1];
	}
	(*L)->data[(*L)->length-1]=0;//可以忽略
	(*L)->length--;
	return  1;
}