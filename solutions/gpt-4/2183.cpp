#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin >> n;
    vector<ll> coin(n);
    for(int i=0; i<n; i++)
        cin >> coin[i];
    sort(coin.begin(), coin.end());
    ll sum = 1;
    for(int i=0; i<n; i++) {
        if(coin[i] > sum)
            break;
        else
            sum += coin[i];
    }
    cout << sum << "\n";
    return 0;
}