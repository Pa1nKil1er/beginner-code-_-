#include <bits/stdc++.h>
using namespace std;
int l,r;
int m;
int last;
int flag=0;
int sum=0;
void print(int l,int r){
    cout<<l<<" "<<r<<"\n";
    return;
}
void f(int l,int r){
    sum=((l+r)*(r-l+1))/2;
    if(l>=m/2+1) return;
    if(sum==m){ print(l,r); f(l+1,l+2);}
    else if(sum<m){  f(l,r+1);}
    else if(sum>m){  f(l+1,l+2);}
}
int main(){
    cin>>m;
    l=1;r=l+1;
    f(l,r);
    return 0;
}