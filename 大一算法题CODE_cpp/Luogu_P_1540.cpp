#include <bits/stdc++.h>
using namespace std;
int m,n;
int sum=0;int ans=0;
int word[1010],text[1010];
queue<int> space;//我感觉用队列太麻烦，队列没法看长度也没法取具体
int main(){
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>text[i];
        if(word[text[i]]==0){
            ans++;
            if(sum<=m-1){
                word[text[i]]=1;
                sum++;
                space.push(text[i]);
            }else{
                int w=space.front();
                space.pop();
                word[w]=0;
                word[text[i]]=1;
                space.push(text[i]);
            }
        }
    }
    cout<<ans;
}