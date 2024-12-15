#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    long long smallestMissingSum = 1;
    for (int i = 0; i < n; ++i) {
        if (coins[i] > smallestMissingSum) {
            break;
        }
        smallestMissingSum += coins[i];
    }
    cout << smallestMissingSum << endl;
    return 0;
}