#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, id = 1, id_com[100009], low[100009], num[100009], Child[100009];
vector<int> a[100009], f;
bool fre[100009];

void visit(int u)
{
    low[u] = num[u] = ++id;
    f.push_back(u);
    for(int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i];
        if (id_com[v]) continue;
        if (num[v]) low[u] = min(low[u], num[v]);
        else
        {
            visit(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (num[u] == low[u])
    {
        int v;
        do
        {
            v = f.back(); f.pop_back();
            id_com[v] = u;
        }
        while (v != u);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        if (!num[i]) visit(i);
    for(int u=1;u<=n;u++)
        for(int i=0;i<a[u].size();i++)
        {
            int v=a[u][i];
            if (id_com[u] != id_com[v])
            {
                Child[id_com[v]] = true;
            }
        }
    int Count = 0;
    for(int i = 1; i <= n; i++)
        if (id_com[i] == i && !Child[i]) Count++;
    cout << Count << endl;
    for(int i = 1; i <= n; i++) cout << id_com[i] << " ";
    return 0;
}