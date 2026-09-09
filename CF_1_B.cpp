#include<bits/stdc++.h>
using namespace std;
int t,n;
int max_=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while(t--){
        max_=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int num;cin>>num;
            if(num>max_) max_=num;
        }
        int ans=n*max_;
        cout<<ans<<"\n";
    }
}