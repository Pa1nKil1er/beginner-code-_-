#include <bits/stdc++.h>
using namespace std;
int n,m,x_,y_;
int gra[500][500];
queue<pair<int,int>> q;
int tx[]={1,2,-1,-1,1,2,-2,-2};
int ty[]={2,1,2,-2,-2,-1,1,-1};
void bfs(int nx,int ny,int num){
    q.push({nx,ny});
    gra[nx][ny]=0;
    int x0=nx;int y0=ny;//初始位置
    while(!q.empty()){
        auto [nx,ny]=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int x=nx+tx[i];int y=ny+ty[i];
            if(x<=n&&x>=1&&y>=1&&y<=m&&gra[x][y]==-1){
                num=gra[nx][ny]+1;//这样！是我自己想到的喔！
                q.push({x,y});
                gra[x][y]=num;
            }
        }
    //num++;这个不是按照层数增长的，怎么保证层数呢？
    }
    return;
}
int main(){
    cin>>n>>m>>x_>>y_;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        gra[i][j]=-1;

    bfs(x_,y_,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<gra[i][j];
            cout<<" ";
        }
        cout<<"\n";
    }
}