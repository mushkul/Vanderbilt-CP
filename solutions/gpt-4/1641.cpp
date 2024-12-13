c++
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x; cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = a[i].first + a[j].first + a[k].first;
            if (sum == x) {
                cout << a[i].second << " " << a[j].second << " " << a[k].second << "\n";
                return 0;
            }
            else if (sum < x) j++;
            else k--;
        }
    }
    cout << "IMPOSSIBLE\n";
}