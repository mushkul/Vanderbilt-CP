#include<bits/stdc++.h>
using namespace std;
vector<int> vv[1005], v[1005], hd[1005], th[1005];
bool f;
void dfs(int p, int d){
	if(!f) return;
	v[d].push_back(vv[p].size() - 2);
	for(int i=0;i<vv[p].size();i++) if(vv[p][i]!=p) dfs(vv[p][i], d + 1);
}
void dfs2(int p, int d){
	if(!f) return;
	hd[d].push_back(v[p].size() - 2);
	for(int i=0;i<v[p].size();i++) if(v[p][i]!=p) dfs2(v[p][i], d + 1);
}
int main(){
	int n, m, a, b;
	cin>>n;
	while(n--){
		cin>>m;
		for(int i=1;i<=m+2;i++) {
			vv[i].clear();
			v[i].clear();
			hd[i].clear();
			th[i].clear();
		}
		for(int i=1;i<=m-1;i++) scanf("%d %d", &a, &b), vv[a].push_back(b), vv[b].push_back(a);
		for(int i=1;i<=m-1;i++) scanf("%d %d", &a, &b), v[a].push_back(b), v[b].push_back(a);
		f = 1;
		dfs(1, 0);
		dfs2(1, 0);
		for(int i=0;i<=m+1;i++){
			if(f){
				sort(v[i].begin(), v[i].end());
				sort(hd[i].begin(), hd[i].end());
				if(v[i]!=hd[i]) f = 0;
			}
		}
		if(f) printf("YES\n");
		else printf("NO\n");
	}
}