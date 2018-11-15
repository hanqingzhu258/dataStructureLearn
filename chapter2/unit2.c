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
	//��ʽ2(����)
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
	printf("����exa2_4�����\n");
	dispList(L);*/
	/*exa2_4_move1(L);
	printf("����exa2_4_move1�����\n");
	dispList(L);*/
	/*exa2_4_move2(L);
	printf("����exa2_4_move2�����\n");
	dispList(L);*/
//}


/*------------------------------------------------------
* ��������deletem
*
* ��  �ܣ�ɾ��˳�����Ԫ��ֵ��[x,y]֮�������Ԫ��
*
* ��  ����L��ָ��˳����ָ�룻
		  x�������ֵ
		  y���ҽ���ֵ
*
* ����ֵ����
*
* ʱ�临�Ӷȣ�O(n)��O(L->length)
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
* ��������exa2_4(ԭ������:ֻ��һ��whileѭ��ʵ��)
*
* ��  �ܣ���˳���L���Ե�һ��Ԫ��Ϊ�ֽ��ߣ�������С������Ԫ���Ƶ���Ԫ�ص�ǰ�棬
          ����������Ԫ���Ƶ���Ԫ�صĺ���
*
* ��  ����L��ָ��˳����ָ�룻
*
* ����ֵ����
*
* ʱ�临�Ӷȣ�O(n)��O(L->length)//��Ϊֻɨ����һ���L
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
	
	/*printf("������exa2_4ִ�н�����");*/
}

/*------------------------------------------------------
* ��������exa2_4_move1(���нⷨ1)
*
* ��  �ܣ���˳���L���Ե�һ��Ԫ��Ϊ�ֽ��ߣ�������С������Ԫ���Ƶ���Ԫ�ص�ǰ�棬
          ����������Ԫ���Ƶ���Ԫ�صĺ���
*
* ��  ����L��ָ��˳����ָ�룻
*
* ����ֵ����
*
* ʱ�临�Ӷȣ�
* -----------------------------------------------------*/
void exa2_4_move1(SqList *L){
	int i=0,j=L->length-1;
	//��data[0]Ϊ��׼
	int pivot=L->data[0];           
	int tmp;
	//���������˽������м�ɨ�棬ֱ��i=jΪֹ
	while(i!=j){
		//��������ɨ�裬�ҵ�1��С��pivot��Ԫ��
		while(j>i&&L->data[j]>pivot){
			j--;
		}
		//��������ɨ�裬�ҵ�1������pivot��Ԫ��
		while(i<j&&L->data[i]<pivot){
			i++;
		}
		//L->data[i]��L->data[j]���н���
		if(i<j){
			tmp=L->data[i];
			L->data[i]=L->data[j];
			L->data[j]=tmp;
		}
		/*dispList(L);*/
	}
}

/*------------------------------------------------------
* ��������exa2_4_move2(���нⷨ2)
*
* ��  �ܣ���˳���L���Ե�һ��Ԫ��Ϊ�ֽ��ߣ�������С������Ԫ���Ƶ���Ԫ�ص�ǰ�棬
          ����������Ԫ���Ƶ���Ԫ�صĺ���
*
* ��  ����L��ָ��˳����ָ�룻
*
* ����ֵ����
*
* ʱ�临�Ӷȣ�
* -----------------------------------------------------*/
void exa2_4_move2(SqList *L){
	int i=0,j=L->length-1;
	//��data[0]Ϊ��׼
	int pivot = L->data[0];
	//��˳������˽������м�ɨ�裬ֱ��i=jΪֹ
	while(i!=j){
		//��������ɨ�裬��һ���ؼ���С��pivot��data[j]
		while(j>i&&L->data[j]>pivot){
			j--;
		}
		//�ҵ�������data[j],����data[i]��
		L->data[i]=L->data[j];
		//��������ɨ�裬��һ���ؼ��ִ���pivot�ļ�¼data[i]
		while(i<j&&L->data[i]<pivot){
			i++;
		}
		//�ҵ�������data[i]������data[j]��
		L->data[j]=L->data[i];
	}
	L->data[i]=pivot;
}