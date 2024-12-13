#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> result(n);
    iota(result.begin(), result.end(), 1);
    for(int i = n - 1; i >= 0; --i) {
        int j = max(0, i - k);
        reverse(result.begin() + j, result.begin() + i + 1);
        k -= i - j;
    }
    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}