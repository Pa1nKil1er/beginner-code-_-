#include <bits/stdc++.h>
using namespace std;
int r,c,ans=0;
int dy[] = {-1, 1, 0, 0};  // 上、下、左、右
int dx[] = {0, 0, -1, 1};//哇还有这种写法
char mp[1010][1010];
int  check(int x,int y){
    if(mp[y][x-1]=='#'&&mp[y+1][x-1]=='#'&&mp[y+1][x]=='#') return 0;
    else if(mp[y][x+1]=='#'&&mp[y+1][x+1]=='#'&&mp[y+1][x]=='#') return 0;
    else if(mp[y][x-1]=='#'&&mp[y-1][x-1]=='#'&&mp[y-1][x]=='#') return 0;
    else if(mp[y][x+1]=='#'&&mp[y-1][x+1]=='#'&&mp[y-1][x]=='#') return 0;
    else return 1;
}
queue<pair<int,int>> qq;
int main(){
    cin>>r>>c;
    //bool visit[r][c]={false};
    vector<vector<bool>> visit(r+1, vector<bool>(c+1, false));
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>mp[i][j];
        }
    }
    //---------------------//
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(mp[i][j]=='.'){
                if(!check(j,i)){
                    cout<<"Bad placement.";
                    return 0;
                }
            }
            else if(mp[i][j]=='#'&&!visit[i][j]){
                ans++;
                visit[i][j]=true;
                qq.push({i,j});//将起点放入队列
                while(!qq.empty()){//队列为空则说明此时连通块里没有#了
                    auto [y,x]=qq.front();//??为什么用int 不行，用auto可以
                    //因为队列里存的是 pair<int,int> 类型，不是 int！
                    qq.pop();//把刚刚取出的元素pop掉
                    //先进先出，所以front访问队首元素，pop删除队首元素
                    //刚刚从队列里取出一个点
                    for(int k=0;k<=3;k++){
                        //x+=dx[k];这样x就被污染了
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        //向四周试探

                        if(nx>=1&&nx<=c&&ny>=1&&ny<=r&&!visit[ny][nx]&&mp[ny][nx]=='#'){
                            visit[ny][nx]=true;
                            qq.push({ny,nx});
                        }
                    }//这个for循环把四周的，是#的点都放进队列//这样是一层一层检索的，所以是bfs（？）
                    //而队列的 “先进先出” 特性刚好保证了这一点。
                }

            }
        }
    }
    cout<<"There are "<<ans<<" ships.";
    return 0;
}