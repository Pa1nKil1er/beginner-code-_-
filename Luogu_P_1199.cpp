#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> b(550);
int minnum[510];
int a[510][510];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
        cin>>a[i][j];
        b[i].push_back(a[i][j]);
        b[j].push_back(a[i][j]);
    }
    }
    for(int i=1;i<=n;i++){
        sort(b[i].begin(),b[i].end());
        minnum[i]=b[i][n-3];////注意vector从0开始，与我的习惯不同
    }
    sort(minnum+1,minnum+n+1);
    int ans=minnum[n];
    cout<<1<<"\n"<<ans;
}