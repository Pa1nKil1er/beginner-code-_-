#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t;
int a[20010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while(t--){

        int flag=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            int a=2*i-1;int b=a+1;
            cout<<"? "<<a<<" "<<b<<"\n";
            //cout<<flush;
            cout.flush();
            int ans;cin>>ans;
            if(ans==1){
            cout<<"! "<<a<<"\n";
            //cout<<flush;
            cout.flush();
            flag=1;
            break;
            }
        }
        /*
        if(flag==0){
                cout<<"? "<<1<<" "<<3<<"\n";
            cout.flush();
            int ans;cin>>ans;
            if(ans==1){
                cout<<"! 1\n";
                cout.flush();
            }else{
                cout<<"! 2\n";
                cout.flush();
            }
            //cout.flush();
            //cout<<"\n";
            cout.flush();
        }
        */
        if(flag==0){
            cout<<"? 1 2\n";
            cout.flush();
            int ans;cin>>ans;
                cout<<"! 1\n";
                cout.flush();
        }
    }
    }