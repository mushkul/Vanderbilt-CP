#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k, n, m;
    cin >> k >> n >> m;
    
    vector<int> apple_count(k + 1, 0), banana_count(k + 1, 0);

    for (int i = 0; i < n; ++i) {
        int apple;
        cin >> apple;
        apple_count[apple]++;
    }
    
    for (int i = 0; i < m; ++i) {
        int banana;
        cin >> banana;
        banana_count[banana]++;
    }

    for (int w = 2; w <= 2 * k; ++w) {
        int total = 0;
        for (int aip = 1; aip < w; ++aip) {
            int bip = w - aip;
            if (bip >= 1 && bip <= k) {
                total += apple_count[aip] * banana_count[bip];
            }
        }
        cout << total << " ";
    }

    cout << "\n";
    
    return 0;
}