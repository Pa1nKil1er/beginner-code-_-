#include <bits/stdc++.h>
using namespace std;
int n,m,t; int sx,sy,fx,fy;
int sum=0;
int gra[100][100];
int tx[4]={1,0,-1,0}; int ty[4]={0,-1,0,1};
void dfs(int nx,int ny){
    if(nx==fx&&ny==fy)
    {
        sum++;return;
    }
    //if(nx>=n||nx<=0||ny>=m||ny<=0||gra[ny][nx]==1||gra[ny][nx]==2) return;
    for(int i=0;i<=3;i++){
        int x=nx+tx[i];int y=ny+ty[i];
        if(x>n||x<=0||y>m||y<=0||gra[y][x]==1||gra[y][x]==2) continue;
        gra[y][x]=1;
        dfs(x,y);
        gra[y][x]=0;
    }
}
int main()
{
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            gra[i][j]=0;
        }
    }
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    while(t--)
    {
        int a,b; cin>>a>>b;
        gra[b][a]=2;
    }
    gra[sy][sx]=1;//第二版
    dfs(sx,sy);
    cout<<sum;
}