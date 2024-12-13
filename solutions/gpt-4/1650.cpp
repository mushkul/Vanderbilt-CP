c++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int mod = 1e9+7;
const int N = 2e5+5;
ll a[N],pref[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i-1] ^ a[i];
    }
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        cout << (pref[r] ^ pref[l-1]) << "\n";
    }
    return 0;
}