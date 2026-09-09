#include <bits/stdc++.h>
using namespace std;
string s1;
int n,a[110];
int main(){
    cin>>n;
    for(int i=n;i>=0;i--){
        cin>>a[i];
    }
    //
    for(int j=n;j>=1;j--){
        if(a[j]!=0){//常数项不为0才存在
            if(j!=n){//首项不加符号
            if(a[j]>0&&j!=1){
                cout<<"+";
            }
            }
            if(a[j]!=1&&a[j]!=-1) cout<<a[j];
            if(a[j]==-1) cout<<"-";
            cout<<"x";
            if(j!=1) cout<<"^"<<j;
        }
        }
        //将100x^5看成整体
        
    if(a[0]!=0){
        if(n!=0){
            if(a[0]>0) cout<<"+";
        }
        cout<<a[0];
    }
    
}