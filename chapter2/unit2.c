#include<stdio.h>
#include "list.h"

//exa2-3
void deletem(SqList *L,ElemType x,ElemType y);
//exa2-4
void exa2_4(SqList *L);
void exa2_4_move1(SqList *L);
void exa2_4_move2(SqList *L);

//void main(){

	
	//exa2-3
	/*SqList L;
	int a[10]={1,1,2,3,4,5,6,7,8,9};
	createList(&L,a,10);
	dispList(&L);
	deletem(&L,3,5);
	dispList(&L);*/
	//方式2(采用)
	/*SqList *L;
	int a[10]={1,1,2,3,4,5,6,7,8,9};
	createList(&L,a,10);
	dispList(L);
	deletem(L,3,5);
	dispList(L);*/

	//exa2-4
	/*SqList *L;
	int a[10]={3,5,6,1,4,2,7,9,8,0};
	createList(&L,a,10);
	dispList(L);*/
	/*exa2_4(L);
	printf("方法exa2_4结果：\n");
	dispList(L);*/
	/*exa2_4_move1(L);
	printf("方法exa2_4_move1结果：\n");
	dispList(L);*/
	/*exa2_4_move2(L);
	printf("方法exa2_4_move2结果：\n");
	dispList(L);*/
//}


/*------------------------------------------------------
* 函数名：deletem
*
* 功  能：删除顺序表中元素值在[x,y]之间的所有元素
*
* 参  数：L，指向顺序表的指针；
		  x，左界限值
		  y，右界限值
*
* 返回值：无
*
* 时间复杂度：O(n)或O(L->length)
* -----------------------------------------------------*/
void deletem(SqList *L,ElemType x,ElemType y){
	int i=0,j=0;
	while(i<L->length){
		if(!(L->data[i]>=x&&L->data[i]<=y)){
			L->data[j]=L->data[i];
			j++;
		}
		i++;
	}
	L->length=j;
}

/*------------------------------------------------------
* 函数名：exa2_4(原创方法:只用一个while循环实现)
*
* 功  能：对顺序表L，以第一个元素为分界线，将所有小于它的元素移到该元素的前面，
          将大于它的元素移到该元素的后面
*
* 参  数：L，指向顺序表的指针；
*
* 返回值：无
*
* 时间复杂度：O(n)或O(L->length)//因为只扫描了一遍表L
* -----------------------------------------------------*/
void exa2_4(SqList *L){
	int i=0,j=L->length-1;
	int temp=L->data[0];
	int find=0;

	while(i<j){

		printf("i=%d,j=%d\n",i,j);

		if(L->data[j]<temp){
			if(find==0){
				L->data[i]=L->data[j];
				i++;
			}	
			if(L->data[i]>temp){
				L->data[j]=L->data[i];
				j--;
				find=0;
			}else{
				i++;
				find=1;
			}
		}else{
			j--;
		}

		dispList(L);
	}

	L->data[j]=temp;
	
	/*printf("方法：exa2_4执行结束！");*/
}

/*------------------------------------------------------
* 函数名：exa2_4_move1(书中解法1)
*
* 功  能：对顺序表L，以第一个元素为分界线，将所有小于它的元素移到该元素的前面，
          将大于它的元素移到该元素的后面
*
* 参  数：L，指向顺序表的指针；
*
* 返回值：无
*
* 时间复杂度：
* -----------------------------------------------------*/
void exa2_4_move1(SqList *L){
	int i=0,j=L->length-1;
	//以data[0]为基准
	int pivot=L->data[0];           
	int tmp;
	//从区间两端交替向中间扫面，直至i=j为止
	while(i!=j){
		//从右向左扫描，找第1个小于pivot的元素
		while(j>i&&L->data[j]>pivot){
			j--;
		}
		//从左向右扫描，找第1个大于pivot的元素
		while(i<j&&L->data[i]<pivot){
			i++;
		}
		//L->data[i]与L->data[j]进行交换
		if(i<j){
			tmp=L->data[i];
			L->data[i]=L->data[j];
			L->data[j]=tmp;
		}
		/*dispList(L);*/
	}
}

/*------------------------------------------------------
* 函数名：exa2_4_move2(书中解法2)
*
* 功  能：对顺序表L，以第一个元素为分界线，将所有小于它的元素移到该元素的前面，
          将大于它的元素移到该元素的后面
*
* 参  数：L，指向顺序表的指针；
*
* 返回值：无
*
* 时间复杂度：
* -----------------------------------------------------*/
void exa2_4_move2(SqList *L){
	int i=0,j=L->length-1;
	//以data[0]为基准
	int pivot = L->data[0];
	//从顺序表两端交替向中间扫描，直至i=j为止
	while(i!=j){
		//从右向左扫描，找一个关键字小于pivot的data[j]
		while(j>i&&L->data[j]>pivot){
			j--;
		}
		//找到这样的data[j],放入data[i]处
		L->data[i]=L->data[j];
		//从左向右扫描，找一个关键字大于pivot的记录data[i]
		while(i<j&&L->data[i]<pivot){
			i++;
		}
		//找到这样的data[i]，放入data[j]处
		L->data[j]=L->data[i];
	}
	L->data[i]=pivot;
}