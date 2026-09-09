#include <bits/stdc++.h>
using namespace std;
#define mod 1000000000//define不用分号
int n;vector<int> a(5000);//注意：vector需要提前给空间，不然用cin>>a[i]（往已经存在的空间写入）只会出错
long long f=1;
long long ans=0;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ji[5050];//记录阶乘
    ji[0]=1;ji[1]=1;
    for(int i=1;i<=n;i++){
        ji[i]=ji[i-1]*i%mod;
    }

    for(int i=1;i<=n;i++){
        f=1;
        vector<int> b=a;
        sort(b.begin()+1,b.begin()+i+1);//又忘记是左闭右开了
        for(int j=1;j<=i;j++){
            if((b[j]-(j-1))<=0){
                f=0;break;
            }
            f=f*(b[j]-(j-1))%mod;
        }
        f=(f*ji[n-i])%mod;
        ans=(ans+f)%mod;
    }
    cout<<ans;
}