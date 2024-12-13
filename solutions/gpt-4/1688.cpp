#include<bits/stdc++.h>
using namespace std;

const int MAX_N=200010,MAX_K=18; 
int dep[MAX_N],fa[MAX_N][MAX_K],n,q,x,y;
vector<int> g[MAX_N];

void dfs(int x){
	for(int i=1;i<MAX_K;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		dep[y]=dep[x]+1;
		fa[y][0]=x;
		dfs(y);
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=MAX_K-1;i>=0;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=MAX_K-1;i>=0;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++){
		int x;scanf("%d",&x);
		g[x].push_back(i);
	}
	dfs(1);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y));
	}
	return 0;
}