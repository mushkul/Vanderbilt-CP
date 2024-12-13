#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e4+10;
int n,m;
int head[M],nxt[M<<1],to[M<<1],tot;
int deg[M<<1],ga[M<<1];
int wen[M],top,q[M],en[M<<1];
void add(int x,int y) {
	nxt[++tot]=head[x];
	head[x]=tot;
	to[tot]=y;
	deg[y]++;
}
void add1(int x,int y) {
	nxt[++tot]=head[x];
	head[x]=tot;
	to[tot]=y;
	deg[y]++;
}
void T() {
	int b=0,e=1;
	for(int i=2; i<=n; i++)
		if(!deg[i])
			q[e++]=i;
	q[e++]=n;
	do {
		int u=q[++b];
		for(int i=head[u]; i; i=nxt[i]) {
			deg[to[i]]--;
			if(deg[to[i]]==0)
				q[e++]=to[i];
		}
	} while(b+1<e);
}
bool cmp(int a,int b) {
	return ga[a]<ga[b];
}
bool cmp1(int a,int b) {
	return ga[a]>ga[b];
}
int main() {
	scanf("%d%d",&n,&m);
	int _tot=0;
	for(int i=1; i<=m; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		add(y,x);
		en[++_tot]=x;
		en[++_tot]=y;
	} 
	ga[n]=1;
	T();
	for(int i=1; i<=n; i++)
		ga[q[i]]=max(ga[q[i]],ga[wen[top]]+1);
	sort(en+1,en+1+_tot,cmp1);
	for(int i=1; i<=m; i++)
		if(ga[en[i*2-1]]&&ga[en[i*2]]<ga[en[i*2-1]])
			ga[en[i*2]]=ga[en[i*2-1]],wen[++top]=en[i*2];
	sort(wen+1,wen+1+top,cmp);
	int ma=ga[1];
	printf("%d\n",ma);
	for(int i=1; i<=ma; i++,puts(""))
		for(int la=1; top; top--)
			if(ga[wen[top]]==la)
				printf("%d ",wen[top]);
			else
				break;
	return 0;
}