#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canDivide(const vector<long long>& arr, long long maxSum, int k) {
    long long currentSum = 0;
    int subarrays = 1;

    for (long long num : arr) {
        if (num > maxSum) return false;
        
        if (currentSum + num > maxSum) {
            subarrays++;
            currentSum = num;
        } else {
            currentSum += num;
        }
    }

    return subarrays <= k;
}

long long solve(vector<long long>& arr, int k) {
    long long left = *max_element(arr.begin(), arr.end());
    long long right = accumulate(arr.begin(), arr.end(), 0LL);
    long long result = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (canDivide(arr, mid, k)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << solve(arr, k) << "\n";

    return 0;
}