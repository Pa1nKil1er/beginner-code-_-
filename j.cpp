#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,b;
int maxnum=0,maxnumb=0;//论文最大录用数量
int score[20],scoreb[20],sum=0,sumb=0;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m>>k>>b;
        maxnum=0;maxnumb=0;
        //n是论文数量，m是每篇论文的审稿人数
        //k是录用分数阈值，b是最多可选择反驳的论文数
        for(int i=1;i<=n;i++){
            memset(score,0,sizeof(score));
            sum=0;sumb=0;
            for(int j=1;j<=m;j++){
                cin>>score[j];
                scoreb[j]=score[j];
                sum+=score[j];
                if(score[j]>=1) scoreb[j]-=1;
                else scoreb[j]+=1;
                sumb+=scoreb[j];
            }
            if(sum>=k) maxnum+=1;
            if(sumb>=k&&sum<k) maxnumb+=1;
        }
        if(b>maxnumb) maxnum+=maxnumb;
        if(b<=maxnumb) maxnum+=b;
        cout<<maxnum<<"\n";
    }
}