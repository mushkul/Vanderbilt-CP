#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define INF 1e15
#define MAX 505
#define FastIO ios_base :: sync_with_stdio(false);cin.tie(NULL);

ll n, m, q , dis[MAX][MAX];

int main()
{
    FastIO
    cin>>n>>m>>q;
    for(ll i=1; i<=n; i++)
    {
        for(ll j=1; j<=n; j++)
        {
            if(i == j) 
                dis[i][j] = 0;
            else
                dis[i][j] = INF;
        }
    }
    for(ll i=1; i<=m; i++)
    {
        ll a, b ,c;
        cin>>a>>b>>c;
        dis[a][b] = min(dis[a][b],c);
        dis[b][a] = min(dis[b][a],c);
    }
    for(ll k=1; k<=n; k++)
    {
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=n; j++)
            {
                if(dis[i][k] < INF && dis[k][j] < INF)
                    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--)
    {
        ll u, v;
        cin>>u>>v;
        if(dis[u][v] == INF)
            cout<<"-1";
        else
            cout<<dis[u][v];
        cout<<endl;
    }
    return 0;
}