#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f1=1,f2=1;
ll tesp;
ll m;
/*ll fib(ll i){
    if(f[i]!=0) return f[i];
    else{
        f[i]=fib(i-1)+fib(i-2); return f[i];
    }
}*/
int main(){
    cin>>m;
    for(ll i=3;i<=100100000;i++){
        if(f2==1){
            if(f1==0){
                cout<<i-2;
                break;
            }
        }
        tesp=f2;
        f2=((f1%m)+f2%m)%m;
        f1=tesp%m;
    }
    return 0;
}