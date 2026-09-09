#include <bits/stdc++.h>
using namespace std;
int sum=0,count1=0;
int n,k,num[10000000],a[10000000];
bool test(int num){
    if(num==1) return false;
    for(int i=2;i*i<=num;i++){
        if(num%i==0) return false;
    }
    return true;
}
//不用int 用void
void f(int range,int k,int point){//point是类似指针，表示选了某个数（下标为point）
    if(k==0){
        if(test(sum)==true){
            count1++;
        }
        return;//当k到0的时候就return
        //else f(range,k,1);
    }
    //递归出口
    if(k!=0){
        for(int i=point;i<=range-k+1;i++){
            if(num[i]!=0){//即没有选过该数
                sum+=num[i];
                num[i]=0;
                f(range,k-1,i+1);
                num[i]=a[i];//还原
                sum -= a[i];//漏掉的关键回溯******************

            }
            
        }
    }
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        a[i]=num[i];//a[i]是用来还原现场滴
    }
    f(n,k,1);
    cout<<count1;
    return 0;
}