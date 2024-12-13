#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    const int INF = 1e9 + 7;
    vector<int> tail(n+1, INF);

    tail[0] = -INF;
    for (int i = 0; i < n; ++i) {
        auto it = upper_bound(tail.begin(), tail.end(), arr[i]);
        if (*it == INF) *prev(it) = arr[i];
        else if (arr[i] < *it) *it = arr[i];
    }

    for (int i = n; i >= 1; --i) {
        if (tail[i] != INF) {
            cout << i;
            break;
        }
    }

    return 0;
}