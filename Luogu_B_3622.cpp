#include <bits/stdc++.h>
using namespace std;
char r[20];
int n,n2,sum=0;
void print(){
    sum=0;
    for(int q=1;q<=n2;q++) {
        cout<<r[q]; 
        
}
    cout<<"\n";
    return;
}
void dfs(int pos) {
    if (pos > n) {  // 所有位置处理完毕，输出
        print();
        return;
    }
    // 1. 当前位置放'N'，递归处理下一位
    r[pos] = 'N';
    dfs(pos + 1);
    // 2. 当前位置放'Y'，递归处理下一位（回溯逻辑隐含，因为会被下一次赋值覆盖）
    r[pos] = 'Y';
    dfs(pos + 1);
}
int main(){
    cin>>n;
    n2=n;
    //while(n2--) cout<<"N";
    memset(r,'N',sizeof(r));
    dfs(1);
}