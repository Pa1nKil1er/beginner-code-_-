#include <bits/stdc++.h>
using namespace std;
int t,n;
int dx[5]={0,0,1,0,-1};//上右下左
int dy[5]={0,1,0,-1,0};
int gra[2010][2010];
int bfs(int a,int b){
    queue<pair<int,int>> bbfs;
    bbfs.push({a,b});
    while(!bbfs.empty()){
        auto[y,x]=bbfs.front();
        bbfs.pop();
        for(int i=1;i<=4;i++){
            int y1=y,x1=x;
        y1+=dy[i];x1+=dx[i];
        if(gra[y1][x1]==0&&y1<=n&&y1>=1&&x1<=n&&x1>=1){
            gra[y1][x1]=1;
            bbfs.push({y1,x1});
        }
    }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(int j=1;j<=n;j++){
                gra[i][j]=s[j-1]-'0';
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(gra[i][j]==0&&(gra[i+1][j]==1||gra[i-1][j]==1||gra[i][j+1]==1||gra[i][j-1]==1)){
                    gra[i][j]=1;
                    bfs(i,j);
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<gra[i][j];
                if(j==n) cout<<"\n";
            }
        }
    }
}