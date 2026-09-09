#include<bits/stdc++.h>
using namespace std;
int t,n,m,h;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while(t--){
        vector<int> a;int b[200010];int c[200010];
        //memset(a,0,sizeof(0));不能用吗原来
        int flag=0;
        cin>>n>>m>>h;
        for(int i=1;i<=n;i++){
            int number;
            cin>>number;
            a.push_back(number);
        }
        vector<int> aa;
        aa=a;
        for(int i=1;i<=m;i++){
            cin>>b[i]>>c[i];
            aa[b[i]-1]+=c[i];
            if(aa[b[i]-1]>h){
                aa=a;
            }
        }
        for(int i=0;i<a.size();i++){
            cout<<aa[i];
            if(i<a.size()) cout<<" ";
        }
        cout<<"\n";
    }
}