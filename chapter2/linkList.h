#include "main.h"

//���嵥����������
typedef struct LNode{
	ElemType data;
	//ָ��ֱ�Ӻ�̽��
	struct LNode * next;
}LinkList;

//����˫����������
typedef struct DNode{
	ElemType data;
	//ָ��ǰ�����
	struct DNode *prior;
	//ָ��ֱ�Ӻ�̽��
	struct DNode *next;
}DLinkList;

//��������������ʵ��

/*------------------------------------------------------
* ��������createListF��ͷ�彨����
*
* ��  �ܣ���a�е�n��Ԫ�ش�������
*
* ��  ����L�������ͷ���ָ�룻
		  a���������������
		  n������a�ĳ���
*
* ����ֵ����
*
* ʱ�临�Ӷȣ�O(n)
* -----------------------------------------------------*/
void createListF(LinkList **L,ElemType a[],int n){
	LinkList *s;
	int i;
	//����ͷ���
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
* ��������createListR��β�彨����
*
* ��  �ܣ���a�е�n��Ԫ�ش���˳���
*
* ��  ����L�������ͷ���ָ�룻
		  a���������������
		  n������a�ĳ���
*
* ����ֵ����
*
* ʱ�临�Ӷȣ�O(n)
* -----------------------------------------------------*/
void createListR(LinkList **L,ElemType a[],int n){
	LinkList *s,*r;
	int i;
	//����ͷ���
	*L=(LinkList *)malloc(sizeof(LinkList));
	//rʼ��ָ��β���
	r=*L;
	for(i=0;i<n;i++){
		//ʼ��ָ��β���
		s=(LinkList *)malloc(sizeof(LinkList));
		s->data=a[i];
		//��s����r֮��
		r->next=s;
		r=s;
	}
	//β���next����ΪNULL
	r->next=NULL;
}

/*------------------------------------------------------
* ��������initLinkList
*
* ��  �ܣ���ʼ�����Ա�����һ��ͷ��㣩
*
* ��  ����L�������ͷ��㣻
*
* ����ֵ����
*
* ʱ�临�Ӷȣ�O(1)
* -----------------------------------------------------*/
void initLinkList(LinkList **L){
	//���������ͷ���
	*L=(LinkList *)malloc(sizeof(LinkList));
	(*L)->next=NULL;
}

/*------------------------------------------------------
* ��������destroyLinkList
*
* ��  �ܣ��ͷŵ�����Lռ�õ��ڴ�ռ䣬����һ�ͷ�ȫ�����Ŀռ�
*
* ��  ����L�������ͷ��㣻
*
* ����ֵ����
*
* ʱ�临�Ӷȣ�O(n)
* -----------------------------------------------------*/
void destroyLinkList(LinkList **L){
	LinkList *p=*L,*q=p->next;
	while(q!=NULL){
		free(p);
		p=q;
		q=p->next;
	}
	//��ʱqΪNULL��pָ��β��㣬�ͷ���
	free(p);
}

/*------------------------------------------------------
* ��������linkListEmpty
*
* ��  �ܣ��ж������Ƿ�Ϊ�ձ�
*
* ��  ����L�������ͷ��㣻
*
* ����ֵ��1(��)��0(�ǿ�)
*
* ʱ�临�Ӷȣ�O(1)
* -----------------------------------------------------*/
int linkListEmpty(LinkList *L){
	return(L->next==NULL);
}

/*------------------------------------------------------
* ��������linkListLength
*
* ��  �ܣ����ص����������ݽ��ĸ���
*
* ��  ����L�������ͷ��㣻
*
* ����ֵ�������������ݽ��ĸ��� 
*
* ʱ�临�Ӷȣ�O(n)
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
* ��������dispLinkList
*
* ��  �ܣ���һɨ�赥����L��ÿ�����ݽ��ģ�����ʾ������data��ֵ
*
* ��  ����L�������ͷ��㣻
*
* ����ֵ����
*
* ʱ�临�Ӷȣ�O(n)
* -----------------------------------------------------*/
void dispLinkList(LinkList *L){
	//���Կ���������µ����
	LinkList *p=L->next;
	while(p!=NULL){
		printf("%c ",p->data);
		p=p->next;	
	}
	printf("\n");
}


/*------------------------------------------------------
* ��������getLLElem����������ĳ��Ԫ�ص�ֵ��
*
* ��  �ܣ��ڵ�����L�д�ͷ��ʼ�ҵ���i����㣬�����ڵ�i�����ݽ�㣬
		  ����data��ֵ��������e
*
* ��  ����L�������ͷ��㣻
		  i�����ݵ��߼�λ��
		  e���������ֵ�ı���
*
* ����ֵ��0�������ڵ�i�����ݽ�㣩��1�����ڵ�i�����ݽ�㣩
*
* ʱ�临�Ӷȣ�O(n)
* -----------------------------------------------------*/
int getLLElem(LinkList *L,int i,ElemType *e){
	//����ʾ�������ǲ���ȫ�棩
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
	//pָ��ͷ���
	LinkList *p=L;
	while(j<i&&p!=NULL){
		j++;
		p=p->next;
	}
	//�����ڵ�i�����ݽ��
	if(p==NULL){
		return 0;
	}
	//���ڵ�i�����ݽ��
	else{
		*e=p->data;
		return 1;
	}
}

/*------------------------------------------------------
* ��������locateLLElem����Ԫ�ز��ң�
*
* ��  �ܣ��ڵ�����L�д�ͷ��ʼ�ҵ���һ��ֵ����e��ȵĽ�㣬
		  �����������Ľ�㣬�򷵻�λ�ã����򷵻�0
*
* ��  ����L�������ͷ��㣻
		  e���������ֵ�ı���
*
* ����ֵ��0�����������������ݽ�㣩��i�������ݽ���λ����i��
*
* ʱ�临�Ӷȣ�O(n)
* -----------------------------------------------------*/
int locateLLElem(LinkList *L,ElemType e){
	int i=1;
	//pָ���һ�����ݽ��
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
* ��������linkListInsert����������Ԫ�أ�
*
* ��  �ܣ����ڵ�����L���ҵ���i-1�����*p�������������Ľ�㣬��
		  ֵΪe�Ľ��*s�������
*
* ��  ����L�������ͷ��㣻
		  i�����������ݵ��߼�λ��
		  e�����������ݵ�ֵ
*
* ����ֵ��0��δ�ҵ�λ��i����1������ɹ���
*
* ʱ�临�Ӷȣ�O(n)
* -----------------------------------------------------*/
int linkListInsert(LinkList **L,int i,ElemType e){
	int j;
	LinkList *s;
	LinkList *p=(*L)->next;
	//���ҵ�i-1�����
	while(j<i-1&&p!=NULL){
		p=p->next;
		j++;
	}
	//δ�ҵ��߼�λ��Ϊi-1�Ľ��
	if(p==NULL){
		return 0;
	}
	//�ҵ��߼�λ��Ϊi-1�Ľ��
	//�����½��
	s=(LinkList *)malloc(sizeof(LinkList));
	s->data=e;
	//��*s���뵽*p��
	s->next=p->next;
	p->next=s;
	return 1;
}

/*------------------------------------------------------
* ��������linkListDelete��ɾ������Ԫ�أ�
*
* ��  �ܣ��ڵ�����L�д�ͷ��ʼ�ҵ���i-1����㣬�����������Ľ�㣬
		  ��Ҳ����ֱ�Ӻ�̽�㣬��ɾ����ֱ�Ӻ�̽��
*
* ��  ����L�������ͷ��㣻
		  i����ɾ�����ݵ��߼�λ��
		  e����Ŵ�ɾ������ֵ
*
* ����ֵ��0�������ڵ�i�����ݽ�㣩��1��ɾ���ɹ���
*
* ʱ�临�Ӷȣ�O(n)
* -----------------------------------------------------*/
int linkListDelete(LinkList **L,int i,ElemType *e){
	int j=1;
	LinkList *p=(*L)->next,*q;
	//���ҵ�i-1�����
	while(j>i-1&&p!=NULL){
		p=p->next;
		j++;
	}
	//δ�ҵ��߼�λ��Ϊi-1�Ľ��
	if(p==NULL){
		return 0;
	}
	//�ҵ��߼�λ��Ϊi-1�Ľ��*p
	//qָ��Ҫɾ���Ľڵ�
	q=p->next;
	//�������ڵ�i�����
	if(q==NULL){
		return 0;
	}
	//���ڵ�i�����
	//�ӵ�������ɾ�����q
	p->next=q->next;
	*e=q->data;
	//�ͷ�*q���
	free(q);
	return 1;
	
}

/*------------------------------------------------------
* ��������createDLListF
*
* ��  �ܣ�������a����˫����
*
* ��  ��������ͷ�巨
*
* ��  ����L��˫�����ͷ��㣻
		  a���ο�����
		  n�����鳤��s
*
* ����ֵ����
*
* ʱ�临�Ӷȣ�
* -----------------------------------------------------*/
void createDLListF(DLinkList **L,ElemType a[],int n){
	DLinkList *s;
	int i;
	//����ͷ���
	*L=(DLinkList *)malloc(sizeof(DLinkList));
	(*L)->next=(*L)->prior=NULL;
	for(i=0;i<n;i++){
		//�����½��
		s=(DLinkList *)malloc(sizeof(DLinkList));
		s->data=a[i];
		//��*s����ԭ��ʼ���֮ǰ��ͷ���֮��
		s->next=(*L)->next;
		if((*L)->next!=NULL){
			(*L)->next->prior=s;
		}
		(*L)->next=s;
		s->prior=(*L);
	}
}

/*------------------------------------------------------
* ��������createDLListR
*
* ��  �ܣ�������a����˫����
*
* ��  ��������β�巨
*
* ��  ����L��˫�����ͷ��㣻
		  a���ο�����
		  n�����鳤��s
*
* ����ֵ����
*
* ʱ�临�Ӷȣ�
* -----------------------------------------------------*/
void createDLListR(DLinkList **L,ElemType a[],int n){
	DLinkList *s,*r;
	int i;
	//����ͷ���
	*L=(DLinkList *)malloc(sizeof(DLinkList));
	(*L)->next=(*L)->prior=NULL;
	//rʼ��ָ��β��㣬��ʼʱָ��ͷ���
	r=*L;
	for(i=0;i<n;i++){
		//�����½��
		s=(DLinkList *)malloc(sizeof(DLinkList));
		s->data=a[i];
		//��*s����*r֮��
		r->next=s;
		s->prior=r;
		//rָ��s���
		r=s;
	}
	//β���next����ΪNULL
	r->next=NULL;
}


/*------------------------------------------------------
* ��������dLinkListInsert
*
* ��  �ܣ���ָ��λ�ò�����Ԫ��
*
* ��  ������˫����L�еĵ�i��λ���ϲ���ֵΪe��Ԫ��
*
* ��  ����L��˫�����ͷ��㣻
		  i��������Ԫ�ص�λ��
		  e��������Ԫ�ص���ֵ
*
* ����ֵ��0��������󣺲�����λ��i����1������ɹ���
*
* ʱ�临�Ӷȣ�O(n)
* -----------------------------------------------------*/
int dLinkListInsert(DLinkList **L,int i,ElemType e){
	int n=1;
	DLinkList *s,*p=(*L)->next;
	//���ҵ���i-1��Ԫ��
	while(n<i-1&&p!=NULL){
		n++;
		p=p->next;
	}
	//δ�ҵ��߼�λ��Ϊi-1�Ľ��
	if(p==NULL){
		return 0;
	}
	//�ҵ��߼�λ��Ϊi-1�Ľ��
	//�½�һ��Ԫ��
	s=(DLinkList *)malloc(sizeof(DLinkList));
	s->data=e;
	//����Ԫ�ط��ڵ�i-1��Ԫ�غ���
	s->next=p->next;
	if(p->next!=NULL){
		p->next->prior=s;
	}
	p->next=s;
	s->prior=p;
	return 1;
}

/*------------------------------------------------------
* ��������dLinkListDelete
*
* ��  �ܣ�ɾ��ָ��λ�õ�Ԫ�أ������ظ�Ԫ��ֵ
*
* ��  ����ɾ��˫����L�еĵ�i��λ����Ԫ��
*
* ��  ����L��˫�����ͷ��㣻
		  i����ɾ��Ԫ�ص�λ��
		  e����ɾ��Ԫ�ص���ֵ
*
* ����ֵ��0��ɾ�����󣺲�����λ��i����1��ɾ���ɹ���
*
* ʱ�临�Ӷȣ�O(n)
* -----------------------------------------------------*/
int dLinkListDelete(DLinkList **L,int i,ElemType *e){
	int n=1;
	DLinkList *p=(*L)->next,*s;
	//���ҵ���i-1��Ԫ��
	while(n<i-1&&p!=NULL){
		n++;
		p=p->next;
	}
	//���Ҳ�����i-1��Ԫ��
	if(p==NULL){
		return 0;
	}
	//��i�����
	s=p->next;
	//��������ڵ�i�����
	if(s==NULL){
		return 0;
	}
	//������ڵ�i�����
	*e=s->data;
	//ɾ����i�����
	p->next=s->next;
	if(s->next!=NULL){
		s->next->prior=p;
	}
	//�ͷ�ԭ��i�����Ŀռ�
	free(s);
	return 1;
}

		
/*------------------------------------------------------
* ��������dispDLinkList
*
* ��  �ܣ���ӡ˫����
*
* ��  ��������˫�������ݽ�������ֵ���δ�ӡ����
*
* ��  ����L��˫�����ͷ��㣻
*
* ����ֵ����
*
* ʱ�临�Ӷȣ�O(n)
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
* ��������dLinkListLength
*
* ��  �ܣ����˫����ĳ���
*
* ��  ����ͳ��˫��������Ԫ�صĸ���
*
* ��  ����L��˫�����ͷ��㣻
*
* ����ֵ��0��˫����Ϊ�գ���˫�������ݽ�����
*
* ʱ�临�Ӷȣ�O(n)
* -----------------------------------------------------*/
int dLinkListLength(DLinkList*L){
	int length=1;
	DLinkList *p=L->next;
	//˫����Ϊ��
	if(p==NULL){
		return 0;
	}
	while(p!=NULL){
		length++;
		p=p->next;
	}
	return length;
}