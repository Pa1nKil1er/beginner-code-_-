#include "supermarket.hpp"
// ====================== 文件读写功能 ======================
//加载记录
void Market_system::loadFromFile() {
    //加载商品
    ifstream finGoods("goods.txt");
    if (finGoods.is_open()) {
        int id;
        string name;
        double price;
        int stock;
        while (finGoods>>id>>name>>price>>stock) {
            Goods g(id,name,price,stock);
            depot.push_back(g);
            if (id>num) num=id;//保证ID自增正确
        }
        finGoods.close();
    }

    //加载销售记录
    ifstream finSale("sale.txt");
    if(finSale.is_open()){
        int gid,num;
        string name,date;
        double total;
        while(finSale>>gid>>name>>date>>num>>total) {
            Sale_record r(gid,name,date,num,total);
            bill.push_back(r);
        }
        finSale.close();
    }
}

// 保存记录
void Market_system::saveToFile() {
    //商品
    ofstream foutGoods("goods.txt");
    for (auto& g : depot){
        foutGoods<<g.getId()<<" "<<g.getName()<<" "<<g.getPrice()<<" "<<g.getStock()<<endl;
    }
    foutGoods.close();

    //销售记录
    ofstream foutSale("sale.txt");
    for (auto& r : bill) {
        foutSale<<r.getGoodsId()<<" "<<r.getGoodsName()<<" "<<r.getSaleDate()<<" "<<r.getSaleNum()<<" "<<r.getTotalPrice()<<endl;
    }
    foutSale.close();
}