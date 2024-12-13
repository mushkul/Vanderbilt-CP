#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if (k == 1 || k > n) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        vector<int> permutation(n);
        for(int i = 0; i < n; ++i) permutation[i] = i + 1;
        if (k == n) {
            for(int i = 0; i < n; ++i) cout << permutation[i] << " ";
            cout << endl;
            continue;
        }
        for(int i = k-1; i < n-1; ++i) {
            swap(permutation[i], permutation[i+1]);
        }
        for(int i = 0; i < n; ++i) cout << permutation[i] << " ";
        cout << endl;
    }
    return 0;
}