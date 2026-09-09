#include <bits/stdc++.h>
using namespace std;
int x,y;
int n,m;
int num,sum=0;
int main(){
    cin>>n>>m;
    x=(m+1)/2;y=(n+1)/2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>num;
            if(i==y) sum+=num;
            else if(j==x) sum+=num;
            else if(i+j==x+y) sum+=num;
            else if(i-j==x-y) sum+=num;
            else if(abs(i-y)+abs(j-x)<=4) sum+=num;
        }
    }
    cout<<sum;
}