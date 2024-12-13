#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

int findDigit(ll k) {
    ll len = 1, digits = 9, start = 1;
    while (k > len * digits) {
        k -= len * digits;
        len++;
        digits *= 10;
        start *= 10;
    }
    
    start += (k - 1) / len;
    string s = to_string(start);
    return s[(k - 1) % len] - '0';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    cin >> q;
    
    while (q--) {
        ll k;
        cin >> k;
        cout << findDigit(k) << "\n";
    }
    
    return 0;
}