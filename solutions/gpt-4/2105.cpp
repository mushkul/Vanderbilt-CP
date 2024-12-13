#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
const int alph=26, N=1e5+1,mod=1e9+7,MAX=1e9+7;
int p[N],cnt[N],pos[N];
pair<long long,int> h[N];
vector<int> who[N],g[N];
bitset<N> bs;
string s;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>s; int n=s.size();
  int pw[n+1]={0};
	pw[0]=1; 
	for(int i=1;i<=n;i++) pw[i]=(pw[i-1]*alph)%mod;
	for(int i=1;i<=n;i++) h[i]={ (h[i-1].first*alph+s[i-1])%mod , i}; 
	sort(h+1,h+n+1);
	ll ans=n;
	for(int i=1;i<n;i++)
	{
		int j=n-(h[i].second);
		int k=n-(h[i+1].second);
		int l=min(j,k);
		ll p=h[i].first;
		int r=i;
		while(r+1<=n && h[r+1].first==p)
		{
		   r++;
		   j=n-(h[r].second);
		   l=min(l,j);   
		}
		for(int j=i+1;j<=r+1;j++)
        	{
          	    p*=(alph);
           	    if(p>=mod) p-=mod;
          	    p+=(s[h[j-1].second+l]);
           	    if(p>=mod) p-=mod;
   	    	}
		if(l==j || l==k) 
		{
     		l--;	
			if(l>=0) ans-=l;
		}
		else
		{
         ans-=(l);
			break;
		}
        i=r;
	}
	cout<<ans<<endl;
	return 0;
}