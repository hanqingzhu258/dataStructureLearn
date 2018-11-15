//
// Created by hanqing zhu on 2018/11/11.
//
#include <stdio.h>
#include <stdlib.h>
#include "unit1_4.h"
#include "main.h"
#include "unit1_2.h"

struct OPS lpri[]={{'=',0},{'(',1},{'*',5},{'/',5},{'+',3},{'-',3},{')',6}},
           rpri[]={{'=',0},{'(',6},{'*',4},{'/',4},{'+',2},{'-',2},{')',1}};

/*------------------------------------------------------
 * 函数名：leftpri
 *
 * 功  能：求左运算符（栈顶运算符）的优先级
 *
 * 描  述：
 *
 * 参  数：op，左运算符（栈顶运算符）
 *
 * 返回值：左运算符（栈顶运算符）的优先级
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int leftpri(char op){
    int i=0;
    for (int i = 0; i < MaxOp; i++) {
        if(lpri[i].ch==op){
            return lpri[i].pri;
        }
    }
}

/*------------------------------------------------------
 * 函数名：rightpri
 *
 * 功  能：求右运算符的优先级
 *
 * 描  述：
 *
 * 参  数：op，右运算符
 *
 * 返回值：右运算符的优先级
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int rightpri(char op){
    int i=0;
    for (int i = 0; i < MaxOp; i++) {
        if(rpri[i].ch==op){
            return rpri[i].pri;
        }
    }
}

/*------------------------------------------------------
 * 函数名：inOp
 *
 * 功  能：判断ch是否为运算符
 *
 * 描  述：
 *
 * 参  数：ch，待判断字符
 *
 * 返回值：0(否)或1(是)
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int inOp(char ch){
    for (int i = 0; i < MaxOp; i++) {
        if (lpri[i].ch==ch){
            return 1;
        }
    }
    return 0;
}

/*------------------------------------------------------
 * 函数名：precede
 *
 * 功  能：op1和op2运算符优先级的比较
 *
 * 描  述：
 *
 * 参  数：op1，左运算符（栈顶运算符）；
 *        op2，右运算符。
 *
 * 返回值：0(op1=op2)或1(op1>op2)或-1(op1<op2)
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int precede(char op1, char op2){
    if (leftpri(op1)==rightpri(op2)){
        return 0;
    }else if (leftpri(op1)<rightpri(op2)) {
        return -1;
    }else{
        return 1;
    }
}

/*------------------------------------------------------
 * 函数名：trans
 *
 * 功  能：将算术表达式转换为后缀表达式
 *
 * 描  述：后缀表达式：即运算符在操作数的后面，在后缀表达式中已
 *         考虑了运算符的优先级，没有括号，只有操作数和运算符。
 *         后缀表达式求值是按照运算符的次序进行的。
 *
 * 参  数：exp，算术表达式；
 *        postexp,后缀表达式
 *
 * 返回值：
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
void trans(char *exp,char postexp[]){
    //定义运算符栈（顺序栈）
    struct {
        //存放运算符
        char data[MaxSize];
        //栈指针
        int top;
    }op;
    //i作为postexp的下标
    int i=0;
    //初始化栈
    op.top=-1;
    //将‘=’进栈
    op.top++;
    op.data[op.top]='=';
    //exp表达式未扫描完时循环
    while (*exp!='\0'){
        //如果当前运算符为数字字符的情况
        if (!inOp(*exp)){
            while (*exp>='0'&&*exp<='9'){
                postexp[i++]=*exp;
                exp++;
            }
            postexp[i++]='#';
        }
        //为运算符的情况
        else{
            switch (precede(op.data[op.top],*exp)){
                //栈顶运算符的优先级低
                case -1:
                    //将当前运算符进栈
                    op.top++;
                    op.data[op.top]=*exp;
                    //继续扫描其它运算符
                    exp++;
                    break;
                //只有括号满足这种情况
                case 0:
                    //退栈
                    op.top--;
                    //继续扫描其它字符
                    exp++;
                    break;
                //栈顶运算符优先级高
                case 1:
                    //退栈并输出到postexp中
                    postexp[i++]=op.data[op.top];
                    op.top--;
                    break;
            }
        }
    }
    //此时exp扫描完毕，退栈到‘=’为止
    while (op.data[op.top]!='='){
        postexp[i++]=op.data[op.top];
        op.top--;
    }
    //给postexp表达式添加结束标志
    postexp[i]='\0';

}

/*------------------------------------------------------
 * 函数名：compvalue
 *
 * 功  能：计算后缀表达式postexp的值
 *
 * 描  述：
 *
 * 参  数：postexp，待求后缀表达式指针
 *
 * 返回值：该后缀表达式的值
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
float compvalue(char *postexp){
    struct {
        //存放数值
        float data[MaxSize];
        //栈指针
        int top;
    }st;
    float d,a,b,c;
    //初始化栈
    st.top=-1;
    //postexp字符串未结束时扫描
    while (*postexp!='\0'){
        switch (*postexp){
            case '+':
                a=st.data[st.top];
                st.top--;
                b=st.data[st.top];
                st.top--;
                c=a+b;
                st.top++;
                st.data[st.top]=c;
                break;
            case '-':
                a=st.data[st.top];
                st.top--;
                b=st.data[st.top];
                st.top--;
                c=b-a;
                st.top++;
                st.data[st.top]=c;
                break;
            case '*':
                a=st.data[st.top];
                st.top--;
                b=st.data[st.top];
                st.top--;
                c=a*b;
                st.top++;
                st.data[st.top]=c;
                break;
            case '/':
                a=st.data[st.top];
                st.top--;
                b=st.data[st.top];
                st.top--;
                if(a!=0){
                    c=b/a;
                    st.top++;
                    st.data[st.top]=c;
                } else{
                    printf("\n\t除零错误！\n");
                    exit(0);//异常退出
                }
                break;
            default:
                //处理数字字符
                //将连续的数字字符转换为对应的数
                //值存放到d中
                d=0;
                while(*postexp>='0'&&*postexp<='9'){
                    d=10*d+*postexp-'0';
                    postexp++;
                }
                //将该数字进栈
                st.top++;
                st.data[st.top]=d;
                break;
        }
        //继续处理其它字符
        postexp++;
    }
    return st.data[st.top];
}

/*------------------------------------------------------
 * 函数名：mgpath
 *
 * 功  能：寻找(xi,yi)到(xe,ye)迷宫路径
 *
 * 描  述：通过顺序栈存储迷宫路径
 *
 * 参  数：xi,yi:起始位置的坐标；
 *        xe,ye:出口位置的坐标。
 *
 * 返回值：0(没有通道)或1(找到通道)
 *
 * 时间复杂度：
 * -----------------------------------------------------*/
int mgpath(int xi,int yi,int xe,int ye,int mg[M+2][N+2]){
    struct {
        int i;
        int j;
        int di;
    }st[MaxSize];
    int top=-1;

    int i,j,k,di,find;
    top++;
    st[top].i=xi;
    st[top].j=yi;
    st[top].di=-1;
    mg[xi][yi]=-1;

    while(top>-1){
        i=st[top].i;
        j=st[top].j;
        di=st[top].di;
        if (i==xe&&j==ye){
            printf("迷宫路径如下：\n");
            for (int k = 0; k <=top ; k++) {
                printf("\t(%d,%d)",st[k].i,st[k].j);
                if ((k+1)%5==0){
                    printf("\n");
                }
            }
            printf("\n");
            return 1;
        }
        find=0;
        while(di<4&&find==0){
            di++;
            switch (di){
                case 0:
                    i=st[top].i-1;
                    j=st[top].j;
                    break;
                case 1:
                    i=st[top].i;
                    j=st[top].j+1;
                    break;
                case 2:
                    i=st[top].i+1;
                    j=st[top].j;
                    break;
                case 3:
                    i=st[top].i;
                    j=st[top].j-1;
                    break;

            }
            if (mg[i][j]==0){
                find=1;
            }
        }
        if (find==1){
            st[top].di=di;
            top++;
            st[top].i=i;
            st[top].j=j;
            st[top].di=-1;
            mg[i][j]=-1;
        }else{
            mg[st[top].i][st[top].j]=0;
            top--;
        }
    }
    return 0;
}