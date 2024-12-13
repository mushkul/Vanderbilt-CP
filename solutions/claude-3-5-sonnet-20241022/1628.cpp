#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void generate(vector<ll>& arr, vector<ll>& sums, int start, int end, ll currSum) {
    if (start == end) {
        sums.push_back(currSum);
        return;
    }
    generate(arr, sums, start + 1, end, currSum);
    generate(arr, sums, start + 1, end, currSum + arr[start]);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    ll x;
    cin >> n >> x;
    
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<ll> leftSums, rightSums;
    int mid = n/2;
    
    generate(arr, leftSums, 0, mid, 0);
    generate(arr, rightSums, mid, n, 0);
    
    sort(rightSums.begin(), rightSums.end());
    
    ll result = 0;
    for (ll sum : leftSums) {
        ll target = x - sum;
        auto upper = upper_bound(rightSums.begin(), rightSums.end(), target);
        auto lower = lower_bound(rightSums.begin(), rightSums.end(), target);
        result += upper - lower;
    }
    
    cout << result << "\n";
    
    return 0;
}