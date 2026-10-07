#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//第五周课后实验作业：栈的应用——中缀算术表达式求值
//关于top记得调用时要-1，比如oper.oper[(oper.top)-1]
//compute(num.num[num.top-2],num.num[num.top-1],oper.oper[(oper.top)-1])
//这里要注意取数的先后，并且注意运算符的弹出和入栈

//关于将运算符进栈的时机一直没选好，总是迷迷糊糊放到while循环里。应该放在while外面！while计算完再进栈新的。
typedef struct num_stack
{
    double num[10010];
    int top;
    int base;
}number;
//操作数栈和运算符栈,注意数组从0开始存
typedef struct operator_stack
{
    char oper[10010];
    int top;
    int base;
}opera;
double compute(double a,double b,char c)
{
    if(c=='+') return a+b;
    else if(c=='-') return a-b;
    else if(c=='*') return a*b;
    else if(c=='/') return a/b;
    return -1;
}
int priority(char a)
{
    if(a=='#') return 0;
    else if(a=='+') return 1;
    else if(a=='-') return 1;
    else if(a=='*') return 2;
    else if(a=='/') return 2;
    return -1;
}
char s[100];
number num={.top=0,.base=0};
opera oper={.top=1,.base=0};//c不可以在初始化列表对数组特定元素赋值，本来想赋值第一个元素为#的
int main()
{
    while(1)
    {
        int choice=-1;
        printf("————————————————————————————\n");
        printf("1——输入待计算的中缀算术表达式\n");
        printf("2——执行表达式求值并输出结果\n");
        printf("0——结束程序\n");
        printf("————————————————————————————\n");
        printf("此刻的表达式是%s\n",s);
        printf("————————————————————————————\n");
        printf("您的选择是？\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                scanf("%s",s);
                break;
            case 2:
            {    //number num={.top=0,.base=0};
                //opera oper={.top=1,.base=0};
                num.top = 0;   num.base = 0;
                oper.top = 1;  oper.base = 0;
                oper.oper[0] = '#';
                //在这里初始化
                double temp=0;
                char t='#';
                int i=0;
                int flag=0;
                while(s[i])
                {
                    //读取数字
                    if(s[i]<='9'&&s[i]>='0')
                    {
                        flag=1;
                        temp=temp*10+s[i]-'0';
                    }
                    //else if(flag==-1){num.num[(num.top)++]=temp; temp=0;}
                    //括号
                    if(s[i]=='(') 
                    {
                        if(flag==1) {num.num[(num.top)++]=temp; temp=0;flag=0;}
                        oper.oper[(oper.top)++]=s[i];
                    }
                    if(s[i]==')')
                    {
                        if(flag==1) {num.num[(num.top)++]=temp; temp=0;flag=0;}
                        while(oper.oper[(oper.top)-1]!='(')
                        {
                            double number=compute(num.num[num.top-2],num.num[num.top-1],oper.oper[(oper.top)-1]);
                            num.top-=2; oper.top-=1;
                            num.num[(num.top)++]=number;
                        }
                        oper.top--;//要记得弹掉(

                    }
                    //读取操作符
                    if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
                    {
                        if(flag==1) {num.num[(num.top)++]=temp; temp=0;flag=0;}
                        if(oper.oper[(oper.top)-1]=='(')
                            oper.oper[(oper.top)++]=s[i];

                        else if(priority(oper.oper[(oper.top)-1])>=priority(s[i]))
                        {
                            while(priority(oper.oper[(oper.top)-1])>=priority(s[i]))
                            {
                                double number=compute(num.num[num.top-2],num.num[num.top-1],oper.oper[(oper.top)-1]);
                                num.top-=2; oper.top-=1;
                                num.num[(num.top)++]=number;
                            }
                            oper.oper[(oper.top)++]=s[i];
                        }
                        else
                        {
                            oper.oper[(oper.top)++]=s[i];
                        }
                    }
                    i++;
                }
                //注意这里还要再弹一次
                if(flag==1) {num.num[(num.top)++]=temp; temp=0;flag=0;}
                while(oper.top>1)
                {
                    double number=compute(num.num[num.top-2],num.num[num.top-1],oper.oper[(oper.top)-1]);
                    num.top-=2; oper.top-=1;
                    num.num[(num.top)++]=number;
                }
                printf("%g\n",num.num[num.top-1]);//g的输出比f好看
                break;
            }
            case 0:
                return 0;
            default:
                printf("\n输入有误，请重新输入（0-7）！\n");
                break;
        }
    }
    
    
}
