#include <stdio.h>
#include <stdlib.h>

struct TEST{
    int n;
    struct TEST *next;
};

typedef  struct TEST T;


void main() {


    void test(T **t);
    void test1(T *t);

    T *t1=(T *)malloc(sizeof(T));
    T *t2=(T *)malloc(sizeof(T));
    t1->n=1;
    t2->n=2;
    t1->next=t2;
    printf("%d\n",t1->next->n);
//    test(&(t1->next));
    test1(t1->next);
    if (t1->next!=NULL){
        printf("%d",t1->next->n);
    }else{
        printf("ssssssssss");
    }


}

void test(T **t){
    *t=NULL;
}

void test1(T *t){
    t=NULL;
}