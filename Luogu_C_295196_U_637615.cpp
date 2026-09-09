#include<bits/stdc++.h>
using namespace std;
int n,p,q;
char s[10];
int dfs(int n,int p,int q);
int main(){
    cin>>n>>p>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    
    int ans=qsum*psum;
    cout<<ans;
}