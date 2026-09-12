#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct goods_type {
    int num;
    char name[50];
    float price;
    int stock;
} DataType;

typedef struct {
    DataType data[MAX_SIZE];
    int length;
} SeqList;

void showMenu();
void inputGoods(SeqList* L);
void sortByNum(SeqList* L);
void sortByStock(SeqList* L);
void printGoods(SeqList* L);

int SearchList(SeqList*L,int num);
void DeleteGoods(SeqList*L,int num);
void SaleGoods(SeqList *L);
void AddGooods(SeqList *L);
void ScanGoods(SeqList *L);

int main() {
    SeqList L;
    L.length = 0;

    int choice;

    while (1) {
        showMenu();
        printf("请输入您的选择: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputGoods(&L);
                break;
            case 2:
                sortByNum(&L);
                break;
            case 3:
                sortByStock(&L);
                break;
            case 4:
                printGoods(&L);
                break;
            case 5:
                SaleGoods(&L);
                break;
            case 6:
                AddGooods(&L);
                break;
            case 7:
                ScanGoods(&L);
                break;
            case 0:
                printf("\n感谢使用，系统已退出！\n");
                exit(0);
            default:
                printf("\n输入有误，请重新输入（0-7）！\n");
                break;
        }
        printf("\n按回车键继续...");
        getchar();
        getchar();
    }

    return 0;
}

void showMenu() {
    printf("\n**********系统功能菜单**********\n");
    printf("*  1--------输入商品信息      *\n");
    printf("*  2--------按编号排序        *\n");
    printf("*  3--------按库存排序        *\n");
    printf("*  4--------输出商品信息      *\n");
    printf("*  5--------商品销售          *\n");
    printf("*  6--------商品入库          *\n");
    printf("*  7--------商品清库          *\n");
    printf("*  0--------退出系统          *\n");
    printf("********************************\n");
}

void inputGoods(SeqList* L) {
    int n;
    printf("请输入要录入的商品数量: ");
    scanf("%d", &n);
    if (L->length + n > MAX_SIZE) {
        printf("商品数量超出上限！最多还能录入 %d 个商品。\n", MAX_SIZE - L->length);
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\n请输入第 %d 个商品的信息:\n",i+1);
        printf("商品编号: ");
        scanf("%d", &L->data[L->length].num);
        printf("商品名称: ");
        scanf("%s", L->data[L->length].name);
        printf("商品单价: ");
        scanf("%f", &L->data[L->length].price);
        printf("商品库存: ");
        scanf("%d", &L->data[L->length].stock);

        L->length++;
    }
    printf("\n商品信息录入成功！\n");
}

void sortByNum(SeqList* L) {
    if (L->length < 2) {
        printf("商品数量少于2个，无需排序！\n");
        return;
    }

    DataType temp;
    for (int i = 0; i < L->length - 1; i++) {
        for (int j = 0; j < L->length - 1 - i; j++) {
            if (L->data[j].num > L->data[j + 1].num) {
                temp = L->data[j];
                L->data[j] = L->data[j + 1];
                L->data[j + 1] = temp;
            }
        }
    }
    printf("\n已按商品编号从小到大完成排序！\n");
}

void sortByStock(SeqList* L) {
    if (L->length < 2) {
        printf("商品数量少于2个，无需排序！\n");
        return;
    }

    DataType temp;
    for (int i = 0; i < L->length - 1; i++) {
        for (int j = 0; j < L->length - 1 - i; j++) {
            if (L->data[j].stock > L->data[j + 1].stock) {
                temp = L->data[j];
                L->data[j] = L->data[j + 1];
                L->data[j + 1] = temp;
            }
        }
    }
    printf("\n已按商品库存量从小到大完成排序！\n");
}

void printGoods(SeqList* L) {
    if (L->length == 0) {
        printf("\n当前没有商品信息，请先输入商品信息！\n");
        return;
    }

    printf("\n%-10s %-20s %-10s %-10s\n", "商品编号", "商品名称", "商品单价", "商品库存");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < L->length; i++) {
        printf("%-10d %-20s %-10.2f %-10d\n",
               L->data[i].num, L->data[i].name, L->data[i].price, L->data[i].stock);
    }
}
int SearchList(SeqList*L,int num)
{
    for(int i=0;i<L->length;i++)
    {
        if(L->data[i].num==num)
        {
            return i;
        }
    }
    return -1;
}

void SaleGoods(SeqList *L){
    int goodsnumber=0;
    int goodsnum=0;
    int goodsplace=0;
    float money=0;
    printf("请输入销售物品的编号与数量\n");
    scanf("%d",&goodsnumber);
    scanf("%d",&goodsnum);
    goodsplace=SearchList(L,goodsnumber);
    if(goodsplace==-1)
    {
        printf("该商品不存在，请检查所输入编号\n");
    }
    else
    {
        printf("已查找到商品%s\n",L->data[goodsplace].name);
        if(L->data[goodsplace].stock<goodsnum)
        {
            printf("抱歉，库存不足。");
        }
        else
        {
            L->data[goodsplace].stock-=goodsnum;
            money=goodsnum*L->data[goodsplace].price;
            printf("销售成功，顾客应付金额为%f元",money);
        }
    }
}
void AddGooods(SeqList *L)
{
    int goodsplace=0;
    int goodsnumber=0;
    int goodsnum=0;
    printf("请输入库物品的编号和数量\n");
    scanf("%d",&goodsnumber);
    scanf("%d",&goodsnum);
    goodsplace=SearchList(L,goodsnumber);
    if(goodsplace==-1)
    {
        printf("该商品为新增商品\n");
        printf("请输入该商品的信息:\n");
        L->data[L->length].num=goodsnumber;
        printf("商品名称: ");
        scanf("%s", L->data[L->length].name);
        printf("商品单价: ");
        scanf("%f", &L->data[L->length].price);
        L->data[L->length].stock=goodsnum;
        L->length++;
    }
    else
    {
        printf("已查找到商品%s\n",L->data[goodsplace].name);
        L->data[goodsplace].stock+=goodsnum;
        printf("商品入库成功\n");
    }
}
void DeleteGoods(SeqList*L,int num)
{
    for(int i=num;i<L->length-1;i++)
    {
        L->data[i]=L->data[i+1];
    }
    L->length--;
}
void ScanGoods(SeqList *L)
{
    printf("现在开始检查哪些商品已售尽\n");
    int flag=0;
    int choice=-1;
    while(flag<L->length)
    {
        if(L->data[flag].stock==0)
        {
            printf("发现库存为0的物品：%s\n",L->data[flag].name);
            printf("是否需要清除该商品？（需要请输1，否则输入0）\n");
            scanf("%d",&choice);
            if(choice==1)
            {
                DeleteGoods(L,flag);
                printf("已清除。\n");
            }
            else
            {
                printf("好的，已保留该商品\n");
                flag++;
            }
        }
        else
        {
            flag++;
        }
    }
    printf("所有商品均经过检查。\n");
}
