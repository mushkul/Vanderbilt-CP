c++
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

const int N = 1e5+10;
vector<int> adj[N];
ll ways[N], dp[N];
bool vis[N];
stack<int> st;

void dfs(int x){
	vis[x]=1;
	for(auto i:adj[x]){
		if(!vis[i]){
			dfs(i);
		}
	}

	st.push(x);
}

void solve(){
	int n,m,a,b;
	cin>>n>>m;

	while(m--){
		cin>>a>>b;
		adj[a].push_back(b);
	}

	memset(vis, 0, sizeof vis);

	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
    memset(ways, 0, sizeof ways);
	ways[1]=1;

	while(!st.empty()){
		int node = st.top();
		st.pop();

		for(auto i:adj[node]){
			ways[i] = (ways[i] + ways[node]) % mod;
		}
	}

	cout<<ways[n]<<'\n';
}


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
}