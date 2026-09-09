#include<bits/stdc++.h>
using namespace std;
//和我昨天写的情侣牵手很像
int a[210];//与map一样，记录人——位置
int b[110];//每个位置站着谁，总体位置
int main(){
    //数据量小
    int n;int sum=0;
    cin>>n;
    n*=2;
    for(int i=1;i<=n;i++){
        int co;
        cin>>co;
        b[i]=co;
        if(a[co]!=0){//前面已经出现过
            co+=100;//将一对情侣一个放在1-100，另一个放在101-200
            a[co]=i;
        }else{ a[co]=i; }
    }
    //cout<<"102的位置="<<a[102]<<"\n";   
    //cout<<"2的位置="<<a[2]<<"\n";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
    for(int i=1;i<=n;i+=2){
        int x=b[i];//拿出目前最前面的情侣
        int p1=a[x];int p2=a[x+100];//拿出这对情侣目前的位置
        //cout<<"p1="<<p1<<" ,p2="<<p2<<"\n";
        sum+=abs(p2-p1)-1;
        a[x+100]=i+1;
        //后面的人位置都加1
        for(int j=p2;j>=i+2;j--){
            a[b[j-1]]+=1;
            swap(b[j],b[j-1]);
        }
    }
    cout<<sum;
}

