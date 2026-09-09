#include <bits/stdc++.h>
using namespace std;
//看不出两极化，四极化了
int l=-100,r=100;
vector<double> num;
double a,b,c,d;
int f(double x,double y){
    double fi=a*x*x*x+b*x*x+c*x+d;
    double fi2=a*y*y*y+b*y*y+c*y+d;
    if(fi*fi2>0){
        return 1;
    }if(fi*fi2<0){
        return -1;
    }
    if(fi*fi==0){
        return 0;
    }
}
double f2(double x){
    double fi=a*x*x*x+b*x*x+c*x+d;
    if(fi==0){
        return 1;
    }else{
        return 0;
    }
}
int flag=0;
int main(){
    cin>>a>>b>>c>>d;
    for(int i=1;i<=200;i++){
        if(f(l+i,r)<0) {
            continue;
        }
        if(f(l+i,r)>=0&&flag==0||f(l+i,r)>=0&&flag==2){
            num.push_back(l+i);
            flag=1;
            if(num.size()==3) break;
        }
        if(f(l+i,r)<=0&&flag==1) {
            num.push_back(l+i);
            flag=2;
        }
    }
    for(int i=0;i<3;i++){
        for(double j=0.00;j>=-2.00;j-=0.01){
            if(f2(num[i]+j)){
                num[i]=num[i]+j;
                break;
            }
    }
    }
    for(int i=0;i<=2;i++){
        printf("%.2f ",num[i]);
    }
}