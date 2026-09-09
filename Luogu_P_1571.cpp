#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[101000],b[101000];
int e(int x){
    int l=1;int r=m;
    while(l<=r){
        int mid=(l+r)/2;
        if(b[mid]==a[x]) return 1;
        if(b[mid-1]<a[x]&&b[mid+1]>a[x]) return 0;
        if(b[mid]<a[x]) l=mid+1;//如果把l，r放到括号里是不是这里就是递归了喵? 
        else if(b[mid]>a[x]) r=mid-1;
    }
    //遍历完还没有找到，那就说明找不到
    return 0;
}
int main(){

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    sort(b+1,b+m+1);
    for(int i=1;i<=n;i++){
        if(e(i)) cout<<a[i]<<" ";
    }
    return 0;
}
