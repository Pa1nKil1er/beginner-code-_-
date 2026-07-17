#include "supermarket.hpp"

#include <fstream>

void show_menu() 
{
    cout << "\n====================超市收银系统====================" << endl;
    cout << "1. 添加商品信息" << endl;
    cout << "2. 修改商品信息" << endl;
    cout << "3. 删除商品信息        ──         ── " << endl;
    cout << "4. 商品销售            ●           ● " << endl;
    cout << "5. 查看销售记录      ///            ///" << endl;
    cout << "6. 退货处理                └───┘ " << endl;
    cout << "7. 查看所有商品（库存）" << endl;
    cout << "8. 销售统计" << endl;
    cout << "0. 退出系统" << endl;
    cout << "====================================================" << endl;
    cout << "请输入操作序号：";

    return;
}
int main()
{
    Market_system System;
    // 程序启动时加载文件（如果有旧数据，先读入）
    System.loadFromFile(); 
    int OPTION=-1;
    
    while(1)
    {
        //清屏
        system("cls");
        
        show_menu();

        cin>>OPTION;
        switch(OPTION)
        {
            case 1:
                System.add_goods();
                break;
            case 2:
                System.change_goods();
                break;
            case 3:
                System.delete_goods();
                break;
            case 4:
                System.sale();
                break;
            case 5:
                System.show_sale();
                break;
            case 6:
                System.return_goods();
                break;
            case 7:
                System.show_goods();
                break;
            case 8:
                System.sale_statistic();
                break;
            case 0:
                // 退出前保存数据到TXT
                System.saveToFile(); 
                cout << "退出系统，感谢使用！" << endl;
                return 0;
            default:
                cout << "输入无效，请重新选择！" << endl;
                break;
        }
        
        //调整界面
        cin.ignore();  // 清空缓冲区
        cin.get();    // 等待按回车继续
    
    }
    
}