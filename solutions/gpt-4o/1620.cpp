#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canProduceInTime(const vector<long long>& machines, long long t, long long time) {
    long long total = 0;
    for(long long k : machines) {
        total += time / k;
        if(total >= t) return true;
    }
    return total >= t;
}

int main() {
    int n;
    long long t;
    cin >> n >> t;
    vector<long long> machines(n);
    for(int i = 0; i < n; ++i) {
        cin >> machines[i];
    }

    long long left = 1, right = 1e18, answer = right;
    while(left <= right) {
        long long mid = left + (right - left) / 2;
        if(canProduceInTime(machines, t, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}