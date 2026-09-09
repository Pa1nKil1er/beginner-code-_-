#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
ll k;
int main(){
    cin>>n>>m>>k;
    if((n*m)%2==0){
        if((n*m)*3/2>k){
            cout<<"NO";
            return 0;
        }
    }
    else if((n*m)%2==1){
        if(((n*m+1)/2+(n*m/2*2))>k){
            cout<<"NO";
            return 0;
        }
    }
    
        cout<<"YES\n";
        ll key=0;
        if((n*m)%2==0){
        if((n*m)/2*3>=k){
            key=k-3*(n*m)/2;
        }
    }
        else if((n*m)%2==1){
        if(((n*m+1)/2+(n*m/2*2))>=k){
            key=k-((n*m+1)/2+(n*m/2*2));
        }
    }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1&&j==1) cout<<key;
                else if(i%2==1&&j%2==1) cout<<1;
                else if(i%2==0&&j%2==0) cout<<1;
                else if(i%2==1&&j%2==0) cout<<2;
                else if(i%2==0&&j%2==1) cout<<2; 
            cout<<" ";
            }
            cout<<"\n";
        }
    
}