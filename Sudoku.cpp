#include <bits/stdc++.h>
using namespace std;
int t;
int n=4;
string a[5];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while(t--){
        int sum=0;
        //cin>>a1;cin>>a2;cin>>a3;cin>>a4;
        getline(cin,a[1]);getline(cin,a[2]);getline(cin,a[3]);getline(cin,a[4]);
        string aa[5];
        aa[1][1]=a[1][1];aa[2][1]=a[1][2];aa[3][1]=a[1][3];aa[4][1]=a[1][4];
        aa[1][2]=a[2][1];aa[2][2]=a[2][2];aa[3][2]=a[2][3];aa[4][2]=a[2][4];
        aa[1][3]=a[3][1];aa[2][3]=a[3][2];aa[3][3]=a[3][3];aa[4][3]=a[3][4];
        aa[1][4]=a[4][1];aa[2][4]=a[4][2];aa[3][4]=a[4][3];aa[4][4]=a[4][4];
        //cout<<a[1]<<"\n";cout<<a[2]<<"\n";cout<<a[3]<<"\n";cout<<a[4]<<"\n";
        for(int i=1;i<=4;i++){
            if(a[i]=="1 2 3 4"||a[i]=="1 2 4 3"||a[i]=="1 3 2 4"||a[i]=="1 3 4 2"||a[i]=="1 4 2 3"||a[i]=="1 4 3 2"
            ||a[i]=="2 1 3 4"||a[i]=="2 1 4 3"||a[i]=="2 3 4 1"||a[i]=="2 3 1 4"||a[i]=="2 4 1 3"||a[i]=="2 4 3 1"||a[i]=="3 4 1 2"
        ||a[i]=="3 4 2 1"||a[i]=="3 1 2 4"||a[i]=="3 1 4 2"||a[i]=="3 2 1 4"||a[i]=="3 2 4 1"||a[i]=="4 1 2 3"||a[i]=="4 1 3 2"
    ||a[i]=="4 2 1 3"||a[i]=="4 2 3 1"||a[i]=="4 3 2 1"||a[i]=="4 3 1 2") sum++;
            if(aa[i]=="1 2 3 4"||aa[i]=="1 2 4 3"||aa[i]=="1 3 2 4"||aa[i]=="1 3 4 2"||aa[i]=="1 4 2 3"||aa[i]=="1 4 3 2"
            ||aa[i]=="2 1 3 4"||aa[i]=="2 1 4 3"||aa[i]=="2 3 4 1"||aa[i]=="2 3 1 4"||aa[i]=="2 4 1 3"||aa[i]=="2 4 3 1"||aa[i]=="3 4 1 2"
        ||aa[i]=="3 4 2 1"||aa[i]=="3 1 2 4"||aa[i]=="3 1 4 2"||aa[i]=="3 2 1 4"||aa[i]=="3 2 4 1"||aa[i]=="4 1 2 3"||aa[i]=="4 1 3 2"
    ||aa[i]=="4 2 1 3"||aa[i]=="4 2 3 1"||aa[i]=="4 3 2 1"||aa[i]=="4 3 1 2") sum++;
        }
        if(sum==2) cout<<"YES\n";
        else{
            cout<<"NO\n";
        }
    }
}