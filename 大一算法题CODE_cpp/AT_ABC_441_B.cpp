#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,t;
int ss[130];int tt[130];
int q;
int main(){
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++){
        ss[s[i]]=1;//s有的
    }
    cin>>t;
    for(int i=0;i<m;i++){
        tt[t[i]]=1;//t有的
    }
    cin>>q;
    while(q--){
        string w;
        int sum=0;
        cin>>w;
        for(int i=0;i<w.size();i++){
            if(tt[w[i]]==1&&ss[w[i]]==0){
                cout<<"Aoki\n";break;
            }
            else if(tt[w[i]]==0&&ss[w[i]]==1){
                cout<<"Takahashi\n";break;
            }
            else if(tt[w[i]]==1&&ss[w[i]]==1){
                sum++;
            }
            if(sum==w.size()){
                cout<<"Unknown\n";
            }
        }
    }
}