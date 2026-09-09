#include <bits/stdc++.h>
#include <algorithm> 
using namespace std;
int n,M,T;//n为愿望总数，M为钱数，T为时间(都是用来消耗的)
//相比最基础的01背包，多了一维钱数要考虑
//三维数组太占据空间了，用结构体怎么样？
//依旧以物体为主轴，将时间和钱数作为二维数组存在结构体里
struct power{
    int dp[201][201];//m 与 t
}po[110];
struct wish{
    int money;
    int time;
}w[110];
int main(){
    cin>>n>>M>>T;
    for(int i=1;i<=n;i++){
        cin>>w[i].money;
        cin>>w[i].time;
    }
    for(int i=1;i<=n;i++){//用三重循环有tle的风险,或许我该思考一下滚动数组
        //我草居然过了
        po[i]=po[i-1];
        for(int m=w[i].money;m<=M;m++){
            for(int t=w[i].time;t<=T;t++){
                //这两种好像没区别
        //for(int m=M;m>=w[i].money;m--){
            //for(int t=T;t>=w[i].time;t--){//
                po[i].dp[m][t]=max(po[i].dp[m][t] , po[i-1].dp[m-w[i].money][t-w[i].time]+1);
            }
        }
    }
    cout<<po[n].dp[M][T];
}