//
// Created by hanqing zhu on 2018/11/13.
//

#include "unit3.h"

/*------------------------------------------------------
 * 函数名：index
 *
 * 功  能：在主串s中找到一个与子串t相等的子串
 *
 * 描  述：简单匹配算法（Brute-Force）
 *
 * 参  数：s，主串；
 *        t，模式串。
 *
 * 返回值：主串中与子串t相等的子串的开始位置
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int index(SqString s,SqString t){
    int i=0,j=0;
    while (j<t.length&&i<s.length){
        if(s.data[i]==t.data[j]){
            i++;
            j++;
        }else{
            i=i-j+1;
            j=0;
        }
    }
    if(j<strLength(t)){
        return -1;
    }else{
        return i-t.length;
    }
}


//KMP算法
//思想：设s为目标串，t为模式串，并设i指针和j指针分别指示目标串和模式串中正待比较的字符，
//     令i和j的初值为0,。若有si=tj，则i和j分别增1；否则，i不变，j退回到j=next[j]的位
//     置（即模式串右滑），比较si和tj，若相等则指针各增1，否则j再退回到下一个j=next[j]
//     的位置（即模式串继续右滑），再比较si和tj。以此类推，直到出现下列两种情况之一：一种
//     情况是j退回到某个j=next[j]的位置时有si=tj，则指针各增1后继续匹配；另一种情况是j
//     退回到j=-1时，此时令i、j指针各增1，即下一次比较s（i+1）和t0。

/*------------------------------------------------------
 * 函数名：getNext
 *
 * 功  能：由模式串t求出next值
 *
 * 描  述：
 *
 * 参  数：t，模式串；
 *        next，存放“部分匹配”信息。
 *
 * 返回值：无
 *
 * 时间复杂度：O(m)
 * -----------------------------------------------------*/
void getNext(SqString t, int next[]){
    int j,k;
    j=0;
    k=-1;
    next[0]=-1;
    while (j<t.length-1){
        //k为-1或比较的字符相等时
        if(k==-1||t.data[j]==t.data[k]){
            j++;
            k++;
            next[j]=k;
        } else{
            k=next[k];
        }
    }
}

/*------------------------------------------------------
 * 函数名：KMPIndex
 *
 * 功  能：KMP算法
 *
 * 描  述：
 *
 * 参  数：s，匹配串；
 *        t，模式串。
 *
 * 返回值：匹配开始的位置或-1(无法匹配)
 *
 * 时间复杂度：O(m+n):m,t的长度；n,s的长度
 * -----------------------------------------------------*/
int KMPIndex(SqString s,SqString t){
    int next[MaxSize],i=0,j=0;
    getNext(t,next);
    while (i<s.length&&j<t.length){
        if(j==-1||s.data[i]==t.data[j]){
            i++;
            j++;
        }else{
            j=next[j];
        }
    }
    if(j>=t.length){
        return (i-t.length);
    } else{
        return -1;
    }
}

//修正的KMP算法
//思路：若按上述定义得到next[j]=k，而模式中tj=tk，则主串中字符si和模式串中字符tj比较不等
//     时，不需要再和tk进行比较，而直接和t(next[k])进行比较，换句话说，此时的next[j]应和
//     next[k]相同。为此将next[j]修正为nextVal[j]。

/*------------------------------------------------------
 * 函数名：getNextVal
 *
 * 功  能：修正的next数组
 *
 * 描  述：在计算出next值的同时，如果a位字符与它next值指向的b位
 *        字符相等，则该a位的nextVal就指向b位的nextVal值，如果
 *        不等，则该a位的nextVal值就是它自己a位的next的值。
 *
 * 参  数：t，模式串；
 *        nextVal，改进的存储“部分匹配”信息
 *
 * 返回值：无
 *
 * 时间复杂度：O(m):m,t的长度
 * -----------------------------------------------------*/
void getNextVal(SqString t,int nextVal[]){
    int j=0,k=-1;
    nextVal[0]=-1;
    while(j<t.length){
        if(k==-1||t.data[j]==t.data[k]){
            j++;
            k++;
            if(t.data[j]==t.data[k]){
                nextVal[j]==nextVal[k];
            } else{
                nextVal[j]=k;
            }
        }
    }
}

/*------------------------------------------------------
 * 函数名：KMPIndex1
 *
 * 功  能：改进的KMP算法
 *
 * 描  述：
 *
 * 参  数：s，匹配串；
 *        t，模式串。
 *
 * 返回值：匹配的开始位置或-1(无法匹配)
 *
 * 时间复杂度：O(m+n):m，t的长度；n，s的长度
 * -----------------------------------------------------*/
int KMPIndex1(SqString s,SqString t){
    int i=0,j=0,nextVal[MaxSize];
    getNextVal(t,nextVal);
    while(i<s.length&&j<t.length){
        if(j==-1||t.data[j]==s.data[i]){
            i++;
            j++;
        }else{
            j=nextVal[j];
        }
    }
    if(j>=t.length){
        return (i-t.length);
    }else{
        return -1;
    }
}