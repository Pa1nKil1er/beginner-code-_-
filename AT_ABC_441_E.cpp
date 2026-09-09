#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
string s;vector<int> a;
int ss[500010];
int main(){
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='A'){
            ss[i]=1;a.push_back(i);
        }
        if(s[i]='B') ss[i]=-1;
        ss[i]=ss[i-1]+ss[i];
    }
    for(int i=0;i<a.size();i++){
        for(int j=a[i]+1;j<n;j++){
            int sum=ss[j]-ss[a[i]]+1;//a的数量
            if(sum>0) ans++;
        }
    }
    cout<<ans;
}