#include "supermarket.hpp"

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

void Market_system::sale()
{
    cout << "\n====================商品销售========================" << endl;
    if(!check_stock()) return;
   int targetID=get_targetID();
   cout<<"该商品为：\n";
   depot[targetID].show_goods();

   cout<<"请输入销售数量\n";
   int salenum=0;cin>>salenum;
   if(salenum>depot[targetID].getStock())
   {
    cout<<"库存不足,当前库存为"<<depot[targetID].getStock();
    return;
   }

   depot[targetID].setStock(depot[targetID].getStock()-salenum);

   //关于日期的处理
   string Date;
   Date = getNowDate(); // 自动获取今天日期

   num2++;
   Sale_record B(targetID,depot[targetID].getName(),Date,salenum,salenum*depot[targetID].getPrice());
   bill.push_back(B);
   cout << "====================================================" << endl;
}

void Market_system::show_sale()
{
    //for(int i=bill.begin();i<bill.end();i++)
    cout << "======================销售记录=======================" << endl;
    for(int i=0;i<bill.size();i++)
    {
        bill[i].show_salerecord();
        cout<<"\n";
    }
    cout << "====================================================" << endl;
    return;
}

void Market_system::return_goods()
{
    cout << "\n====================商品退货========================" << endl;
    if(!check_stock()) return;
    int targetID=get_targetID();

    cout<<"该商品为：\n";
    depot[targetID].show_goods();

    cout<<"请输入退货数量\n";
    int returnnum=0;cin>>returnnum;

    depot[targetID].setStock(depot[targetID].getStock()+returnnum);

    //关于日期的处理
    string Date;
    //getline(cin,Date);
    Date = getNowDate(); // 自动获取今天日期
    
    num2++;
    Sale_record B(targetID,depot[targetID].getName(),Date,(-1)*returnnum,(-1)*returnnum*depot[targetID].getPrice());
    bill.push_back(B);
    cout << "====================================================" << endl;
    return;
}

void Market_system::sale_statistic()
{
    if(bill.empty()){
        cout<<"暂无任何销售记录\n";
        return;
    }
    double allMoney=0;
    int allCount=0;
    map<int,pair<int,double>> sale_data; //key:商品ID, 销量、总金额
    for(auto &rec : bill){
        int id = rec.getGoodsId();
        int cnt = rec.getSaleNum();
        double money = rec.getTotalPrice();
        sale_data[id].first+=cnt;
        sale_data[id].second+=money;
        allCount+=cnt;
        allMoney+=money;
    }
    cout<<"===========销售统计报表===========\n";
    cout<<"商品ID\t销量\t总销售额\n";
    for(auto &p : sale_data){
        cout<<p.first<<"\t"<<p.second.first<<"\t"<<p.second.second<<"\n";
    }
    cout<<"---------------------------------\n";
    cout<<"总销售件数:"<<allCount<<"\n";
    cout<<"总营收金额:"<<allMoney<<"\n";
    cout<<"=================================\n";

}