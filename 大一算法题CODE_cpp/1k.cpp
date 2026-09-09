#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
int main(){
    cin>>n;
    cout<<n%2;
}
/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,sum=0;
map<ll,ll> mp;
vector<int> ss;
int main(){
    cin>>n;
    for(ll a=1;a<=n;a++){
        for(ll d=1;d<=n;d++){
            mp[a*d]+=1;
            if(mp[a*d]==1) ss.push_back(a*d);
        }
    }
    for(int i=0;i<=ss.size()-1;i++){
        sum+=mp[ss[i]]*mp[ss[i]];
    }
    cout<<sum;
    sum=sum%2;
    cout<<sum;
}还是超时
*/