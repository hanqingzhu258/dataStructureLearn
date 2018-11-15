#include <stdio.h>
#include "linkList.h"

//exa2-5
void split(LinkList **L,LinkList **L1,LinkList **L2);
//exa2-6
void sort_exa2_6(LinkList **L);
//exa2-7
void reverse_exa2_7(DLinkList **L);
//exa2-8
void sort_exa2_8(DLinkList **L);

//测试主函数
void main(){

	//exa2-7
	/*ElemType a[7]={'a','b','c','d','e','f','g'};
	//定义双链表的头结点
	DLinkList *L;
	//利用数组a创建该双链表
	createDLListR(&L,a,7);
	dispDLinkList(L);
	reverse_exa2_7(&L);
	dispDLinkList(L);*/

	//exa2_8
	ElemType a[7]={'a','c','b','e','g','f','d'};
	//定义双链表的头结点
	DLinkList *L;
	//利用数组a创建该双链表
	createDLListR(&L,a,7);
	dispDLinkList(L);
	sort_exa2_8(&L);
	dispDLinkList(L);

}

/*------------------------------------------------------
* 函数名：split
*
* 功  能：在一个带头结点的单链表L={a1,b1,a2,b2,...,an,bn},
		  设计一个算法将其拆分成两个带头节点的单链表L1,L2，
		  L1={a1,a2,...,an},L2={bn,...,b2,b1}。要求L1使用L的头结点
*
* 描  述：利用原单链表L中的所有结点，采用尾插法建立单链表L1，
		  采用头插法建立单链表L2
*
* 参  数：L，待拆分链表；
		  L1，使用L头的拆分列表1；
		  L2，拆分列表2
*
* 返回值：无
*
* 时间复杂度：O(n)
* -----------------------------------------------------*/
void split(LinkList **L,LinkList **L1,LinkList **L2){
	//p指向第1个数据结点
	LinkList *p=(*L)->next,*q,*r1;
	//L1利用原来L的头结点
	*L1=*L;
	//r1始终指向L1的尾结点
	r1=*L1;
	//创建L2的头结点
	*L2=(LinkList *)malloc(sizeof(LinkList));
	(*L2)->next=NULL;
	while(p!=NULL){
		//q指向p的直接后继结点
		q=p->next;
		//采用尾插法将p插入L1中
		r1->next=p;
		r1=p;
		//p指向下一轮
		p=q->next;
		//采用头插法将q插入L2中
		q->next=(*L2)->next;
		(*L2)->next=q;
	}
	//尾结点next置空
	r1->next=NULL;
}		

/*------------------------------------------------------
* 函数名：sort_exa2_6
*
* 功  能：有一个带头结点的单链表L，设计一个算法使其元素递增有序排列
*
* 描  述：若原单链表中有一个或以上的数据结点，先构造只含一个数据结点的有序表，
		  （只含一个数据结点的单链表一定是有序表）。扫描原单链表余下的结点*p
		  （直到p==NULL为止），在有序表中通过比较，找插入*p的直接前驱结点*q，
		  然后将*p插入到*q之后（这里实际上采用的是直接插入排序方法）
*
* 参  数：L，待排序链表的头结点；
*
* 返回值：无
*
* 时间复杂度：
* -----------------------------------------------------*/
void sort_exa2_6(LinkList **L){
	//p指向第1个数据结点
	LinkList *p=(*L)->next,*q,*r;
	//若原单链表中有一个或以上的数据结点
	if(p!=NULL){
		//r保存*p结点直接后继结点的指针
		r=p->next;
		//构造只含一个数据结点的有序表
		p->next=NULL;
		p=r;
		while(p!=NULL){
			//r保存*p结点直接后继结点的指针
			r=p->next;
			q=(*L);
			//在有序表中找插入*p的直接前驱结点*q的位置
			while(q->next!=NULL&&q->next->data<p->data){
				q=q->next;
			}
			//将*p插入到*q之后
			p->next=q->next;
			q->next=p;
			//扫描原单链表余下的结点
			p=r;
		}
	}
}

/*------------------------------------------------------
* 函数名：reverse_exa2_7
*
* 功  能：有一个带头结点的双链表L，设计一个算法将其所有元素逆置
*
* 描  述：先构造只有一个头结点的双链表L（利用原来的头结点），
		  用p扫描双链表所有结点，采用头插法将*p结点插入到L中
*
* 参  数：L，待排序链表的头结点；
*
* 返回值：无
*
* 时间复杂度：
* -----------------------------------------------------*/
void reverse_exa2_7(DLinkList **L){
	//s指向第1个数据结点
	DLinkList *s=(*L)->next,*p;
	(*L)->next=NULL;
	while(s!=NULL){
		//p指向*s的直接后继结点
		p=s->next;
		//采用头插法将*p结点的数据插入到双链表中
		s->next=(*L)->next;
		if((*L)->next!=NULL){
			(*L)->next->prior=s;
		}
		(*L)->next=s;
		s->prior=(*L);
		s=p;
	}
}

/*------------------------------------------------------
* 函数名：sort_exa2_8
*
* 功  能：有一个带头结点的双链表L，设计一个算法将其元素递增有序排列
*
* 描  述：
*
* 参  数：L，待排序链表的头结点；
*
* 返回值：无
*
* 时间复杂度：
* -----------------------------------------------------*/
void sort_exa2_8(DLinkList **L){
	DLinkList *p=(*L)->next,*s,*q=(*L)->next;

	/*printf("方法 sort_exa2_8 正在执行");*/

	s=p->next;
	//构建只含一个数据元素的双链表
	p->next=NULL;
	
	//对原双链表剩下的元素进行循环插入
	while(s!=NULL){

		//保存原双链表的下一个元素的位置
		p=s->next;
		//找到要插入的位置
		q=(*L)->next;
		while(q->next!=NULL&&q->next->data<s->data){
			q=q->next;
		}

		//将该元素插入所找元素的后面
		s->next=q->next;
		//如果所找元素不是最后一个元素
		if(q->next!=NULL){
			q->next->prior=s;
		}
		q->next=s;
		s->prior=q;

		//指向下一轮循环
		s=p;
	}
}
