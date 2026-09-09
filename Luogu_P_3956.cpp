#include <bits/stdc++.h>
using namespace std;
//要考虑的东西似乎很多，但感觉难度并没有激增，应该考虑一些细节即可
//感觉有点dp的想法，因为是格子（？）
int m,n;
int gra[110][110];
int coin[110][110];
void dfs(int nx,int ny,int sum){
    if(nx==m&&ny==m) if(coin[ny][nx]>sum) coin[ny][nx] =sum;
}
int main(){
    cin>>m>>n;
    while(n--){
        int y,x,a;
        cin>>y>>x>>a;
        gra[y][x]=a+1;//1为红，2为黄，0为无色
    }
    dfs(1,1,0);
}