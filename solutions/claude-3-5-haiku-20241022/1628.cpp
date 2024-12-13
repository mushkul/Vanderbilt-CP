#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void generateSubsetSums(vector<ll>& arr, vector<ll>& sums) {
    int n = arr.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        ll sum = 0;
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                sum += arr[j];
            }
        }
        sums.push_back(sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll x;
    cin >> n >> x;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<ll> left_sums, right_sums;
    int mid = n / 2;

    vector<ll> left_half(arr.begin(), arr.begin() + mid);
    vector<ll> right_half(arr.begin() + mid, arr.end());

    generateSubsetSums(left_half, left_sums);
    generateSubsetSums(right_half, right_sums);

    sort(right_sums.begin(), right_sums.end());

    ll count = 0;
    for (ll left_sum : left_sums) {
        ll target = x - left_sum;
        auto range = equal_range(right_sums.begin(), right_sums.end(), target);
        count += range.second - range.first;
    }

    cout << count << '\n';

    return 0;
}