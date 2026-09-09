#include <bits/stdc++.h>
using namespace std;
int maxstar=0;//最大星系的大小
int sum=0;//星系的数量
int zuo[100010];//星座数量相同的视作一个星系
int n,m;
char gra[2000][2000];
//最小单位是星座，所以dfs的应该是星座
int tx[]={1,0,-1,0};
int ty[]={0,-1,0,1};
void dfs(int nx,int ny,int num){//num用于记录星座的大小
    if(nx>n||ny>m||nx<=0||ny<=0||gra[ny][nx]=='.') return; 
    for(int i=0;i<=3;i++){
        int x=nx+tx[i];int y=ny+ty[i];
        if(x>n||y>m||x<=0||y<=0||gra[y][x]=='.') continue;
        gra[y][x]='.';
        dfs(x,y,num+1);//突然感觉好像没必要回溯？
        gra[y][x]='*';
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>gra[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(gra[i][j]=='*') dfs(j,i,1);

        }
    }
    
}