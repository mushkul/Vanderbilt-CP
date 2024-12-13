#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<long long> costs(n - k + 1, 0);
    multiset<int> left, right;
    long long leftSum = 0, rightSum = 0;

    auto balance = [&]() {
        if (left.size() > right.size() + 1) {
            auto it = prev(left.end());
            leftSum -= *it;
            rightSum += *it;
            right.insert(*it);
            left.erase(it);
        } else if (right.size() > left.size()) {
            auto it = right.begin();
            rightSum -= *it;
            leftSum += *it;
            left.insert(*it);
            right.erase(it);
        }
    };

    auto add = [&](int x) {
        if (!left.empty() && x <= *prev(left.end())) {
            left.insert(x);
            leftSum += x;
        } else {
            right.insert(x);
            rightSum += x;
        }
        balance();
    };

    auto remove = [&](int x) {
        if (left.find(x) != left.end()) {
            leftSum -= x;
            left.erase(left.find(x));
        } else {
            rightSum -= x;
            right.erase(right.find(x));
        }
        balance();
    };

    for (int i = 0; i < k; ++i) {
        add(arr[i]);
    }

    for (int i = k; i <= n; ++i) {
        int median = *prev(left.end());
        costs[i - k] = (left.size() * median - leftSum) + (rightSum - right.size() * median);
        if (i < n) {
            add(arr[i]);
            remove(arr[i - k]);
        }
    }

    for (auto cost : costs) {
        cout << cost << " ";
    }
    cout << endl;

    return 0;
}