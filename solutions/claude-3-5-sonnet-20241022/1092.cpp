#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin >> n;
    
    ll sum = n * (n + 1) / 2;
    
    if (sum % 2) {
        cout << "NO\n";
        return 0;
    }
    
    cout << "YES\n";
    vector<int> set1, set2;
    ll target = sum / 2;
    ll currSum = 0;
    
    for (int i = n; i >= 1; i--) {
        if (currSum + i <= target) {
            set1.push_back(i);
            currSum += i;
        } else {
            set2.push_back(i);
        }
    }
    
    cout << set1.size() << "\n";
    for (int i = 0; i < set1.size(); i++) {
        cout << set1[i] << (i < set1.size()-1 ? " " : "\n");
    }
    
    cout << set2.size() << "\n";
    for (int i = 0; i < set2.size(); i++) {
        cout << set2[i] << (i < set2.size()-1 ? " " : "\n");
    }
    
    return 0;
}