#include <bits/stdc++.h>
using namespace std;
int m,n;
//并查集中的查
int fa[5010];
int find(int a){
    int x=a;
    while(fa[x]!=x){
        x=find(fa[x]);
    }
    fa[a]=x;
    return x;
}
struct aa{
    int x,y,v;
} eage[200010];
//bool cmp(struct aa eage[a],struct aa eage[b]){
bool cmp(aa a,aa b){
    return a.v<b.v;
}
int main(){
    cin>>n>>m;
    //k
    //用贪心思想优先选取权值小的边，跳过会构成环的边，
    //直到边的数目为n-1（n为点）
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int x,y,v;
        cin>>x>>y>>v;
        eage[i].x=x;
        eage[i].y=y;
        eage[i].v=v;
    }
    sort(eage+1,eage+1+m,cmp);
    int sum=0;int ans=0;
    for(int i=1;i<=m;i++){
        if(sum==n-1) break;
        int f1,f2;
        f1=find(eage[i].x);  f2=find(eage[i].y);
        if(f1==f2) continue;
        else {
            //fa[eage[i].x]=fa[eage[i].y];
            fa[f1]=f2;
            sum++;
            ans+=eage[i].v;
        }
    }
    if(sum==n-1) cout<<ans<<"\n";
}