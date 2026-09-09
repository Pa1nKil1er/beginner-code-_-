#include <bits/stdc++.h>
using namespace std;
int t,m;
int bag[110][1010];
int value[110];int ti[110];
int maxy=0;
int main(){
    cin>>t>>m;
    for(int i=1;i<=m;i++){//t为时间，m为药的数量
        cin>>ti[i];
        cin>>value[i];
    }
    /*for(int i=m;i>=1;i--){
        if(ti[i]>t) continue;
        else{
            t-=ti[i];
            //bag[t][i]=max({bag[t-ti[i]][i-1]+value[i],bag[t][i-1]});
            bag[t][i]=max({bag[t+ti[i]][i+1]+value[i],bag[t+ti[i]][i+1]});
            //没有maxy是不是就不行
            if(maxy<bag[t][i]) maxy=bag[t][i];
            //t-=ti[i];移到上面
        }
        //if(i==1) cout<<bag[t][i];
    }
    cout<<maxy;*/
    for(int i=1;i<=m;i++){
        for(int j=1;j<=t;j++){
            bag[i][j]=bag[i-1][j];
            if(j<ti[i]) continue;
            else{
                bag[i][j]=max({bag[i-1][j-ti[i]]+value[i],bag[i-1][j]});
                if(maxy<bag[i][j]) maxy=bag[i][j];
            }
        }
    }
    cout<<maxy;
    return 0;
}