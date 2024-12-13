#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<long long> calculateSubsetSums(const vector<int>& nums) {
    vector<long long> subsetSums;
    int n = nums.size();
    for (int i = 0; i < (1 << n); ++i) {
        long long sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sum += nums[j];
            }
        }
        subsetSums.push_back(sum);
    }
    return subsetSums;
}

int main() {
    int n;
    long long x;
    cin >> n >> x;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    int n1 = n / 2, n2 = n - n1;

    vector<int> left(t.begin(), t.begin() + n1);
    vector<int> right(t.begin() + n1, t.end());

    auto leftSums = calculateSubsetSums(left);
    auto rightSums = calculateSubsetSums(right);

    unordered_map<long long, long long> rightSumCount;
    for (auto sum : rightSums) {
        ++rightSumCount[sum];
    }

    long long count = 0;
    for (auto sum : leftSums) {
        auto it = rightSumCount.find(x - sum);
        if (it != rightSumCount.end()) {
            count += it->second;
        }
    }

    cout << count << endl;
    return 0;
}