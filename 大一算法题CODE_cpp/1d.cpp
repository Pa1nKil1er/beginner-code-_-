#include <bits/stdc++.h>
using namespace std;
int p1=1,p2=1;//p1为质量可能，p2为数量可能
int n,p,q;
int qq[5000];//qq为具体数量
int pp[10];//pp为具体质量
int max1,max2;
char box[10];
int main(){
    cin>>n>>p>>q;
    qq[q]=1;
    pp[p]=1;
    pp[6]=1;
    pp[7]=1;
    max1=q;
    max2=p;
    for(int i=1;i<=n;i++){
        cin>>box[i];
        if(box[i]=='#'){
            for(int j=1;j<=max2;j++){
                if(pp[j]!=0){
                    p=j;
                if(pp[p+1]==0){
                pp[p+1]=1;
                p1+=1;
            }
                if(pp[p+2]==0){
                pp[p+2]=1;
                p1+=1;
            }
        }
            }
            if(max2+2<5) max2+=2;
            else max2=5;
        }
        if(box[i]=='+'){
            for(int j=1;j<=max1;j++){
                if(qq[j]!=0){
                    q=j;
                if(qq[q+1]==0){
                qq[q+1]=1;
                p2+=1;
            }
                if(qq[q+2]==0){
                qq[q+2]=1;
                p2+=1;
            }
        }
            }
            max1+=2;
        }
        if(box[i]=='*'){
            for(int j=1;j<=max1;j++){
                if(qq[j]!=0){
                    q=j;                
                    if(qq[q*2]==0) {
                    qq[q*2]=1;
                    p2+=1;
                }
            }
        }
        max1*=2;//目前最大的可能数量
        }
    }
    cout<<p1*p2;
}