#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k, ans = 0, j = 0;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        while(j < m && b[j] < a[i] - k) j++;
        if(j < m && b[j] <= a[i] + k)
        {
            ans++;
            j++;
        }
    }
    cout<< ans;
    return 0;
}