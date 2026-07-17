#ifndef BASE_H
#define BASE_H
//——————————————————————————————————————————————
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
/*办法1：加 inline
string getNowDate() {
    time_t now = time(0);
    tm ltm = *localtime(&now);
    
    char buf[100];
    sprintf(buf, "%04d-%02d-%02d", 
            1900 + ltm.tm_year, 
            1 + ltm.tm_mon, 
            ltm.tm_mday);
    
    return string(buf);
}
*/


class Goods{
private:
    int id;
    string name;
    double price;
    int stock;
public:
    Goods()
    : id(0),name("待记录物品"),price(0),stock(0)
    {}
    Goods(int ID,string Name,double Price,int Stock)
    : id(ID),name(Name),price(Price),stock(Stock)
    {
        cout<<"已创建完成。\n";
    }

    int getId() const {return id;}
    string getName() const {return name;}
    double getPrice() const {return price;}
    int getStock() const {return stock;}
    void show_goods(){
        cout<<"商品ID:"<<getId()<<" ";
        cout<<"商品名称:"<<getName()<<" ";
        cout<<"价格:"<<getPrice()<<" ";
        cout<<"库存:"<<getStock()<<"\n";
        return;
    }
    void setName(string newName) {name = newName;}
    void setPrice(double newPrice) {price = newPrice;}
    void setStock(int newStock) {stock = newStock;}
};

class Sale_record //: public Goods
{
private:
    int id;
    string name;
    string date;
    int number;
    double total_price;
public:
    Sale_record()
    :id(0),name("待记录物品"),date("未知"),number(0),total_price(0)
    {}
    Sale_record(int ID,string Name,string Date,int Number,double TotalPrice)
    :id(ID),name(Name),date(Date),number(Number),total_price(TotalPrice)
    {}
    int getGoodsId() const {return id;}
    string getGoodsName() const {return name;}
    string getSaleDate() const {return date;}
    int getSaleNum() const {return number;}
    double getTotalPrice() const {return total_price;}
    void show_salerecord()
    {
        cout<<"商品ID:"<<id<<" ";
        cout<<"商品名称:"<<name<<" ";
        cout<<"日期:"<<date<<" ";
        cout<<"销售数目:"<<number<<" ";
        cout<<"销售额:"<<total_price<<"\n";
        return;
    }
};
//——————————————————————————————————————————————
#endif