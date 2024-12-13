#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define F first
#define S second

const int N=2e5+5;

int n,p[N],pos[N];
vector<pii> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    for(int i=1;i<=n;i++){cin>>p[i]; pos[p[i]]=i;}
    for(int i=1;i<=n;)
    {
        if(pos[i]==i){i++; continue;}
        int end=pos[i];
        while(end>i)
        {
            ans.pb(mp(end,pos[end]));
            swap(p[pos[end]],p[end]);
            swap(pos[p[end]],pos[p[pos[end]]);
            end--;
        }
        i++;
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)cout<<ans[i].F<<' '<<ans[i].S<<endl;
}