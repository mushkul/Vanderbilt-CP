#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<pair<int, int>> reversals;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        int pos = find(arr.begin() + i, arr.end(), i + 1) - arr.begin();
        
        if (pos != i) {
            if (pos != n - 1) {
                reverse(arr.begin() + pos, arr.end());
                reversals.emplace_back(pos + 1, n);
            }
            
            reverse(arr.begin() + i, arr.begin() + pos + 1);
            reversals.emplace_back(i + 1, pos + 1);
        }
    }

    cout << reversals.size() << endl;
    for (auto& r : reversals) {
        cout << r.first << " " << r.second << endl;
    }

    return 0;
}