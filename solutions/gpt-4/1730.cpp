#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n; 
        vector<int> x(n);
        int xor_value = 0;
        for(int& val: x) {
            cin >> val;
            xor_value ^= val;
        }
        cout << (xor_value == 0 ? "second" : "first") << "\n";
    }
    return 0;
}