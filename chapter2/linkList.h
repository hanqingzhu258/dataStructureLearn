#include "main.h"

//定义单链表结点类型
typedef struct LNode{
	ElemType data;
	//指向直接后继结点
	struct LNode * next;
}LinkList;

//定义双链表结点类型
typedef struct DNode{
	ElemType data;
	//指向前驱结点
	struct DNode *prior;
	//指向直接后继结点
	struct DNode *next;
}DLinkList;

//单链表基本运算的实现

/*------------------------------------------------------
* 函数名：createListF（头插建表法）
*
* 功  能：由a中的n个元素创建链表
*
* 参  数：L，链表的头结点指针；
		  a，创建链表的数组
		  n，数组a的长度
*
* 返回值：无
*
* 时间复杂度：O(n)
* -----------------------------------------------------*/
void createListF(LinkList **L,ElemType a[],int n){
	LinkList *s;
	int i;
	//创建头结点
	*L=(LinkList *)malloc(sizeof(LinkList));
	(*L)->next=NULL;
	for(i=0;i<n;i++){
		s=(LinkList *)malloc(sizeof(LinkList));
		s->data=a[i];
		s->next=(*L)->next;
		(*L)->next=s;
	}
}

/*------------------------------------------------------
* 函数名：createListR（尾插建表法）
*
* 功  能：由a中的n个元素创建顺序表
*
* 参  数：L，链表的头结点指针；
		  a，创建链表的数组
		  n，数组a的长度
*
* 返回值：无
*
* 时间复杂度：O(n)
* -----------------------------------------------------*/
void createListR(LinkList **L,ElemType a[],int n){
	LinkList *s,*r;
	int i;
	//创建头结点
	*L=(LinkList *)malloc(sizeof(LinkList));
	//r始终指向尾结点
	r=*L;
	for(i=0;i<n;i++){
		//始终指向尾结点
		s=(LinkList *)malloc(sizeof(LinkList));
		s->data=a[i];
		//将s插入r之后
		r->next=s;
		r=s;
	}
	//尾结点next域置为NULL
	r->next=NULL;
}

/*------------------------------------------------------
* 函数名：initLinkList
*
* 功  能：初始化线性表（创建一个头结点）
*
* 参  数：L，链表的头结点；
*
* 返回值：无
*
* 时间复杂度：O(1)
* -----------------------------------------------------*/
void initLinkList(LinkList **L){
	//创建链表的头结点
	*L=(LinkList *)malloc(sizeof(LinkList));
	(*L)->next=NULL;
}

/*------------------------------------------------------
* 函数名：destroyLinkList
*
* 功  能：释放单链表L占用的内存空间，即逐一释放全部结点的空间
*
* 参  数：L，链表的头结点；
*
* 返回值：无
*
* 时间复杂度：O(n)
* -----------------------------------------------------*/
void destroyLinkList(LinkList **L){
	LinkList *p=*L,*q=p->next;
	while(q!=NULL){
		free(p);
		p=q;
		q=p->next;
	}
	//此时q为NULL，p指向尾结点，释放它
	free(p);
}

/*------------------------------------------------------
* 函数名：linkListEmpty
*
* 功  能：判断链表是否为空表
*
* 参  数：L，链表的头结点；
*
* 返回值：1(空)或0(非空)
*
* 时间复杂度：O(1)
* -----------------------------------------------------*/
int linkListEmpty(LinkList *L){
	return(L->next==NULL);
}

/*------------------------------------------------------
* 函数名：linkListLength
*
* 功  能：返回单链表中数据结点的个数
*
* 参  数：L，链表的头结点；
*
* 返回值：单链表中数据结点的个数 
*
* 时间复杂度：O(n)
* -----------------------------------------------------*/
int linkListLength(LinkList *L){
	int length=0;
	LinkList *p=L;
	if(L->next==NULL){
		return 0;
	}
	if(p->next!=NULL){
		length++;
		p=p->next;
	}
	return length;
}

/*------------------------------------------------------
* 函数名：dispLinkList
*
* 功  能：逐一扫描单链表L的每个数据结点的，并显示各结点的data域值
*
* 参  数：L，链表的头结点；
*
* 返回值：无
*
* 时间复杂度：O(n)
* -----------------------------------------------------*/
void dispLinkList(LinkList *L){
	//忽略空链表情况下的输出
	LinkList *p=L->next;
	while(p!=NULL){
		printf("%c ",p->data);
		p=p->next;	
	}
	printf("\n");
}


/*------------------------------------------------------
* 函数名：getLLElem（求链表中某个元素的值）
*
* 功  能：在单链表L中从头开始找到第i个结点，若存在第i个数据结点，
		  则将其data域值赋给变量e
*
* 参  数：L，链表的头结点；
		  i，数据的逻辑位序；
		  e，存放数据值的变量
*
* 返回值：0（不存在第i个数据结点）或1（存在第i个数据结点）
*
* 时间复杂度：O(n)
* -----------------------------------------------------*/
int getLLElem(LinkList *L,int i,ElemType *e){
	//错误示范（考虑不够全面）
	/*int n=0;
	LinkList *p=L->next;
	while(p!=NULL){
		n++;
		if(n==i){
			*e=p->data;
			break;
		}else{
			p->next;
		}
	}*/
	int j=0;
	//p指向头结点
	LinkList *p=L;
	while(j<i&&p!=NULL){
		j++;
		p=p->next;
	}
	//不存在第i个数据结点
	if(p==NULL){
		return 0;
	}
	//存在第i个数据结点
	else{
		*e=p->data;
		return 1;
	}
}

/*------------------------------------------------------
* 函数名：locateLLElem（按元素查找）
*
* 功  能：在单链表L中从头开始找到第一个值域与e相等的结点，
		  若存在这样的结点，则返回位置，否则返回0
*
* 参  数：L，链表的头结点；
		  e，存放数据值的变量
*
* 返回值：0（不存在这样的数据结点）或i（该数据结点的位置是i）
*
* 时间复杂度：O(n)
* -----------------------------------------------------*/
int locateLLElem(LinkList *L,ElemType e){
	int i=1;
	//p指向第一个数据结点
	LinkList *p=L->next;
	while(p!=NULL&&p->data!=e){
		p=p->next;
		i++;
	}
	if(p==NULL){
		return(0);
	}
	return(i);
}

/*------------------------------------------------------
* 函数名：linkListInsert（插入数据元素）
*
* 功  能：先在单链表L中找到第i-1个结点*p，若存在这样的结点，将
		  值为e的结点*s插入其后
*
* 参  数：L，链表的头结点；
		  i，待插入数据的逻辑位序；
		  e，待插入数据的值
*
* 返回值：0（未找到位置i）或1（插入成功）
*
* 时间复杂度：O(n)
* -----------------------------------------------------*/
int linkListInsert(LinkList **L,int i,ElemType e){
	int j;
	LinkList *s;
	LinkList *p=(*L)->next;
	//查找第i-1个结点
	while(j<i-1&&p!=NULL){
		p=p->next;
		j++;
	}
	//未找到逻辑位序为i-1的结点
	if(p==NULL){
		return 0;
	}
	//找到逻辑位序为i-1的结点
	//创建新结点
	s=(LinkList *)malloc(sizeof(LinkList));
	s->data=e;
	//将*s插入到*p后
	s->next=p->next;
	p->next=s;
	return 1;
}

/*------------------------------------------------------
* 函数名：linkListDelete（删除数据元素）
*
* 功  能：在单链表L中从头开始找到第i-1个结点，若存在这样的结点，
		  且也存在直接后继结点，则删除该直接后继结点
*
* 参  数：L，链表的头结点；
		  i，待删除数据的逻辑位序；
		  e，存放待删除数据值
*
* 返回值：0（不存在第i个数据结点）或1（删除成功）
*
* 时间复杂度：O(n)
* -----------------------------------------------------*/
int linkListDelete(LinkList **L,int i,ElemType *e){
	int j=1;
	LinkList *p=(*L)->next,*q;
	//查找第i-1个结点
	while(j>i-1&&p!=NULL){
		p=p->next;
		j++;
	}
	//未找到逻辑位序为i-1的结点
	if(p==NULL){
		return 0;
	}
	//找到逻辑位序为i-1的结点*p
	//q指向要删除的节点
	q=p->next;
	//若不存在第i个结点
	if(q==NULL){
		return 0;
	}
	//存在第i个结点
	//从单链表中删除结点q
	p->next=q->next;
	*e=q->data;
	//释放*q结点
	free(q);
	return 1;
	
}

/*------------------------------------------------------
* 函数名：createDLListF
*
* 功  能：由数组a建立双链表
*
* 描  述：利用头插法
*
* 参  数：L，双链表的头结点；
		  a，参考数组
		  n，数组长度s
*
* 返回值：无
*
* 时间复杂度：
* -----------------------------------------------------*/
void createDLListF(DLinkList **L,ElemType a[],int n){
	DLinkList *s;
	int i;
	//创建头结点
	*L=(DLinkList *)malloc(sizeof(DLinkList));
	(*L)->next=(*L)->prior=NULL;
	for(i=0;i<n;i++){
		//创建新结点
		s=(DLinkList *)malloc(sizeof(DLinkList));
		s->data=a[i];
		//将*s插在原开始结点之前，头结点之后
		s->next=(*L)->next;
		if((*L)->next!=NULL){
			(*L)->next->prior=s;
		}
		(*L)->next=s;
		s->prior=(*L);
	}
}

/*------------------------------------------------------
* 函数名：createDLListR
*
* 功  能：由数组a建立双链表
*
* 描  述：利用尾插法
*
* 参  数：L，双链表的头结点；
		  a，参考数组
		  n，数组长度s
*
* 返回值：无
*
* 时间复杂度：
* -----------------------------------------------------*/
void createDLListR(DLinkList **L,ElemType a[],int n){
	DLinkList *s,*r;
	int i;
	//创建头结点
	*L=(DLinkList *)malloc(sizeof(DLinkList));
	(*L)->next=(*L)->prior=NULL;
	//r始终指向尾结点，开始时指向头结点
	r=*L;
	for(i=0;i<n;i++){
		//创建新结点
		s=(DLinkList *)malloc(sizeof(DLinkList));
		s->data=a[i];
		//将*s插入*r之后
		r->next=s;
		s->prior=r;
		//r指向s结点
		r=s;
	}
	//尾结点next域置为NULL
	r->next=NULL;
}


/*------------------------------------------------------
* 函数名：dLinkListInsert
*
* 功  能：在指定位置插入新元素
*
* 描  述：在双链表L中的第i个位置上插入值为e的元素
*
* 参  数：L，双链表的头结点；
		  i，待插入元素的位置
		  e，待插入元素的数值
*
* 返回值：0（插入错误：不存在位置i）或1（插入成功）
*
* 时间复杂度：O(n)
* -----------------------------------------------------*/
int dLinkListInsert(DLinkList **L,int i,ElemType e){
	int n=1;
	DLinkList *s,*p=(*L)->next;
	//先找到第i-1个元素
	while(n<i-1&&p!=NULL){
		n++;
		p=p->next;
	}
	//未找到逻辑位序为i-1的结点
	if(p==NULL){
		return 0;
	}
	//找到逻辑位序为i-1的结点
	//新建一个元素
	s=(DLinkList *)malloc(sizeof(DLinkList));
	s->data=e;
	//将新元素放在第i-1个元素后面
	s->next=p->next;
	if(p->next!=NULL){
		p->next->prior=s;
	}
	p->next=s;
	s->prior=p;
	return 1;
}

/*------------------------------------------------------
* 函数名：dLinkListDelete
*
* 功  能：删除指定位置的元素，并返回该元素值
*
* 描  述：删除双链表L中的第i个位置上元素
*
* 参  数：L，双链表的头结点；
		  i，待删除元素的位置
		  e，待删除元素的数值
*
* 返回值：0（删除错误：不存在位置i）或1（删除成功）
*
* 时间复杂度：O(n)
* -----------------------------------------------------*/
int dLinkListDelete(DLinkList **L,int i,ElemType *e){
	int n=1;
	DLinkList *p=(*L)->next,*s;
	//先找到第i-1个元素
	while(n<i-1&&p!=NULL){
		n++;
		p=p->next;
	}
	//若找不到第i-1个元素
	if(p==NULL){
		return 0;
	}
	//第i个结点
	s=p->next;
	//如果不存在第i个结点
	if(s==NULL){
		return 0;
	}
	//如果存在第i个结点
	*e=s->data;
	//删除第i个结点
	p->next=s->next;
	if(s->next!=NULL){
		s->next->prior=p;
	}
	//释放原第i个结点的空间
	free(s);
	return 1;
}

		
/*------------------------------------------------------
* 函数名：dispDLinkList
*
* 功  能：打印双链表
*
* 描  述：将该双链表数据结点的数据值依次打印出来
*
* 参  数：L，双链表的头结点；
*
* 返回值：无
*
* 时间复杂度：O(n)
* -----------------------------------------------------*/
void dispDLinkList(DLinkList *L){
	DLinkList *p=L->next;
	while(p!=NULL){
		printf("%c ",p->data);
		p=p->next;
	}
	printf("\n");
}

/*------------------------------------------------------
* 函数名：dLinkListLength
*
* 功  能：输出双链表的长度
*
* 描  述：统计双链表数据元素的个数
*
* 参  数：L，双链表的头结点；
*
* 返回值：0（双链表为空）或双链表数据结点个数
*
* 时间复杂度：O(n)
* -----------------------------------------------------*/
int dLinkListLength(DLinkList*L){
	int length=1;
	DLinkList *p=L->next;
	//双链表为空
	if(p==NULL){
		return 0;
	}
	while(p!=NULL){
		length++;
		p=p->next;
	}
	return length;
}