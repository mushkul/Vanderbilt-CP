#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> position(n + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        position[x] = i;
    }
    int rounds = 1;
    for (int i = 2; i <= n; ++i) {
        if (position[i] < position[i - 1]) {
            ++rounds;
        }
    }
    cout << rounds << endl;
    return 0;
}