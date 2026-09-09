#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while(t--){
        string s;
        vector<int> a(200010);int b[400010];
        memset(b,0,sizeof(b));
        cin>>n>>m>>k;
        int sum=n;//机器人初始数量
        for(int i=1;i<=n;i++){
            cin>>a[i];//第i个机器人的位置
        }for(int i=1;i<=m;i++){
            //防止re，尖刺位置加200000
            int place;
            cin>>place;
            b[place+200000]=1;;
        }
        
        cin>>s;
        for(int j=0;j<k;j++){
            for(int i=1;i<=n;i++){
                if(s[j]=='L'){
                    if(a[i]==200001) continue;
                    else a[i]-=1;
                    if(b[a[i]+200000]){
                        sum-=1;
                        a[i]=200001;
                    } 
                }
                if(s[j]=='R'){
                    if(a[i]==200001) continue;
                    else a[i]+=1;
                    if(b[a[i]+200000]){
                        sum-=1;
                        a[i]=200001;
                    } 
                }
        }
        cout<<sum;
        if(j!=k-1) cout<<" ";
        }
        cout<<"\n";
    }
}