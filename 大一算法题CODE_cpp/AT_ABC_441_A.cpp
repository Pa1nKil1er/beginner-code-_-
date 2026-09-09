#include<bits/stdc++.h>
using namespace std;
long long x,y,p,q;
int main(){
    cin>>p>>q;
    cin>>x>>y;
    if(x>=p&&y>=q&&x<=p+99&&y<=q+99){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}