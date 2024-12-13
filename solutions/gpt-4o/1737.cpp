#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<vector<long long>> arrays(1, vector<long long>(n));
    for(int i = 0; i < n; i++) {
        cin >> arrays[0][i];
    }

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int k, a, x;
            cin >> k >> a >> x;
            arrays[k - 1][a - 1] = x;
        } else if(type == 2) {
            int k, a, b;
            cin >> k >> a >> b;
            long long sum = 0;
            for(int i = a - 1; i <= b - 1; i++) {
                sum += arrays[k - 1][i];
            }
            cout << sum << '\n';
        } else if(type == 3) {
            int k;
            cin >> k;
            arrays.push_back(arrays[k - 1]);
        }
    }

    return 0;
}