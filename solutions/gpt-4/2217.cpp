#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 5;
int a[maxn], p[maxn], r[maxn];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;   
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[a[i]] = i;
    }
    r[n + 1] = n + 1;
    for(int i = n; i >= 1; i--)
    {
        r[i] = min(r[i + 1], p[i]);
    }
    int res = 1;
    for(int i = 2; i <= n + 1; i++)
    {
        if(r[i - 1] < r[i]) res++;
    }
    while(m--)
    {
        int x, y; cin >> x >> y;
        vector<int> v = {a[x], a[y]};
        if(x > y) swap(x, y);
        for(int z : v)
        {
            if(z != 1 && p[z] < p[z - 1]) res--;
            if(z != n && p[z] > p[z + 1]) res--;
            swap(p[z], p[a[x] == z ? a[y] : a[x]]);
            if(z != 1 && p[z] < p[z - 1]) res++;
            if(z != n && p[z] > p[z + 1]) res++;
        }
        swap(a[x], a[y]);
        cout << res << "\n";
    }
    return 0;
}