#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll h[16];
ll hh(int n){
    if(h[n]!=0) return h[n];
    else{
        for(int i=1;i<n;i++){
            h[n]+=(hh(n-i)*hh(i));
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