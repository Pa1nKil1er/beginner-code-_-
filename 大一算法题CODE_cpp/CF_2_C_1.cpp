#include <bits/stdc++.h>
using namespace std;
int ans[200001];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T;
	long long n,i,p;
	for(cin>>T;T>0;T--)
	{
		cin>>n;
		if(n%2==1)
		{
			cout<<n-1<<' ';
			for(i=2;i<=n-1;i++)cout<<(i^1)<<' ';
			cout<<"1\n";
			continue;
		}
		for(i=0;n>>i&1^1;i++);
		p=i;
		if(n==(1<<p))
		{
			cout<<"-1\n";
			continue;
		}
		ans[n]=1;
		ans[1]=n;
		for(i=2;i<n;i++)ans[i]=i^1;
		swap(ans[1],ans[1<<p]);
		for(i=1;i<=n;i++)cout<<ans[i]<<' ';
		cout<<'\n';
	}
	return 0;
}