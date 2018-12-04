//
// Description: 插入排序：直接插入排序、二分插入排序、希尔排序
// Created by hanqing zhu on 2018/12/3.
//


#ifndef CHAPTER10_INSERTSORT_H
#define CHAPTER10_INSERTSORT_H

#include "main.h"

//插入排序
/*------------------------------------------------------
 *
 * 直接插入排序
 *
 * author： hanqing zhu 2018/12/3 15:42
 * -----------------------------------------------------*/
void insertSort_direct(RecType r[],int n);
void insertSort_direct_book(RecType r[],int n);

/*------------------------------------------------------
 *
 * 二分（折半）插入排序
 *
 * author： hanqing zhu 2018/12/3 17:17
 * -----------------------------------------------------*/
void insertSort_binary(RecType r[],int n);

/*------------------------------------------------------
 *
 * 希尔排序
 *
 * author： hanqing zhu 2018/12/3 20:25
 * -----------------------------------------------------*/
void shellSort(RecType r[],int n);

//交换排序
/*------------------------------------------------------
 *
 * 冒泡排序
 *
 * author： hanqing zhu 2018/12/3 21:11
 * -----------------------------------------------------*/
void bubbleSort(RecType r[],int n);

/*------------------------------------------------------
 *
 * 快速排序
 *
 * author： hanqing zhu 2018/12/4 9:26
 * -----------------------------------------------------*/
void quickSort(RecType r[],int s,int t);
void quickSort1(RecType r[],int s,int t);

//选择排序
/*------------------------------------------------------
 *
 * 直接选择排序
 *
 * author： hanqing zhu 2018/12/4 10:28
 * -----------------------------------------------------*/
void selectSort(RecType r[],int n);

/*------------------------------------------------------
 *
 * 堆排序
 *
 * author： hanqing zhu 2018/12/4 16:06
 * -----------------------------------------------------*/
void heapSort(RecType r[],int n);
void sift(RecType r[],int low,int high);

//归并排序
void merge(RecType r[],int low,int mid,int high);
void mergePass(RecType r[],int length,int n);
/*------------------------------------------------------
 *
 * 自底向上的二路归并排序
 *
 * author： hanqing zhu 2018/12/4 19:07
 * -----------------------------------------------------*/
void mergeSort(RecType r[],int n);
/*------------------------------------------------------
 *
 * 自顶向下的二路归并排序
 *
 * author： hanqing zhu 2018/12/4 19:08
 * -----------------------------------------------------*/
void mergeSortDC(RecType r[],int low,int high);
void mergeSort1(RecType r[],int n);


/*------------------------------------------------------
 *
 * 基数排序
 * 
 * author： hanqing zhu 2018/12/4 20:22
 * -----------------------------------------------------*/
void radixSort(RecType **p,int r,int d);


/*------------------------------------------------------
 *
 * 输出RecType型链队
 *
 * author： hanqing zhu 2018/12/4 20:42
 * -----------------------------------------------------*/
void dispLink(RecType *p);


#endif //CHAPTER10_INSERTSORT_H
