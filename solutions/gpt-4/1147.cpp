#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin>>n>>m;
	vector<string> mat(n);
	vector<vector<int>> dp(n,vector<int>(m,0));
	for(int i=0;i<n;++i)
		cin>>mat[i];
	for(int j=0;j<m;++j)
		if(mat[0][j]=='.')
			dp[0][j]=1;
	for(int i=1;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(mat[i][j]=='.')
				dp[i][j]=1+dp[i-1][j];
		}
	}
	int answer=0;
	for(int i=0;i<n;++i)
	{
		vector<int> left(m), right(m);
		stack<int> s;
		for(int j=0;j<m;++j)
		{
			while(!s.empty() and dp[i][s.top()]>dp[i][j])
			{
				right[s.top()]=j;
				s.pop();
			}
			s.push(j);
		}
		while(!s.empty())
		{
			right[s.top()]=m;
			s.pop();
		}
		for(int j=m-1;j>=0;--j)
		{
			while(!s.empty() and dp[i][s.top()]>dp[i][j])
			{
				left[s.top()]=j+1;
				s.pop();
			}
			s.push(j);
		}
		while(!s.empty())
		{
			left[s.top()]=0;
			s.pop();
		}
		for(int j=0;j<m;++j)
		{
			int temp=dp[i][j]*(right[j]-left[j]);
			answer=max(answer,temp);
		}
	}
	cout<<answer<<'\n';
	return 0;
}