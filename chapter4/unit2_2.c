//
// Created by hanqing zhu on 2018/11/13.
//

#include <stdlib.h>
#include <stdio.h>
#include "unit2_2.h"


/*------------------------------------------------------
 * 函数名：liStrAssign
 *
 * 功  能：将一个字符串常量赋给串s，即生成一个其值等于cstr的串s
 *
 * 描  述：尾插法
 *
 * 参  数：s，待赋值字符串；
 *        cstr，赋值字符数组。
 *
 * 返回值：无
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void liStrAssign(LiString **s, char cstr[]){
    LiString *p,*r;
    int i;
    *s=(LiString *)malloc(sizeof(LiString));
    (*s)->next=NULL;
    r=*s;
    for (i=0;cstr[i]!='\0';i++){
        p=(LiString *)malloc(sizeof(LiString));
        p->data=cstr[i];
        r->next=p;
        r=p;
    }
    r->next=NULL;
}

/*------------------------------------------------------
 * 函数名：liStrCopy
 *
 * 功  能：将串t赋值给串s
 *
 * 描  述：尾插法
 *
 * 参  数：s，待赋值串；
 *        t，拷贝串。
 *
 * 返回值：无
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void liStrCopy(LiString **s,LiString *t){
    LiString *p=t->next,*q,*r;
    *s=(LiString *)malloc(sizeof(LiString));
    //r始终指向尾结点
    r=*s;
    //将t的所有结点复制到s
    while (p!=NULL){
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    r->next=NULL;
}


/*------------------------------------------------------
 * 函数名：liStrEqual
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
int liStrEqual(LiString *s,LiString *t){
    LiString *p=s->next,*q=t->next;
    while (p!=NULL&&q!=NULL){
        if (p->data!=q->data){
            return 0;
        }
        p=p->next;
        q=q->next;
    }
    if (p!=NULL||q!=NULL){
        return 0;
    }else{
        return 1;
    }
}


/*------------------------------------------------------
 * 函数名：liStrLength
 *
 * 功  能：求串长：返回串s中的字符个数
 *
 * 描  述：
 *
 * 参  数：s，待统计串。
 *
 * 返回值：串长度
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int liStrLength(LiString *s){
    LiString *p=s->next;
    int length=0;
    while (p!=NULL){
        length++;
        p=p->next;
    }
    return length;
}


/*------------------------------------------------------
 * 函数名：liConcat
 *
 * 功  能：串连接：返回由两个串s和t连接在一起形成的新串
 *
 * 描  述：尾插法
 *
 * 参  数：s,t:待连接串。
 *
 * 返回值：新串
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
LiString * liConcat(LiString *s,LiString *t){
    LiString *li,*p,*q,*r;
    li=(LiString *)malloc(sizeof(LiString));
    p=s->next;
    r=li;
    //将串s的所有结点复制到li
    while (p!=NULL){
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    p=t->next;
    //将串t的所有结点复制到li
    while(p!=NULL){
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    r->next=NULL;
    return li;
}


/*------------------------------------------------------
 * 函数名：subLiStr
 *
 * 功  能：求子串：返回串s中从第i（1<=i<=strLength(s)）个字符开
 *        始的、由连续j个字符组成的子串参数不正确时返回一个空串
 *
 * 描  述：
 *
 * 参  数：s，待操作串；
 *        i，子串起始位置；
 *        j，子串长度。
 *
 * 返回值：新串
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
LiString * subLiStr(LiString *s, int i, int j){
    LiString *li,*p=s->next,*q,*r;
    int loc=1;
    //找到第i个数据结点
    while(loc<i&&p!=NULL){
        loc++;
        p=p->next;
    }
    //参数i不正确
    if (loc<i){
        return NULL;
    }
    li=(LiString *)malloc(sizeof(LiString));
    li->next=NULL;
    r=li;
    loc=0;
    while (loc<j&&p!=NULL){
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;
        r=q;
        loc++;
        p=p->next;
    }
    //参数j不正确
    if (loc<j){
        return NULL;
    }
    r->next=NULL;
    return li;
}

/*------------------------------------------------------
 * 函数名：
 *
 * 功  能：将串s2插入到串s1的第i（1<=i<=strLength(s)+1）个字符
 *        中，即将s2的第一个字符作为s1的第i个字符，并返回产生的新
 *        串。参数不正确时返回一个新串。
 *
 * 描  述：
 *
 * 参  数：s1，待插入串；
 *        i，插入起始位置；
 *        s2，插入串。
 *
 * 返回值：新串
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
LiString * insLiStr(LiString *s1, int i,LiString *s2){
    LiString *li,*p=s1->next,*q,*r,*m;
    int loc;
    li=(LiString *)malloc(sizeof(LiString));
    li->next=NULL;
    //参数不正确时返回空串
    if (i<=0||i>liStrLength(s1)+1){
        return li;
    }
    //r始终指向新串的尾结点
    r=li;
    //找到串s1的前i-1个元素赋给新串li
    for (loc=1;loc<=i-1;loc++){
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    //串s剩余结点的起始结点
    m=p;
    //将串s2赋给新串li
    p=s2->next;
    while(p!=NULL){
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    //将串s1的剩余结点赋给li
    while(m!=NULL){
        q=(LiString *)malloc(sizeof(LiString));
        q->data=m->data;
        r->next=q;
        r=q;
        m=m->next;
    }
    return li;
}

/*------------------------------------------------------
 * 函数名：delLiStr
 *
 * 功  能：从串s中删去第i（1<=i<=strLength(s)）个字符开始的、由
 *        连续j个字符组成的子串，并返回产生的新串。参数不正确时返
 *        回一个空串。
 *
 * 描  述：尾插法
 *
 * 参  数：s，待删除串；
 *        i，删除子串的起始位置；
 *        j，删除子串的长度。
 *
 * 返回值：新串
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
LiString * delLiStr(LiString *s,int i, int j){
    int loc;
    LiString *li,*p=s->next,*r,*q;

//    printf("该方法正在执行：delLiStr");

    li=(LiString *)malloc(sizeof(LiString));
    li->next=NULL;
    //参数不正确，返回空串
    if (i<=0||i+j-1>liStrLength(s)||j<0){
        return li;
    }
    //r始终指向li的末尾
    r=li;
    //将s的前n-1项复制到li
    for(loc=1;loc<=i-1;loc++){
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    //找到剩余的第1项，即跳过从第i项开始的中间的j项
    for(loc=1;loc<=j;loc++){
        p=p->next;
    }
    //将剩下的复制到li中
    while(p!=NULL){
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    r->next=NULL;
    return li;
}

/*------------------------------------------------------
 * 函数名：repLiStr
 *
 * 功  能：在串s中，将第i（1<=i<=strLength(s)）个字符开始的、由
 *        连续j个字符组成的子串，用串t代替，并返回产生的新串。参数
 *        不正确时返回一个空串。
 *
 * 描  述：尾插法
 *
 * 参  数：s，被替代串；
 *        i，替代起始位置；
 *        j，替代子串的长度；
 *        t，替代串。
 *
 * 返回值：新串
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
LiString * repLiStr(LiString *s,int i, int j,LiString *t){
    int loc;
    LiString *li,*r,*p=s->next,*q,*m;
    li=(LiString *)malloc(sizeof(LiString));
    li->next=NULL;
    //r始终指向li的末尾
    r=li;
    //若参数不正确，返回空串
    if (i<=0||j<0||i+j-1>liStrLength(s)){
        return li;
    }
    //将s的前i-1项复制到li中
    for(loc=1;loc<=i-1;loc++){
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    //保存s的第i项
    m=p;
    //将t复制到li中（作为li的第i项开始）
    p=t->next;
    while (p!=NULL){
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    //跳过s从第i项开始的一共j项数据
    p=m;
    for(loc=1;loc<=j;loc++){
        p=p->next;
    }
    //将s剩下的数据复制到li中
    while(p!=NULL){
        q=(LiString *)malloc(sizeof(LiString));
        q->data=p->data;
        r->next=q;
        r=q;
        p=p->next;
    }
    r->next;
    return li;
}

/*------------------------------------------------------
 * 函数名：dispLiString
 *
 * 功  能：输出串s的所有元素值
 *
 * 描  述：
 *
 * 参  数：s，待输出串
 *
 * 返回值：无
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void dispLiString(LiString *s){
    LiString *p;
    if (s==NULL){
        printf("空串");
        return;
    }
    p=s->next;
    while (p!=NULL){
        printf("%c",p->data);
        p=p->next;
    }
    printf("\n");
    return;
}

/*------------------------------------------------------
 * 函数名：exa4_3_repl
 *
 * 功  能：将在s中最先出现的子串“ab”改为“xyz”
 *
 * 描  述：以链串为存储结构
 *
 * 参  数：s，待修改串
 *
 * 返回值：无
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void exa4_3_repl(LiString **s){
    LiString *q,*p=(*s)->next;
    //找到ab所在的指针（a的指针）
    while (p!=NULL){
        if (p->data=='a'){
            if (p->next->data='b'){
                p->data='x';
                p->next->data='y';
                q=(LiString *)malloc(sizeof(LiString));
                q->data='z';
                q->next=p->next->next;
                p->next->next=q;
                return;
            }
        }
        p=p->next;
    }

}