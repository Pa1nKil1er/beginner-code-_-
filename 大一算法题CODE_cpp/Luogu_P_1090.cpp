#include <bits/stdc++.h>
using namespace std;
int n;int a[10010];
int heap[10010];//堆,本题要实现的是小根堆
int len;//堆尾
//void swap(int a,int b){
//    int c=a;a=b;b=c;
//}
void put(int a){//把数放进堆里
    heap[len+1]=a;
    int i=len+1;
    while(i>1&&a<heap[(i)/2]){
    //while(i>1&&heap[i]<heap[(i)/2]){
        swap(heap[i],heap[i/2]);
        i=i/2;
    }
    len++;
}
//...............................................
int get( ){//取出根
    if(len==0) return 0;//
    int ans=heap[1];
    int a=heap[len];int i=1;
    heap[1]=heap[len];len--;
    //while(i*2<=len&&(a>heap[i*2]||a>heap[i*2+1])){
    while(i*2<=len){
        //if(a>heap[i*2]) {swap(heap[2*i],heap[i]);i*=2;}
        //else {swap(heap[2*i+1],heap[i]);i=i*2+1;}
        //if(heap[2*i]>heap[2*i+1]){
        //    swap(heap[2*i],heap[i]);i*=2;
        //}else{
        //    swap(heap[2*i+1],heap[i]);i=i*2+1;
        //}
        int minn=i*2;
        if(i*2+1 <= len && heap[i*2+1] < heap[minn]){
            minn=i*2+1;//右孩子存在且更小，更新最小子节点
        }

        if(heap[i]>heap[minn]){
            swap(heap[i],heap[minn]);
            i=minn;
        }else{
            break;
        }
    }
    return ans;
}
int sum=0;
int main(){
    cin>>n;len=0;
    for(int i=1;i<=n;i++){
        int ai;cin>>ai;put(ai);
    }
    //while(len>0){
    while(len>1){
        int g1=get();
        int g2=get();
        sum+=(g1+g2);
        put(g1+g2); 
    }
    cout<<sum;
}