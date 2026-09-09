#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    int bb;
    while(t--){
        string n;
        cin>>n;
        int num[200010];
        for(int i=0;i<n.size();i++){
            num[i+1]=n[i]-'0';
        }
        int flag=0;
        for(int i=1;i<=n.size();i++){
            if(num[i]>=5){
                num[i-1]+=1;
                num[i]=0;
                bb=i;
                flag=1;
                break;
            }
        }
        if(flag==0){//全都小于4
            for(int i=n.size();i>=1;i--){
            if(num[i]<5){
                num[i]=0;
                bb=i;
                flag=2;
                break;
            }
        }
        }
        if(flag==1){
            for(int i=0;i<=n.size();i++){
                if((i==0&&num[i]!=0||i!=0)&&i<bb)cout<<num[i];
                if(i>=bb) cout<<0;
        }
        }
        if(flag==2){
            for(int i=1;i<=n.size();i++){
                if(i<bb) cout<<num[i];
                if(i>=bb) cout<<0;
        }
        }
        cout<<"\n";
    }
}