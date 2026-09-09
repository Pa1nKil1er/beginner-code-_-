#include <bits/stdc++.h>
using namespace std;
int a[30];
int s;
int gcd(int a,int b){
    int c;
    while(b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s=gcd(a[i],s);
    }
    cout<<abs(s);
}