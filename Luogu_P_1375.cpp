#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll h[100010];
ll mod_=1000000007;
ll hh(int n){
    if(h[n]!=0) return h[n];
    else{
        for(int i=1;i<n;i++){
            h[n]+=(hh(n-i)*hh(i))%mod_;
            h[n]%=mod_;
        }
        return h[n];
    }
}
int main(){
h[1]=1;h[2]=1;h[3]=2;
    int n;
    cin>>n;
    n+=1;
    cout<<hh(n);
}