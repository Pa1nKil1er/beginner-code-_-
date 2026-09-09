#include <bits/stdc++.h>
using namespace std;
//即求这个无向图中，彼此独立的图有几个
int n,m;
int sum=0;
int p,q; 
vector<vector<int>> graph(100000);
//ヾ(≧▽≦*)o灵活点在于邻接表难以判断是否遍历过，解决的办法也很简单，另开一个数组
queue<int> bfs;//不会bfs，但是队列起手应该没错
int visited[100010];
int main(){
    memset(visited, 0, sizeof(visited));
    cin>>n>>m;
    for(int i=1;i<=m;i++){//注意邻接表是以边为核心的，所以是m
        cin>>p>>q;
        graph[p].push_back(q);
        graph[q].push_back(p);
        /*bfs.push(p);
        bfs.push(q);*/
    }
    //遍历一下整个图
    for(int i=1;i<=n;i++){//注意这里遍历的是顶点
        //auto com=graph[i].front;
        if(visited[i]!=1){
            bfs.push(i);
            visited[i]=1;
            //应该在这里sum++,代表这个点是未被走过的
            sum++;
        }
        while(!bfs.empty()){
            int com=bfs.front();
            bfs.pop();
            /*if((graph[com].empty())){
                sum++;//这样的话显得只有孤立结点才会被计数，不合要求
            }else{*/
                int len=graph[com].size();
                for(int j=len-1;j>=0;j--){
                    if(visited[graph[com][j]]==0){
                        bfs.push(graph[com][j]);
                        visited[graph[com][j]]=1;
                    }
                    //不需要，因为遍历是倒着遍历的graph[com].pop_back();
                }
            //}
        }

    }
    cout<<sum;
}