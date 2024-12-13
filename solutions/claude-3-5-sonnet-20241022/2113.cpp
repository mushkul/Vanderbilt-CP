#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<ll> res(n+m-1);
    for(int i = 0; i < n+m-1; i++) {
        ll sum = 0;
        int start = max(0, i-m+1);
        int end = min(i+1, n);
        int b_idx = m-1-(i-start);
        
        for(int j = start; j < end; j++) {
            sum += (ll)a[j] * b[b_idx++];
        }
        res[i] = sum;
    }
    
    for(int i = 0; i < n+m-1; i++) {
        cout << res[i];
        if(i < n+m-2) cout << " ";
    }
    
    return 0;
}