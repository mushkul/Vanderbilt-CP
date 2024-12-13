#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hammingDistance(long long a, long long b) {
    long long x = a ^ b;
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<long long> nums;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        long long num = 0;
        for(int j = 0; j < k; j++) {
            if(s[j] == '1') {
                num |= (1LL << (k-1-j));
            }
        }
        nums.push_back(num);
    }
    
    int minDist = k;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            minDist = min(minDist, hammingDistance(nums[i], nums[j]));
        }
    }
    
    cout << minDist << endl;
    
    return 0;
}