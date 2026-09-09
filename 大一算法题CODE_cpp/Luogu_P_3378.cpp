#include <bits/stdc++.h>
using namespace std;
int heap[200010];//小根堆
int len=0;
void put(int a){
    len++;
    heap[len]=a;
    int i=len;
    while(heap[i]>heap[i/2]) swap(heap[i],heap[i/2]);
}
int get(){
    int ans=heap[1];heap[1]=heap[len];
    len--;int i=1;
    while(heap[i]>heap[2*i])
}