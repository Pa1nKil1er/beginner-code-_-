#include "supermarket.hpp"
//int main()
//{
void Market_system::add_goods()//添加商品
{
    cout << "\n====================添加商品========================" << endl;
    cin.ignore();
    string Name;
    double Price=0;int Stock=0;
    num++;
    cout<<"请输入商品名称：\n";
    cin>>Name;
    cout<<"\n请输入商品单价:\n";
    cin>>Price;
    cout<<"\n请输入商品库存:\n";
    cin>>Stock;
    Goods A(num,Name,Price,Stock);
    depot.push_back(A);
    cout << "====================================================" << endl;
}


void Market_system::change_goods()
{
    cout << "\n====================商品信息修改====================" << endl;
    if(!check_stock()) return;

    /*int targetID=0;
    cout<<"请输入要修改的商品ID\n";
    cin>>targetID;
    */
    int targetID=get_targetID();
    cin.ignore();
    
    cout<<"当前商品信息为：\n";
    depot[targetID].show_goods();
    

        cout<<"请问您要修改的是 1.商品部分信息 还是 2.整体商品信息？\n";
        cout<<"请输入您的选择：\n";
        int op1=0;
        cin>>op1;
        if(op1==2)
        {
            cin.ignore();
            cout<<"请输入新名称：\n";
            cout<<"（回车保留原名称）\n";
            string newname;
            getline(cin,newname);
            if(!newname.empty()) depot[targetID].setName(newname); 
            
            //cin.ignore();
            cout<<"请输入新单价：\n";
            cout<<"（输入-1保留原价格）"<<endl;
            int newprice=-1;
            cin>>newprice;
            if(newprice!=-1) depot[targetID].setPrice(newprice);
            
            cin.ignore();
            cout<<"请输入新库存：\n";
            cout<<"（输入-1保留原库存）"<<endl;
            int newstock=-1;
            cin>>newstock;
            if(newstock!=-1) depot[targetID].setStock(newstock);

        }
        else if(op1==1)
        {
            cout<<"您要修改的是：\n";
            cout<<"1.名称 2.单价 3.库存 ";
            cout<<"请输入您的选择 : "; 
            int opt2=-1;
            cin>>opt2;
            if(opt2==1)
            {
                cout<<"请输入新单价：\n";
                double newprice=-1;
                cin>>newprice;
                if(newprice!=-1) depot[targetID].setPrice(newprice);
            }
            else if(opt2==2)
            {
                cout<<"请输入新单价：\n";
                cout<<"（输入-1保留原价格）"<<endl;
                double newprice=-1;
                cin>>newprice;
                if(newprice!=-1) depot[targetID].setPrice(newprice);
            }
            else if(opt2==3)
            {
                cout<<"请输入新库存：\n";
                cout<<"（输入-1保留原库存）"<<endl;
                int newstock=-1;
                cin>>newstock;
                if(newstock!=-1) depot[targetID].setStock(newstock);
            }
        }
    cout << "====================================================" << endl;

    return;
}


void Market_system::delete_goods()
{
   //if(depot.empty()){
   //     cout<<"目前仓库无商品\n";
   //     return;
    //}
    cout << "\n====================商品删除========================" << endl;
    if(!check_stock()) return;

    /*int targetID=0;
    cout<<"请输入要修改的商品ID\n";
    cin>>targetID;*/
    int targetID=get_targetID();

    depot[targetID].setName("待记录物品");
    depot[targetID].setPrice(0);
    depot[targetID].setStock(0);
    cout << "====================================================" << endl;
    return;
}

void Market_system::show_goods()
{
    cout << "=======================商品列表=====================" << endl;
    for(int i=0;i<depot.size();i++){
        depot[i].show_goods();
    }
    cout << "====================================================" << endl;
    return;
}


//}