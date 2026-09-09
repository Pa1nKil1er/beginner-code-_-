#include <bits/stdc++.h>
using namespace std;
int r,maxq=0;
int f[1010][1010];
int num[1010][1010];
int main(){
    cin>>r;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=i;j++){
            cin>>num[i][j];
        }
    }
    //f[1][1]=num[1][1];
    //顺：
    /*for(int i=1;i<=r;i++){
        for(int j=1;j<=i;j++){
            f[i][j]=max({f[i-1][j],f[i-1][j-1]})+num[i][j];
            if(i==r){
                if(maxq<f[i][j]) maxq=f[i][j];
            }
        }
    }*/
   //逆着怎么写？：
   for(int i=r;i>=2;i--){
        for(int j=i;j>=1;j--){
            f[i][j]=max({f[i+1][j],f[i+1][j+1]})+num[i][j];
            if(i==2){
                if(maxq<f[i][j]) maxq=f[i][j];
            }
        }
    }
    maxq+=+num[1][1];
    cout<<maxq;
}