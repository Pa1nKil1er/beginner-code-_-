#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[3010];
int num[3010];
int ans1=0,ans2=0;
int min_=0;
int min2=0;//正的
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while(t--){
        memset(num,0,sizeof(num));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i==1){
                min_=a[1];
                min2=1;
            }
            if(a[i]<min_) min_=a[i];
            if(a[i]<min2&&a[i]>=0) min2=a[i];
        }
        int delete_=min_;
        for(int i=1;i<=n;i++){
            int aa=a[i];
            aa-=delete_;
            num[aa]=1;
        }
        for(int i=0;i<=3000;i++){
            if(num[i]==0){
                ans1=i;
                break;
            }
        }
        if(min_<0){
        memset(num,0,sizeof(num));
        int delete_=min2;
        for(int i=1;i<=n;i++){
            a[i]-=delete_;
            num[a[i]]=1;
        }
        for(int i=0;i<=3000;i++){
            if(num[i]==0){
                ans2=i;
                break;
            }
        }
        }
        int ans=max({ans1,ans2});
        cout<<ans;
        cout<<"\n";
    }
}