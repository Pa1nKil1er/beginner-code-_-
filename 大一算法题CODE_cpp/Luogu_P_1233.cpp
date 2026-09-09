#include <bits/stdc++.h>
using namespace std;
//依旧是求最长不下降子数组(倒着看一样嘛)
//但关键是要考虑两个维度，同时使其尽可能少
//不过答案求的是时间而不是具体排列，而且5000的n似乎不算大
//（找出最少能分成几个最长不下降子数组？）
int n;
int l,w;
vector<vector<int>> sti;
//怎么实现这个二维让我有点苦恼，结构体不行，二维数组也不太行（想用sort
//试试用冒泡实现二维数组？
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l>>w;
        sti.push_back({l,w});
        
    }
    sort(sti.begin(),sti.end());
    /*for (auto& row : sti) {
        for (int num : row) cout << num << " ";
        cout << endl;
    }*/
   int t=1;
    for(int i=0;i<=n;i++){
        if(sti[i][2]<=sti[i+1][2])
    }//不会了。。
}

