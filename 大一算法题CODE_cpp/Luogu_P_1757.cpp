#include <bits/stdc++.h>
using namespace std;
//同一组的只能选一个，那就针对组内的物品再进行一次背包
//（即不是01背包，而是1234..背包
//利用结构体怎么样
struct zushu{
    vector<int> a;//重量
    vector<int> b;//价值
    //vector<int> c;//组数
}z[110];
int m,n;//m为书包容量，n为物品数（但是这里的主轴应该是组数了吧？ 
int dp[1010][1010];
int aa,bb,cc;
int zu=0;//总组数
int main(){
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>aa>>bb>>cc;
        if(cc>zu) zu=cc;
        z[cc].a.push_back(aa);
        z[cc].b.push_back(bb);
        //z[cc].c.push_back(cc);
    }
    for(int i=1;i<=zu;i++){
        for(int j=)
    }
}
