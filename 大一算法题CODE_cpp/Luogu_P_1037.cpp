#include <bits/stdc++.h>
using namespace std;
int n,k,a[20],b[20];
vector<int> num;
int num2[35];//用于计算每个数对应的规则数
int ans=1;
int main(){
    cin>>n>>k;
    //拆分n的各位
    while(n>=1){
        int i=n%10;
        num.push_back(i);
        n/=10;
    }
    for(int i=1;i<=k;i++){
        cin>>a[i]>>b[i];
        for(int j=0;j<=sizeof(num)-1;j++){
            if(a[i]==num[j]){
                num2[num[j]]+=1;
            }
        }
    }
    for(int i=1;i<=35;i++){
        if(num2[i]!=0) ans*=num2[i]+1;
    }
    cout<<ans;
}