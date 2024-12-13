#include<bits/stdc++.h>
using namespace std;

#define sqr(x) ((x) * (x))
typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 2e5+5;
pll a[MAXN];
ll dist[MAXN];

inline ll getDist(pll a, pll b)
{
    return sqr(a.first-b.first) + sqr(a.second-b.second);
}

struct cmpX
{
    inline bool operator() (const pll &a, const pll &b)
    {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    }
};

struct cmpY
{
    inline bool operator() (const pll &a, const pll &b)
    {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    }
};

set<pll, cmpY> box;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a+n, cmpX());
    dist[0] = LONG_LONG_MAX;
    box.insert(a[0]);
    int left = 0;
    for (int i = 1; i < n; i++)
    {
        while (left < i && sqr(a[i].first - a[left].first) > dist[i-1])
            box.erase(a[left++]);
        for (auto it = box.lower_bound(pll(a[i].first-dist[i-1], a[i].second-dist[i-1]));
                it != box.end() && sqr(a[i].second - it->second) <= dist[i-1];
                it++)
            dist[i] = min(dist[i-1], getDist(a[i], *it));
        box.insert(a[i]);
    }
    cout << dist[n-1] << "\n";
    return 0;
}