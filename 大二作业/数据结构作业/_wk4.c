#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 实验名称：栈和队列的应用---数制转换
int stack[100];//使用简单的数组实现栈，base为0
int top=0;

int queue[100];//使用简单的数组实现队列
int front=0;
int rear=0;

double num=0;
void func(int x,double num);
char change(int number);

int main()
{
    while(1)
    {
        int choice =-1;
        printf("1.输入待转换的十进制实数  \n");
        printf("========================\n");
        printf("当前待转换数：%.10f\n", num);
        printf("2.转换为二进制数         \n");
        printf("3.转换为八进制数         \n");
        printf("4.转换为十六进制数       \n");
        printf("0.结束程序              \n");

        printf("请输入你的选择：\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("请输入待转换的十进制实数:\n");
            scanf("%lf",&num);
            break;
        case 2:
            func(2,num);
            break;
        case 3:
            func(8,num);
            break;
        case 4:
            func(16,num);
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }

}

void func(int x,double num)
{
    top=0;front=0;rear=0;//重置指针
    if(num<0){
        printf("-");
        num*=-1.0;
    }
    //先要分离整数和小数
    int integer=(int) num;
    double flo=num-integer;

    //整数部分
    if(integer==0) stack[++top]=0;
    else{
        while(integer){
        stack[++top]=integer%x;
        integer/=x;
        }
    }
    
    for(int i=top;i>=1;i--){
        printf("%c",change(stack[i]));
    }
    //小数部分
    //转换精度设置为10（？
    int count=0;
    while(flo>1e-10 && count<10){
        flo*=x;  int temp=(int)flo;
        queue[rear++]=temp;
        flo-=temp;
        count++;
    }
    if(rear>0) printf(".");
    for(int i=front;i<rear;i++){
        printf("%c",change(queue[i]));
    }
    printf("\n");
    return;
    
}

char change(int number){
    char c;
    if(number>9) c='A'+number-10;
    else c='0'+number;

    return c;
}
