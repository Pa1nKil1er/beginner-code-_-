#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll bx,by,cx,cy;ll sum=0;
ll dp[30][30];ll mp[30][30];
ll ty[]={0,1};ll tx[]={1,0};//右和下
//先定义后调用，这样main里无法调用dfs
//void dp(ll y,ll x);
int main(){
    cin>>bx>>by>>cx>>cy;
    bx++;by++;cx++;cy++;//防止0导致的re
    //直接标记会导致re
    //mp[cy-1][cx+2]=1;mp[cy-1][cx-2]=1;mp[cy+1][cx+2]=1;mp[cy+1][cx-2]=1;mp[cy-2][cx-1]=1;mp[cy-2][cx+1]=1;mp[cy+2][cx+1]=1;mp[cy+2][cx-1]=1;mp[cy][cx]=1;
    ll horse_ty[]={0,1,-1,1,-1,2,-2,2,-2}; 
    ll horse_tx[]={0,2,2,-2,-2,1,1,-1,-1}; 
    for (int i=0;i<=8;i++) {
        ll ny=cy+horse_ty[i]; 
        ll nx=cx+horse_tx[i];
    //仅标记在合法范围内的控制点
    if (ny>0&&ny<=by&&nx>0&&nx<=bx){
        mp[ny][nx]=1;
        dp[ny][nx]=0;
    }
}

    if(bx==1&&by==1) cout<<1;
    else if(bx<1||by<1) cout<<0;
    //还漏考虑了马和卒重叠的情况（话说有可能吗
    else if(bx==cx&&by==cy) cout<<0;
    else{
        dp[1][1]=1;
        //just like 前缀和？
        for(int y=1;y<=by;y++){
            for(int x=1;x<=bx;x++){
                if(mp[y][x]==1) continue;
                //关键：防止起始点被覆盖
                if(y==1 && x==1) continue;
                dp[y][x]=dp[y][x-1]+dp[y-1][x];
                if(y==by&&x==bx) sum=dp[y][x];
            }
        }
        cout<<sum;
    }
}


//void dfs(int y,int x){
/*void dp(int y,int x){
    /*if(y==by&&x==bx){
        sum++;return;
    }else*/
    /*if(y==by&&x==bx){sum=mp[y][x]; return;}
    else if(y!=by||x!=bx){
        for(int i=0;i<=1;i++){
            //漏考虑边界
            //if(mp[y+ty[i]][x+tx[i]]==0){
            if(mp[y+ty[i]][x+tx[i]]==0&&y+ty[i]<=by&&x+tx[i]<=bx){
                mp[y+ty[i]][x+tx[i]]+=mp[y][x];
                dp(y+ty[i],x+tx[i]);
                //如果不还原mp[y+ty[i]][x+tx[i]]=0;//要还原的吧
            }
    }
    return;
    }*/