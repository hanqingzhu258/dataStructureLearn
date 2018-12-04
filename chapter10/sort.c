//
// Description: 
// Created by hanqing zhu on 2018/12/3.
//

#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/*------------------------------------------------------
 * 函数名：insertSort_direct
 *
 * 功  能：直接插入排序
 *
 * 描  述：就地排序、稳定排序
 *
 * 参  数：r，待排序记录；
 *        n，记录总数。
 *
 * 返回值：无
 *
 * 时间复杂度：O(n)（最好：正序）O(n^2)（最坏：倒序）O(n^2)（平均）
 *
 * author： hanqing zhu 2018/12/3 15:48
 * -----------------------------------------------------*/
void insertSort_direct(RecType r[],int n){
    int i,j,k;
    RecType tmp;
    //R[i..n-1]为未排序的子区间
    for (i=1;i<n;i++){
        tmp=r[i];
        //找到第i个元素在已排序区间R[0..i-1]的应该位置
        for (j=0;j<i;j++){
            if(r[i].key<r[j].key){
                break;
            }
        }
        //将第i个元素插入其中，构成排序区间R[0..i]
        for (k=i;k>j;k--){
            r[k]=r[k-1];
        }
        r[j]=tmp;
    }
}

void insertSort_direct_book(RecType r[],int n){
    int i,j;
    RecType tmp;
    for (i=1;i<n;i++){
        j=i-1;
        tmp=r[i];
        while (j>=0&&tmp.key<r[j].key){
            r[j+1]=r[j];
            j--;
        }
        r[j+1]=tmp;
    }

}

/*------------------------------------------------------
 * 函数名：insertSort_binary
 *
 * 功  能：二分（折半）插入排序
 *
 * 描  述：就地排序、稳定排序
 *
 * 参  数：r，待排序数组；
 *        n，记录总数。
 *
 * 返回值：
 *
 * 时间复杂度：O(n^2)（减少比较次数，移动次数不变）
 *
 * author： hanqing zhu 2018/12/3 17:18
 * -----------------------------------------------------*/
void insertSort_binary(RecType r[],int n){
    int low,high,mid;
    int i,j;
    RecType tmp;
    for (i=1;i<n;i++){
        tmp=r[i];
        low=0;
        high=i-1;
        while (low<=high){
            mid=low+(high-low)/2;
            if(tmp.key<r[mid].key){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        for (j=i-1;j>=high+1;j--){
            r[j+1]=r[j];
        }
        r[high+1]=tmp;
    }
}

/*------------------------------------------------------
 * 函数名：shellSort
 *
 * 功  能：希尔排序
 *
 * 描  述：就地排序、不稳定排序
 *
 * 参  数：r，待排序数组；
 *        n，记录总数。
 *
 * 返回值：无
 *
 * 时间复杂度：O(n^1.3)
 *
 * author： hanqing zhu 2018/12/3 20:27
 * -----------------------------------------------------*/
void shellSort(RecType r[],int n){
    int gap;
    int i,j;
    RecType tmp;
    //增量值初值
    gap=n/2;
    while (gap>0){
        //对所有相隔gap位置的所有元素组采用直接插入排序
        for (i=gap;i<n;i++){
            tmp=r[i];
            j=i-gap;
            //对相隔gap位置的所有元素组进行排序
            while (j>=0&&tmp.key<r[j].key){
                r[j+gap]=r[j];
                j=j-gap;
            }
            r[j+gap]=tmp;
        }
        //减小增量
        gap=gap/2;
    }
}

/*------------------------------------------------------
 * 函数名：bubbleSort
 *
 * 功  能：冒泡排序
 *
 * 描  述：
 *
 * 参  数：r，待排序数组；
 *        n，记录总数。
 *
 * 返回值：无
 *
 * 时间复杂度：O(n^2)
 *
 * author： hanqing zhu 2018/12/3 21:13
 * -----------------------------------------------------*/
void bubbleSort(RecType r[],int n){
    int i,j;
    int exchange;
    RecType tmp;
    for (i=0;i<n;i++){
        exchange=0;
        //比较，找出本趟最小关键字的记录
        for (j=n-1;j>i;j--){
            if(r[j].key<r[j-1].key){
                //r[j]与r[j-1]进行交换，将最小关键字记录前移
                tmp=r[j-1];
                r[j-1]=r[j];
                r[j]=tmp;
                exchange=1;
            }
        }
        if(exchange==0){
            return;
        }
    }
}

/*------------------------------------------------------
 * 函数名：quickSort
 *
 * 功  能：快速排序
 *
 * 描  述：以区间的第1个元素为基准，不是就地排序，不是稳定排序
 *
 * 参  数：r，待排序数组；
 *        s，排序区间开始位置；
 *        t，排序区间结束位置。
 *
 * 返回值：无
 *
 * 时间复杂度：O(n^2):最坏 O(nlog2[n])：最好 O(nlog2[n])：平均
 *
 * author： hanqing zhu 2018/12/4 9:27
 * -----------------------------------------------------*/
void quickSort(RecType r[],int s,int t){
    int i=s,j=t;
    RecType tmp;
    //区间内至少存在两个元素的情况
    if(s<t){
        //用区间的第一个记录作为基准
        tmp=r[s];
        //从区间两端交替向中间扫描，直至i=j为止
        while (i!=j){
            //从右向左扫描，找第1个小于tmp.key的r[j]
            while (j>i&&tmp.key<r[j].key){
                j--;
            }
            //找到这样的r[j],r[i]<->r[j]交换
            r[i]=r[j];
            //从左向右扫描，找第1个大于tmp.key的r[i]
            while (i<j&&tmp.key>r[i].key){
                i++;
            }
            //找到这样的r[i],r[i]<->r[j]交换
            r[j]=r[i];
        }
        r[i]=tmp;
        //对左区间递归排序
        quickSort(r,s,i-1);
        //对右区间递归排序
        quickSort(r,i+1,t);
    }

}

/*------------------------------------------------------
 * 函数名：quickSort1
 *
 * 功  能：快速排序
 *
 * 描  述：以区间的中间位置的元素为基准
 *
 * 参  数：r，待排序数组；
 *        s，排序区间开始位置；
 *        t，排序区间结束位置。
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/12/4 10:07
 * -----------------------------------------------------*/
void quickSort1(RecType r[],int s,int t){
    int i=s,j=t;
    KeyType prior=r[(s+t)/2].key;
    RecType tmp;
    if (s<t){
        while (i!=j){
            while (j>i&&prior<r[j].key){
                j--;
            }
            while (i<j&&prior>r[i].key){
                i++;
            }
            if(i<=j){
                tmp=r[j];
                r[j]=r[i];
                r[i]=tmp;
            }
        }
        quickSort(r,s,i-1);
        quickSort(r,j+1,t);
    }
}

/*------------------------------------------------------
 * 函数名：selectSort
 *
 * 功  能：直接选择排序
 *
 * 描  述：就地排序、不稳定排序
 *
 * 参  数：r，待排序数组；
 *        n，记录总数。
 *
 * 返回值：无
 *
 * 时间复杂度：O(n^2)
 *
 * author： hanqing zhu 2018/12/4 10:48
 * -----------------------------------------------------*/
void selectSort(RecType r[],int n){
    int i,j;
    int min,loc;
    RecType tmp;
    for (i=0;i<n-1;i++){
        min=INF;
        for (j=n-1;j>=i;j--){
            if(r[j].key<=min){
                min=r[j].key;
                loc=j;
            }
        }
        tmp=r[loc];
        r[loc]=r[i];
        r[i]=tmp;
    }
}

void selectSort_book(RecType r[],int n){
    int i,j,k;
    RecType tmp;
    for (i=0;i<n-1;i++){
        k=i;
        for (j=i+1;j<n;j++){
            if(r[j].key<r[k].key){
                k=j;
            }
        }
        if(k!=i){
            tmp=r[i];
            r[i]=r[k];
            r[k]=tmp;
        }
    }
}

/*------------------------------------------------------
 * 函数名：sift
 *
 * 功  能：对r[low..high]进行筛选
 *
 * 描  述：在堆排序中需要反复使用进行r的筛选调整
 *
 * 参  数：r，待筛选数组；
 *        low，数组下限；
 *        high，数组上限。
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/12/4 16:07
 * -----------------------------------------------------*/
void sift(RecType r[],int low,int high){
    //r[j]是r[i]的左孩子
    int i=low,j=2*i;
    //将r[i]保存在临时变量tmp中
    RecType tmp=r[i-1];
    //若j在有效范围内
    while (j<=high){
        //若右孩子较大，把j指向右孩子
        if (j<high&&r[j-1].key<r[j+1-1].key){
            j++;
        }
        //若r[i].key小于孩子中的最大关键字
        if (tmp.key<r[j-1].key){
            //将r[j]调整到双亲结点位置上
            r[i-1]=r[j-1];
            //修改i值，以便继续向下筛选
            i=j;
            //r[j]是r[i]的左孩子
            j=2*j;
        } else{
            //筛选结束
            break;
        }
    }
    //被筛选的值放入最终位置
    r[i-1]=tmp;
}

/*------------------------------------------------------
 * 函数名：heapSort
 *
 * 功  能：堆排序
 *
 * 描  述：
 *
 * 参  数：r，待排序数组；
 *        n，记录总数。
 *
 * 返回值：无
 *
 * 时间复杂度：O(nlog2[n])
 *
 * author： hanqing zhu 2018/12/4 16:14
 * -----------------------------------------------------*/
void heapSort(RecType r[],int n){
    int i;
    RecType tmp;
    //循环建立初始堆
    for (i=n/2;i>=1;i--){
        sift(r,i,n);
    }
    //进行n-1趟完成堆排序，每一趟堆排序的元素个数减1
    for(i=n;i>=2;i--){
        //将最后一个元素与当前区间内r[1]对换
        tmp=r[1-1];
        r[1-1]=r[i-1];
        r[i-1]=tmp;
        //筛选r[1]结点，得到i-1个结点的堆
        sift(r,1,i-1);
    }
}

//归并排序
/*------------------------------------------------------
 * 函数名：merge
 *
 * 功  能：将两个有序表直接归并为一个有序表
 *
 * 描  述：使用的辅助空间正好是要归并的元素的个数
 *
 * 参  数：r，待排序数组；
 *        low，第一段开始位置；
 *        mid，第一段结束位置；
 *        high，第二段结束位置。
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/12/4 19:09
 * -----------------------------------------------------*/
void merge(RecType r[],int low,int mid,int high){
    RecType *r1;
    //k是r1的下标，i、j分别为第1,2段的下标
    int i=low,j=mid+1,k=0;
    //动态分配空间
    r1=(RecType *)malloc((high-low+1)*sizeof(RecType));
    //在第一段和第二段均未扫描完时循环
    while (i<=mid&&j<=high){
        //将第1段中的记录放入r1中
        if (r[i].key<=r[j].key){
            r1[k]=r[i];
            i++;
            k++;
        }
        //将第2段中的记录放入r2中
        else{
            r1[k]=r[j];
            j++;
            k++;
        }
    }
    //将第1段余下部分复制到r1
    while (i<=mid){
        r1[k]=r[i];
        i++;
        k++;
    }
    //将第2段余下部分复制到r1
    while (j<=high){
        r1[k]=r[j];
        k++;
        j++;
    }
    //将r1复制回r中
    for(k=0,i=low;i<=high;i++,k++){
        r[i]=r1[k];
    }
}

/*------------------------------------------------------
 * 函数名：mergePass
 *
 * 功  能：利用merge()解决一趟归并问题
 *
 * 描  述：若子表个数为奇数，则最后一个子表无须和其它子表归并（即
 *        本趟轮空）；若子表个数为偶数，则要注意到最后一对子表中
 *        后一个子表的区间上界是n-1。
 *        一趟归并使用的辅助空间正好为整个表的长度。
 *
 * 参  数：r，待排序数组；
 *        length，待归并子表的长度；
 *        n，记录总数。
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/12/4 19:23
 * -----------------------------------------------------*/
void mergePass(RecType r[],int length,int n){
    int i;
    for (i=0;i+2*length-1<n;i=i+2*length){
        merge(r,i,i+length-1,i+2*length-1);
    }
    if (i+length-1<n){
        merge(r,i,i+length-1,n-1);
    }
}

/*------------------------------------------------------
 * 函数名：mergeSort
 *
 * 功  能：自底向上的归并算法
 *
 * 描  述：效率较高，可读性较差。非就地排序、稳定排序
 *
 * 参  数：r
 *
 * 返回值：无
 *
 * 时间复杂度：O(nlog2[n])
 *
 * author： hanqing zhu 2018/12/4 19:33
 * -----------------------------------------------------*/
void mergeSort(RecType r[],int n){
    int length;
    for (length=1;length<n;length=2*length){
        mergePass(r,length,n);
    }
}

/*------------------------------------------------------
 * 函数名：mergeSortDC
 *
 * 功  能：对r[low..high]进行自顶向下的二路归并排序
 *
 * 描  述：
 *
 * 参  数：r，待排序数组；
 *        low，区间开始位置；
 *        high，区间结束位置。
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/12/4 19:47
 * -----------------------------------------------------*/
void mergeSortDC(RecType r[],int low,int high){
    int mid;
    if(low<high){
        mid=low+(high-low)/2;
        mergeSortDC(r,low,mid);
        mergeSortDC(r,mid+1,high);
        merge(r,low,mid,high);
    }
}

/*------------------------------------------------------
 * 函数名：mergeSort1
 *
 * 功  能：自顶向下的二路归并排序
 *
 * 描  述：非就地排序、稳定排序
 *
 * 参  数：r，带排序数组；
 *        n，记录总数。
 *
 * 返回值：无
 *
 * 时间复杂度：O(nlog2[n])
 *
 * author： hanqing zhu 2018/12/4 19:49
 * -----------------------------------------------------*/
void mergeSort1(RecType r[],int n){
    mergeSortDC(r,0,n-1);
}

/*------------------------------------------------------
 * 函数名：radixSort
 *
 * 功  能：以r为基数的LSD（least significant digitfirst）排序
 *
 * 描  述：
 *
 * 参  数：p，待排序链表；
 *        r，基数（如二进制基数为2，十进制基数为10）；
 *        d，关键字位数。
 *
 * 返回值：无
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/12/4 20:23
 * -----------------------------------------------------*/
void radixSort(RecType **p,int r,int d){
    //定义个链队的首尾指针
    RecType *head[r],*tail[r],*t,*q=*p;
    int i,j,k;
    //从低位到高位循环
    for (i=0;i<=d-1;i++){
        //初始化各链队首尾指针
        for (j=0;j<r;j++){
            head[j]=tail[j]=NULL;
        }
        //分配：对于原链表中每个结点循环
        while (q!=NULL){
            //找第k个链队
            k=(q)->data.d[i]-'0';
            //第k个链队为空时，队头队尾均指向q
            if (head[k]==NULL){
                head[k]=q;
                tail[k]=q;
            }
            //第k个链队非空时，q入队
            else{
                tail[k]->next=q;
                tail[k]=q;
            }
            //取下一个待排序的元素
            q=q->next;
        }
        //重新用p来收集所有结点
        *p=NULL;
        //收集：对于每一个链队循环
        for  (j=0;j<r;j++){
            //第j个链队不空
            if (head[j]!=NULL){
                //若第j个链队是第一个非空链队
                if (*p==NULL){
                    *p=head[j];
                    t=tail[j];
                }else{
                    t->next=head[j];
                    t=tail[j];
                }
            }
        }
        t->next=NULL;
        printf("按%s位排序\t",(i==0?"个":"十"));
        //调用dispLink函数显示数列
        dispLink(*p);
    }
}

/*------------------------------------------------------
 * 函数名：dispLink
 *
 * 功  能：输出RecType型链队
 *
 * 描  述：在此先忽略
 *
 * 参  数：
 *
 * 返回值：
 *
 * 时间复杂度：
 *
 * author： hanqing zhu 2018/12/4 20:42
 * -----------------------------------------------------*/
void dispLink(RecType *p){

}