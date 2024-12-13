#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    set<int> sums;
    sums.insert(0);
    
    for(int coin : coins) {
        vector<int> newSums;
        for(int sum : sums) {
            newSums.push_back(sum + coin);
        }
        for(int sum : newSums) {
            sums.insert(sum);
        }
    }
    
    sums.erase(0);
    cout << sums.size() << "\n";
    for(int sum : sums) {
        cout << sum << " ";
    }
    return 0;
}