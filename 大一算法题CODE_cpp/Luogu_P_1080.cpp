#include <bits/stdc++.h>
using namespace std;
int n,a,b;
int a[1010][3];
int b[1010];
cmp(){
    int p1=
}
int main(){
    cin>>n;
    cin>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>a[i][1];
        cin>>a[i][2];
        b[i]=a[i][1]*a[i][2];
    }
    sort(a+1,a+n+1,cmp);
}