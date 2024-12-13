#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin >> n;
    
    int len = 1;
    ll curr = 2;
    while (curr < n) {
        len++;
        curr += curr;
    }
    
    vector<int> ans;
    if (n == 1) {
        cout << "0";
        return 0;
    }
    
    ans.push_back(1);
    n--;
    curr = 2;
    
    while (n > curr) {
        ans.push_back(0);
        ans.push_back(1);
        n -= curr;
        curr *= 2;
    }
    
    if (n > 1) {
        ll rem = n - 1;
        string binary = "";
        while (rem > 0) {
            binary = (char)('0' + (rem % 2)) + binary;
            rem /= 2;
        }
        
        for (char c : binary) {
            ans.push_back(c - '0');
        }
    }
    
    for (int x : ans) {
        cout << x;
    }
    
    return 0;
}