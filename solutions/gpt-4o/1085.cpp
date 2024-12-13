#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canDivide(const vector<int>& array, int maxSum, int k) {
    int currentSum = 0, parts = 1;
    for (int num : array) {
        if (currentSum + num > maxSum) {
            parts++;
            currentSum = num;
            if (parts > k) {
                return false;
            }
        }
        else {
            currentSum += num;
        }
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    int low = *max_element(array.begin(), array.end());
    int high = accumulate(array.begin(), array.end(), 0LL);

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canDivide(array, mid, k)) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }

    cout << low << endl;
    return 0;
}