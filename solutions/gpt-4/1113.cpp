#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
const int N=2e5+9;
int p[N],c[N],cnt[N],pos[N];
pair<int,int> a[N],b[N];
string s;
int sz;

void count_sort(){
	fill(cnt,cnt,sz+1,0);
	for(int i=0;i<sz;++i) cnt[c[i]+1]++;
	for(int i=1;i<=sz;++i) cnt[i]+=cnt[i-1];
	for(int i=0;i<sz;++i) pos[i]=cnt[c[a[i].second]]++;
	for(int i=0;i<sz;++i) b[i]=a[pos[i]];
	swap(a,b);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin>>s;
	sz=s.size();
	for(int i=0;i<sz;++i) p[i]=s[i],c[i]=0;
	p[sz]=0; c[sz]=-1; sz++;
	tuple<int,int,int> t[N];
	int k=0;
	do{
		for(int i=0;i<sz;++i) a[i]=pair<int,int>(p[i],i);
		count_sort();
		int cc=0;
		for(int i=0;i<sz;++i){
			if(i && a[i].first!=a[i-1].first) cc++;
			c[a[i].second]=cc;
		}
		k++;
		for(int i=0;i<sz;++i) p[a[i].second]=i;
		for(int i=0;i<sz;++i) t[i]=tuple<int,int,int>(c[i],c[(i+(1<<k))%sz],i);
		sort(t,t+sz);
		for(int i=0;i<sz;++i) p[i]=get<2>(t[i]);
	}while(k<=20);
	int l=0;
	for(int i=0;i<sz-1;++i)
		if(p[i+1]<p[l])
			l=i+1;
	s=s+s;
	string r="";
	for(int it=0;it<sz-1;++it)
		r+=s[(l+it)%sz];
	cout<<r<<"\n";
}