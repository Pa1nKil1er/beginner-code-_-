#include <bits/stdc++.h>
using namespace std;
int dp[200010];
int n,a[200010];
int ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ans=a[1];
    for(int i=1;i<=n;i++){
        dp[i]=max({a[i],dp[i-1]+a[i]});
        if(ans<dp[i]) ans=dp[i];
    }
    cout<<ans;
    return 0;
}