#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull n,k;
int flag=0;
void glay(__int128_t n,__uint128_t k){
    if(n==0) return;
    if(flag==0){//对k+1的坚守/
        k+=1;
        flag=1;
    }
    __uint128_t num;
    num=(__uint128_t(1)<<n);
    if(k<=num/2){
        cout<<0;
    }
    else if(k>num/2){
        cout<<1;
        //处理k
        //k=k-num/2;并非如此，而是应该体现逆序
        k=num-k+1;
    }
    n-=1;
    glay(n,k);
}
int main(){
    cin>>n>>k;
    //k+=1;
    //一直卡的原因就在这里
    //18446744073709551615刚好是2^64,再+1就超过ull的范围
    //就爆了
    glay(n,k);
    return 0;
}