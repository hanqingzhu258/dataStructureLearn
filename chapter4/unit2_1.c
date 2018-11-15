//
// Created by hanqing zhu on 2018/11/12.
//

#include <stdio.h>
#include "unit2_1.h"

/*------------------------------------------------------
 * 函数名：strAssign
 *
 * 功  能：将一个字符串常量赋给串s，即生成一个其值等于cstr的串s
 *
 * 描  述：
 *
 * 参  数：s,待赋值串；
 *        cstr，字符数组。
 *
 * 返回值：无
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void strAssign(SqString *s, char cstr[]){
    int i;
    for (i=0;cstr[i]!='\0';i++){
        s->data[i]=cstr[i];
        s->length++;
    }
}

/*------------------------------------------------------
 * 函数名：strCopy
 *
 * 功  能：将串t赋值给串s
 *
 * 描  述：
 *
 * 参  数：s,待赋值串；
 *        t,赋值串。
 *
 * 返回值：无
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void strCopy(SqString *s,SqString t){
    int i;
    for (i=0;i<t.length;i++){
        s->data[i]=t.data[i];
    }
    s->length=t.length;
}

/*------------------------------------------------------
 * 函数名：strEqual
 *
 * 功  能：判断串相等：若两个串s与t相等返回真（1）；否则返回假（0）
 *
 * 描  述：
 *
 * 参  数：s,t:待比较串。
 *
 * 返回值：0(不相等)或1(相等)
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int strEqual(SqString s,SqString t){
    if(s.length!=t.length){
        return 0;
    }
    for (int i = 0; i <t.length ; i++) {
        if(s.data[i]!=t.data[i]){
            return 0;
        }
    }
    return 1;
}

/*------------------------------------------------------
 * 函数名：strLength
 *
 * 功  能：求串长：返回串s中的字符个数
 *
 * 描  述：
 *
 * 参  数：s,待求串
 *
 * 返回值：串
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int strLength(SqString s){
    return s.length;
}

/*------------------------------------------------------
 * 函数名：concat
 *
 * 功  能：串连接：返回由两个串s和t连接在一起形成的新串
 *
 * 描  述：
 *
 * 参  数：s,连接串1；
 *        t,连接串2。
 *
 * 返回值：新串
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
SqString concat(SqString s,SqString t){
    SqString str;
    int i;
    str.length=s.length+t.length;
    for (i=0;i<s.length;i++){
        str.data[i]=s.data[i];
    }
    for (i=0;i<t.length;i++){
        str.data[s.length+i]=t.data[i];
    }
    return str;
}

/*------------------------------------------------------
 * 函数名：subStr
 *
 * 功  能：求子串：返回串s中从第i（1<=i<=strLength(s)）个字符
 *        开始的由连续j个字符组成的子串参数不正确时返回一个空串
 *
 * 描  述：
 *
 * 参  数：s,待操作串；
 *        i,开始位置（逻辑位序）；
 *        j,子串长度。
 *
 * 返回值：子串
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
SqString subStr(SqString s, int i, int j){
    SqString str;
    int k=i-1;
    str.length=0;
    //参数不正确时返回空串
    if(i<=0||i>s.length||j<0||i-1+j>s.length){
        return str;
    }
    for(k=i-1;k>i+j-1;k++){
        str.data[k-i+1]=s.data[k];
    }
    str.length=j;
    return str;
}

/*------------------------------------------------------
 * 函数名：insStr
 *
 * 功  能：将串s2插入到串s1的第i（1<=i<=strLength(s)+1）个字符
 *        中，即将s2的第一个字符作为s1的第i个字符，并返回产生的新
 *        串。参数不正确时返回一个新串。
 *
 * 描  述：
 *
 * 参  数：s1,待插入串；
 *        i,插入起始位置；
 *        s2，插入串。
 *
 * 返回值：新串
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
SqString insStr(SqString s1, int i,SqString s2){
    SqString str;
    int j,k;
    str.length=0;
    //参数不正确
    if(i<=0||i>s1.length+1){
        return str;
    }
    //将s1.data[0..i-2]复制到str
    for(j=0;j<i-1;j++){
        str.data[j]=s1.data[j];
    }
    //将s2.data[0..s2.length-1]复制到str
    for (k=0;k<s2.length;k++){
        str.data[i-1+k]=s2.data[k];
    }
    //将s1.data[i-1..s1.length-1]复制到str
    for (j=i-1;j<s1.length;j++){
        str.data[j+s2.length]=s1.data[j];
    }
    str.length=s1.length+s2.length;
    return str;
}

/*------------------------------------------------------
 * 函数名：delStr
 *
 * 功  能：从串s中删去第i（1<=i<=strLength(s)）个字符开始的、 由
 *       连续j个字符组成的子串，并返回产生的新串。参数不正确时返回
 *       一个空串。
 *
 * 描  述：
 *
 * 参  数：s,待删除串；
 *        i，删除起始位置；
 *        j，删除字符个数。
 *
 * 返回值：新串
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
SqString delStr(SqString s,int i, int j){
    SqString str;
    int k;
    str.length=0;
    //参数不正确是返回空串
    if(i<=0||i>s.length||i+j-1>s.length){
        return str;
    }
    //将s.data[0..i-2]复制到str
    for(k=0;k<i-1;k++){
        str.data[k]=s.data[k];
    }
    //将s.data[i+j-1..s.length-1]复制到str
    for(k=0;i+j-1+k<s.length;k++){
        str.data[i-1+k]=s.data[i+j-1+k];
    }
    str.length=s.length-j;
    return str;
}

/*------------------------------------------------------
 * 函数名：repStr
 *
 * 功  能：在串s中，将第i（1<=i<=strLength(s)）个字符开始的、由连
 *        续j个字符组成的子串，用串t代替，并返回产生的新串。参数不
 *        正确时返回一个空串。
 *
 * 描  述：
 *
 * 参  数：s,待替换串；
 *        i，替换开始位置；
 *        j，替换长度；
 *        t，替换串。
 *
 * 返回值：新串
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
SqString repStr(SqString s,int i, int j,SqString t){
    SqString str;
    int k,m;
    str.length=0;
    //参数不正确时返回0
    if(i<=0||i>s.length||i+j-1>s.length){
        return str;
    }
    //将s.data[0..i-2]复制到str
    for (k=0;k<i-1;k++){
        str.data[k]=s.data[k];
    }
    //将t.data[0..t.length-1]复制到str
    for(k=0;k<t.length;k++){
        str.data[i-1+k]=t.data[k];
    }
    //将s.data[i+j-1..s.length-1]复制到str
    for(k=i-1+j;k<s.length;k++){
        str.data[k+t.length-j]=s.data[k];
    }
    str.length=s.length-j+t.length;
    return str;
}

/*------------------------------------------------------
 * 函数名：dispString
 *
 * 功  能：输出串s的所有元素值
 *
 * 描  述：
 *
 * 参  数：s,待输出串。
 *
 * 返回值：
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void dispString(SqString s){
    int i;
    if(s.length>0){
        for (i=0;i<s.length;i++){
            printf("%c",s.data[i]);
        }
        printf("\n");
    }
}

/*------------------------------------------------------
 * 函数名：strcmp
 *
 * 功  能：串比较运算
 *
 * 描  述：
 *
 * 参  数：s,t：待比较字符串
 *
 * 返回值：-1(<)或0(=)或1(>)
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int strcmp2(SqString s,SqString t){
    int i,comlen;
    if (s.length<t.length){
        comlen=s.length;
    }else{
        comlen=t.length;
    }
    for(i=0;i<comlen;i++){
        if (s.data[i]<t.data[i]){
            return -1;
        } else if (s.data[i]>t.data[i]){
            return 1;
        }
    }
    if (s.length==t.length){
        return 0;
    }else if (s.length<t.length){
        return -1;
    } else{
        return 1;
    }
}

/*------------------------------------------------------
 * 函数名：longestString
 *
 * 功  能：求串s中出现的第一个最长的连续相同字符构成的平台
 *
 * 描  述：
 *
 * 参  数：s，待求串；
 *        index，所求子串的起始位置；
 *        max，所求子串的长度。
 *
 * 返回值：无
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void longestString(SqString s,int *index,int *max){
    //length保存平台的长度
    int length=1,i=0,start=0;
    //index保存最长平台在s中的开始位置,max保存其长度
    *index=0,*max=0;
    while(i<s.length-1){
        if (s.data[i]==s.data[i+1]){
            i++;
            length++;
        }
        //上一个平台结束
        else{
            //当前平台长度大，则更新max
            if (*max<length){
                *max=length;
                *index=start;
            }
            //初始化下一个平台的起始位置和长度
            i++;
            start=i;
            length=1;
        }
    }
}