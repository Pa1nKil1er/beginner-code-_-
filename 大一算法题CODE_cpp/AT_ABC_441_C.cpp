#include<bits/stdc++.h>
using namespace std;
long long n,k,x;
long long a[300010];
int main(){
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //要喝的酒起码要大于n-k（把水喝光），这样一定能喝到酒
    //接下来的之中把少的认为是酒，算喝几杯能喝到
    long long ans=0,sum=0;ans+=n-k;
    sort(a+1,a+n+1);
    for(int i=k;i>=1;i--){
        sum+=a[i];ans++;
        if(sum>=x){
            cout<<ans;break;
        }
        if(i==1&&sum<x){
            cout<<-1;
        }
    }
}