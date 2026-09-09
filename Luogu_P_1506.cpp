#include <bits/stdc++.h>
using namespace std;
char m[510][510];
int tx[5]={0,1,0,-1,0};
int ty[5]={0,0,-1,0,1};//右下左上
int x=0,y=0,sum=0;
void dfs(int ax,int ay){
    if(m[ay][ax]!='0'||ax>x||ay>y||ax<1||ay<1) return;
    m[ay][ax]='1'; sum+=1;
    for(int i=1;i<=4;i++) dfs(ax+tx[i],ay+ty[i]);
    
}
int main(){
    cin>>y>>x;//y行x列
    for(int i=1;i<=y;i++){
        for(int j=1;j<=x;j++){
            cin>>m[i][j];
            if(m[i][j]=='*') sum++;
        }
    }
    for(int i=1;i<=x;i++){//对第一行与最后一行的可能出水点遍历
        dfs(i,1);
        dfs(i,y);
    }
    for(int i=1;i<=y;i++){//对第一列与最后一列的可能出水点遍历
        dfs(1,i);
        dfs(x,i);
    }
    sum=x*y-sum;
    cout<<sum;
}