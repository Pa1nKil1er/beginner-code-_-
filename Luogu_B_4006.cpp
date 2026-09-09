#include<bits/stdc++.h>
using namespace std;
int num,k;
int l,r;
int max_=0;
vector<int> a;
int n[1010];
int f(int l,int r){
    if(l==a.size()-1) return 0;
    if(a[r]-a[l]>k){
        //if(max_<kk) max_=kk;
        f(l+1,l+2);
    }
    else if(a[r]-a[l]<=k){
        int kk=0;
        for(int i=l;i<=r;i++){
        kk+=a[i]*n[a[i]];
    }
        if(max_<kk) max_=kk;
        f(l,r+1);
    }
}
int main(){
    cin>>num>>k;
    int number;
    for(int i=1;i<=num;i++){
        cin>>number;
        n[number]+=1;
        if(n[number]==1){
            a.push_back(number);
        }
    }
    sort(a.begin(),a.end());
    f(0,1);
    cout<<max_;
}