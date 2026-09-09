#include <bits/stdc++.h>
using namespace std;
#define ll long long
int len1,len2;
string s;
ll mo,son;//分母，分子
ll a=-1,b=-1,c=-1;
ll ten[50];
ll gcd(ll a,ll b){
    ll r;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;        
    }
    if(b==0) return a;
}
int main(){
    cin>>s;
    ten[0]=1;
    for(int i=1;i<=13;i++){
        ten[i]=ten[i-1]*10;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='.') c=i;
        else if(s[i]=='(') a=i;
        else if(s[i]==')') b=i;
    }
    string s1,s2,s3;
    for(int i=0;i<s.size();i++){
        if(i!=a&&i!=b&&i!=c){
            s1+=s[i];//s1为没有任何符号的一串
        }
        if(a!=-1&&i>a&&i<b){
            s2+=s[i];//循环节
        }
        if(i<a&&i!=c){
            s3+=s[i];//除去循环节的部分
        }
    }
    len1=a-c-1;//小数非循环部分长度
    len2=s2.size();//循环节长度
    ll num1=0,num2=0;
    num1=stoi(s1);//整个数看作一个大整数
    if(!s3.empty()) num2=stoi(s3);//唯独去除循环节  //存在()才拼接

    //只有存在循环节的情况下才用减法公式
    if(a!=-1){
        son=num1-num2;
        mo=ten[len1+len2]-ten[len1];
    }else{
        son=num1;
        if(c==-1) mo=1;//整数
        else{
            mo=ten[s1.size()-c];//有限小数
        }
    }
    int g=gcd(mo,son);
    mo/=g;
    son/=g;
    cout<<son;
    if(mo!=1) cout<<"/"<<mo;
}