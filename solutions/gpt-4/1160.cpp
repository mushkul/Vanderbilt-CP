#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define int long long
#define vi vector<int>
#define ii pair<int,int>

const int N=2e5+5;
vector<ii> a;
vi cyc(N),s(N),vis(N),par(N);
int32_t main()
{
    IOS;
    int n, q;
    cin >> n >> q;
    a.pb({0,0});
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.pb({x,i});
        s[i]=x;
        par[i]=x;
    }
    vi dis(N,1e9);
    while(q--) {
        int x,y;
        cin >> x >> y;
        for(int i = 1; i <= n; i++) {
            par[i] = s[i];
            vis[i] = 0;
            dis[i] = 1e9;
        }
        dis[x] = 0;
        vi ans;
        ans.pb(x);
        while(!ans.empty()){
            int node = ans.back();
            ans.pop_back();
            if(vis[node] == 2)
                continue;
            if(vis[par[node]] == 0)
                ans.pb(par[node]);
            vis[node]++;
            if(vis[node] == 2)
                dis[par[node]] = min(dis[par[node]],dis[node]+1);
            else if(vis[node] == 1)
                dis[par[node]] = min(dis[par[node]],dis[node]);
        }
        if(dis[y] == 1e9)
            cout << -1 << endl;
        else
            cout << dis[y] << endl;
    }

    return 0;
}