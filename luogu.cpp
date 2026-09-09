#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> b(510);
int minnum[510];
int a[510][510];
int main(){
    cin>>n;
    n=n*(n-1)/2;
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++){
        cin>>a[i][j];
        b[i].push_back(a[i][j]);
        b[j].push_back(a[i][j]);
    }
        sort(b[i].begin(),b[i].end());
        minnum[i]=b[i][n-i-1];
    }
    sort(minnum+1,minnum+n);
    int ans=minnum[n-1];
    cout<<1<<"\n"<<ans;
}