#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    vector<int> p(n);
    vector<int> removed(n);
    for (int &p_i : p) cin >> p_i;
    set<int> not_removed;
    for (int i = 0; i < n; i++) not_removed.insert(i);
    for (int i = 0; i < n; i++) {
        auto it = next(not_removed.begin(), p[i]-1);
        removed[i] = a[*it].first;
        not_removed.erase(it);
    }
    for (int r : removed) cout << r << " ";
    cout << "\n";
}