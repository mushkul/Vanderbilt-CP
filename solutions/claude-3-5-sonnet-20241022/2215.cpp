#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& p, int k) {
    int n = p.size();
    
    vector<int> lis(n, 1);
    int max_inc = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(p[i] > p[j]) {
                lis[i] = max(lis[i], lis[j] + 1);
                max_inc = max(max_inc, lis[i]);
            }
        }
    }
    
    vector<int> lds(n, 1);
    int max_dec = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(p[i] < p[j]) {
                lds[i] = max(lds[i], lds[j] + 1);
                max_dec = max(max_dec, lds[i]);
            }
        }
    }
    
    return max_inc == k && max_dec == k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    if(k > n || (k == 1 && n > 1)) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    
    if(k == n) {
        for(int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    
    vector<int> p;
    int curr = 1;
    
    // Build alternating subsequence
    while(p.size() < n) {
        if(p.size() % 2 == 0) {
            p.push_back(curr++);
        } else {
            p.push_back(curr + k - 1);
            curr++;
        }
    }
    
    if(check(p, k)) {
        for(int x : p) cout << x << " ";
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}