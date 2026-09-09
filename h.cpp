#include <bits/stdc++.h>
using namespace std;
string s,t,s1,s2;
int n,m;
int flag=0;
int len=0;
int p=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    len=m/2;
    cin>>s;
    cin>>t;
    s1=t.substr(0,len);
    s2=t.substr(len,len);
    size_t p=0;
    if(s==t){
        cout<<"Yes";
        flag=1;
        goto end;
    }
    if(m%2!=0){
        goto end;
    }
    while((p=s.find(s1,p))!=string::npos){
        if(s.find(s2,p+len)!=string::npos){
            flag=1;
            cout<<"Yes";
            goto end;
        }
        p++;
    }
    end:
    if(flag==0) cout<<"No";
}