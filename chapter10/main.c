//
// Description: 
// Created by hanqing zhu on 2018/12/3.
//

#include <stdio.h>
#include "main.h"
#include "sort.h"

void main(){

    RecType r[MaxSize];
    int n=10;
//    int x[MaxSize]={9,8,7,6,5,4,3,2,1,0};
    int x[MaxSize]={1,3,6,5,2,4,7,0,9,8};
    /*int n=6;
    int x[MaxSize]={6,8,5,7,9,0};*/
    initSortRec(r,x,n);
    printf("init:");
    printSortRec(r,n);

    //test_insertsort_direct
    initSortRec(r,x,n);
    insertSort_direct(r,n);
    printf("insertSort_direct:");
    printSortRec(r,n);
    //test_insertsort_direct_book
    initSortRec(r,x,n);
    insertSort_direct_book(r,n);
    printf("insertSort_direct_book:");
    printSortRec(r,n);
    //test_insertsort_binary
    initSortRec(r,x,n);
    insertSort_binary(r,n);
    printf("insertSort_binary:");
    printSortRec(r,n);
    //test_shellSort
    initSortRec(r,x,n);
    shellSort(r,n);
    printf("shellSort:");
    printSortRec(r,n);

    //test_bubbleSort
    initSortRec(r,x,n);
    bubbleSort(r,n);
    printf("bubbleSort:");
    printSortRec(r,n);
    //test_quickSort
    initSortRec(r,x,n);
    quickSort(r,0,n-1);
    printf("quickSort:");
    printSortRec(r,n);
    //test_quickSort1
    initSortRec(r,x,n);
    quickSort1(r,0,n-1);
    printf("quickSort1:");
    printSortRec(r,n);

    //test_selectSort
    initSortRec(r,x,n);
    selectSort(r,n);
    printf("selectSort:");
    printSortRec(r,n);
    //test_heapSort
    initSortRec(r,x,n);
    heapSort(r,n);
    printf("heapSort:");
    printSortRec(r,n);

    //test_mergeSort
    initSortRec(r,x,n);
    mergeSort(r,n);
    printf("mergeSort:");
    printSortRec(r,n);
    //test_mergeSort1
    initSortRec(r,x,n);
    mergeSort1(r,n);
    printf("mergeSort1:");
    printSortRec(r,n);
}

/*------------------------------------------------------
 * 函数名：initSortRec
 *
 * 功  能：初始化待排序数组
 *
 * 描  述：稳定排序，就地排序
 *
 * 参  数：r，待排序数组；
 *        x，关键字数组；
 *        n，记录总数。
 *
 * 返回值：无
 *
 * 时间复杂度：O(n^2)
 *
 * author： hanqing zhu 2018/12/3 15:59
 * -----------------------------------------------------*/
void initSortRec(RecType *r,KeyType x[],int n){
    int i;
    for (i=0;i<n;i++){
        r[i].key=x[i];
    }
}

/*------------------------------------------------------
 * 函数名：printSortRec
 *
 * 功  能：输出记录数组
 *
 * 描  述：
 *
 * 参  数：r，待输出数组；
 *        n，记录总数。
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/12/3 16:14
 * -----------------------------------------------------*/
void printSortRec(RecType r[],int n){
    int i;
    printf("[");
    for (i=0;i<n;i++){
        printf("%d",r[i].key);
        if (i!=n-1){
            printf(",");
        }
    }
    printf("]\n");
}