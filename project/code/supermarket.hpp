#ifndef Super_H
#define Super_H
#include "base.hpp"
//int main()
//{
//Goods depot[]//仓库放货物
//数组容量太小，用vector
//vector<Goods> depot;
//vector<Sale_record> bill;
//用类封装——因为这样更安全，只留接口给外部
//int num=-1;
class Market_system
{
private:
    //static int num;
    int num=-1;
    int num2=-1;//销售记录的数字
    vector<Goods> depot;
    vector<Sale_record> bill;
public:
    void add_goods();//增改删
    void change_goods();
    void delete_goods();
    //展示
    void show_goods();

    void sale();
    void show_sale();
    void return_goods();
    void sale_statistic();

    //文件读写功能
    void loadFromFile();//从文件加载数据
    void saveToFile();//保存数据到文件

    bool check_stock()
    {
        if(depot.empty())
        {
        cout<<"====================================================\n";
        cout<<"目前仓库无商品!\n";
        cout<<"====================================================\n";
        return false;
        }
        return true;
    }

    int get_targetID()
    {
        int targetID=0;
        cout<<"请输入商品ID\n";
        cin>>targetID;
        return targetID;
    }
};
//static int num=0;

void show_menu();
//}
#endif