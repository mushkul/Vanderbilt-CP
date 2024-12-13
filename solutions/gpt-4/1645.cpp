#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; ++i) cin >> a[i];

    vector<int> res(n+1, 0);
    stack<int> stk;
    for (int i=1; i<=n; ++i) {
        while (!stk.empty() && a[stk.top()] >= a[i]) {
            stk.pop();
        }
        res[i] = stk.empty() ? 0 : stk.top();
        stk.push(i);
    }
    
    for (int i=1; i<=n; ++i)
        cout << res[i] << ' ';
    cout << '\n';
    
    return 0;
}