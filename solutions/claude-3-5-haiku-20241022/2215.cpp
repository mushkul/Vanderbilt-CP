#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, int k) {
    if (k == 1) {
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 1);
        reverse(perm.begin(), perm.end());
        return perm;
    }
    
    if (k == n) {
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 1);
        return perm;
    }
    
    vector<int> perm(n);
    for (int i = 0; i < k; i++) {
        perm[i] = i + 1;
    }
    
    int curr = k + 1;
    for (int i = k - 1; i >= 0; i--) {
        perm[i + n - k] = curr++;
    }
    
    for (int i = k; i < n - k; i++) {
        perm[i] = curr++;
    }
    
    return perm;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        if (k > n || k < 1) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        
        vector<int> result = solve(n, k);
        
        for (int num : result) {
            cout << num << " ";
        }
        cout << "\n";
    }
    
    return 0;
}