#include <bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
    cin>>a>>b>>c;
    if(c==a+b) cout<<"YES";
    else if(c==abs(a-b)) cout<<"YES";
    else if(c==a*b) cout<<"YES";
    else if(c==a/b&&a%b==0||c==b/a&&b%a==0) cout<<"YES";
    else{
        cout<<"NO";
    }
}