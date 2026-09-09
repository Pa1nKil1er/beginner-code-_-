#include<bits/stdc++.h>
using namespace std;
int t;int num[25];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(int i=1;i<=21;i++){
        num[i]=i*i;
    }
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cout<<num[i];
            if(i!=n) cout<<" ";
        }
        cout<<"\n";
    }
}