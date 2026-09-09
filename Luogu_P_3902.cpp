#include <bits/stdc++.h>
using namespace std;
int n,a[100100];
int dp[100100];
int ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ans=1;
    /*
    for(int i=1;i<=n;i++){//遍历n个元素，
        dp[i]=1;//初始化为1（最短的不下降序列长度为1）
        for(int j=1;j<i;j++){
        //每个元素都要和前面（i-1）个元素比较，从而保证不下降
            if(a[i]>a[j]) dp[i]=max({dp[i],dp[j]+1});
            ans=max(ans,dp[i]);
        }
    }
    (╯▔皿▔)╯悲报：n²的复杂度tle了
    */
    int len=1;//len即为长度,dp[len]即为该长度下最大的数为
                //当然这个最大的数是所有可能下最小的数(...)
    dp[1]=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]>dp[len]){
            len++;
            dp[len]=a[i];
            //ans=max(ans,len);
        }
        else{//那么这个a[i]有可能成为更小的max数
            //for(int j=len-1;j>=1;j--){
            for(int j=1;j<=len;j++){
                if(a[i]<dp[j]){//找到第一个大于a[i]的dp，更新dp
                    //j++;这里不需要++，因为实质是取代了原本那个最大值
                    dp[j]=a[i];
                    //ans=max(ans,j);
                    break;
                }
            }
        }
    }
    ans=n-len;
    cout<<ans;
}