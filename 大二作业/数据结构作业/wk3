#include <stdio.h>
#include <stdlib.h>
typedef struct Linked_List
{
    int data;
    struct Linked_List* next;

}List;

void print_List(List* L);
List* creat_List();

void merge_List(List* L1,List* L2);
void merge_odered_List(List* L1,List* L2,List* L);
void merge_List_evenorodd(List* L,List* L1,List* L2);

int main()
{
    printf("1.合并链表\n");
    List*L1=creat_List();
    List*L2=creat_List();
    merge_List(L1,L2);
    print_List(L1);

    printf("2.升序链表合并，（链表要升序输入）\n");
    List*L3=creat_List();
    List*L4=creat_List();
    List *L5=(List*)malloc(sizeof(List));
    L5->next=NULL;
    merge_odered_List(L3,L4,L5);
    print_List(L5);

    printf("3拆分链表\n");
    List*L6=creat_List();
    List *L7=(List*)malloc(sizeof(List));
    L7->next=NULL;
    List *L8=(List*)malloc(sizeof(List));
    L8->next=NULL;
    merge_List_evenorodd(L6,L7,L8);
    print_List(L7);
    print_List(L8);
}

List* creat_List()
{
    List *L=(List*)malloc(sizeof(List));
    L->next=NULL;

    List* r=L;
    printf("请输入链表数据（输入-1结束）\n");
    while(1)
    {
        int a=0;
        scanf("%d",&a);
        if(a==-1) break;

        List* newList=(List*)malloc(sizeof(List));
        newList->data=a;
        newList->next=NULL;
        r->next=newList;
        r=newList;
    }
    return L;
}
void print_List(List* L)
{
    List* p=L->next;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void merge_List(List* L1,List* L2)
{
    List* p1=L1;
    while(p1->next)
    {
        p1=p1->next;
    }
    p1->next=L2->next;
    free(L2);
}

void merge_odered_List(List* L1,List* L2,List* L)
{
    List* p1=L1->next;
    List* p2=L2->next;
    List* r=L;

    while(p1&&p2)
    {
        if(p1->data<p2->data)
        {
            r->next=p1;
            r=r->next;
            p1=p1->next;
        }
        else if(p1->data>=p2->data)
        {
            r->next=p2;
            r=r->next;
            p2=p2->next;
        }
    }

    if(p1) r->next=p1;
    else if(p2) r->next=p2;

    free(L1);
    free(L2);
}

void merge_List_evenorodd(List* L,List* L1,List* L2)
{
    List* p=L->next;
    List* p1=L1;//1为奇数链表，2为偶数链表
    List* p2=L2;

    while(p)
    {
        List* List_next=p->next;
        if(p->data%2==1)
        {
            p1->next=p;
            p1=p1->next;
            p=List_next;
        }
        else
        {
            p2->next=p;
            p2=p2->next;
            p=List_next;
        }
    }
    p1->next=NULL;
    p2->next=NULL;

    free(L);
}
