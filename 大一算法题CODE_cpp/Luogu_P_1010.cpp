#include <bits/stdc++.h>
using namespace std;
void f(int b){//把每一位指数分解为2进制
            for(int i=5;i>=0;i--){
                int n=pow(2,i);
                if(b>=n){//易错点之不要试图递归
                    if(n==1) cout<<"2(0)";   
                   else if(n==2) cout<<"2";
                    //b-=n;
                    else{cout<<"2(";
                         f(i);cout<<")";
    }
                    b-=n;
                    if(b!=0) cout<<"+";
                }
            }
}    
int num;
int num1[16],num2[10];
int main(){
    cin>>num;
    //我的打算是从左到右输出！
    int p=0;
        while(num>0){
            num1[p]=num%2;
            num/=2;
            p++;
            }
        int p1=1;
        for(int j=0;j<=p;j++){
            if(num1[j]==1){
                num2[p1]=j;
                p1++;
            }
        }
    for(int j=p1-1;j>=1;j--){
        //没想清楚的话很容易在指数上绕弯出错
        if(num2[j]==0) cout<<"2(0)";
        else if(num2[j]==1) cout<<"2";
        else if(num2[j]>=2){cout<<"2(";
        f(num2[j]);
        cout<<")";}
        if(j>1)cout<<"+";
    }
}