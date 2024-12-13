#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum % 2 != 0) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
        vector<int> set1, set2;
        sum /= 2;
        for (int i = n; i >= 1; i--) {
            if (i <= sum) {
                set1.push_back(i);
                sum -= i;
            } else {
                set2.push_back(i);
            }
        }
        cout << set1.size() << "\n";
        for (int i = 0; i < set1.size(); i++) {
            cout << set1[i] << " ";
        }
        cout << "\n" << set2.size() << "\n";
        for (int i = 0; i < set2.size(); i++) {
            cout << set2[i] << " ";
        }
    }
    return 0;
}