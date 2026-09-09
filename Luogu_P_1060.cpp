#include <bits/stdc++.h>
using namespace std;
int n,m,v[30],p[30];// v 表示该物品的价格p 表示该物品的重要度
int vp[30];//感觉重要度没啥用，重要的是二者乘积
vector<vector<int>> dp(30,vector<int>(30010));//vw[m][n];列表示商品数，行表示家具数
int main(){
    cin>>n>>m;//n 表示总钱数，m 为希望购买物品的个数。
    for(int i=1;i<=m;i++){
        cin>>v[i]>>p[i];
        vp[i]=v[i]*p[i];
    }

    for(int i=1;i<=m;i++){
        dp[i]=dp[i-1];
        for(int j=v[i];j<=n;j++){
            dp[i][j]=max({dp[i][j],dp[i-1][j-v[i]]+vp[i]});
        }
    }
    cout<<dp[m][n];
}
