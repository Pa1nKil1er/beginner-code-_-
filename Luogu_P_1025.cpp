#include <bits/stdc++.h>
using namespace std;
int n,k;
inline int dfs(int num,int part,int now)//分别表示剩余待分的数，分的机会数和现在要选出的数。
{
  if(part==1)return 1;//如分析2。
  int sum=0;//sum一定要开在函数中，否则会漏选(看后面的代码就懂了)
  for(int i=now;i<=num/part;i++)//剪枝：不需要枚举到num，否则既有可能重复计算，又会加大运算量(dfs你懂的)。
    sum+=dfs(num-i,part-1,i);//再搜索剩余待分数num-i，分的机会数少1，选择分出now，将所有情况统计于sum。
  return sum;
}
int main()
{
  cin>>n>>k;
  printf("%d",dfs(n,k,1));//从n,k选一种开始搜。
  return 0;
}