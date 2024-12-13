#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    set<int> sums;
    sums.insert(0);
    
    for (int coin : coins) {
        vector<int> newSums;
        for (int sum : sums) {
            newSums.push_back(sum + coin);
        }
        
        for (int newSum : newSums) {
            sums.insert(newSum);
        }
    }
    
    sums.erase(0);
    
    cout << sums.size() << endl;
    for (int sum : sums) {
        cout << sum << " ";
    }
    cout << endl;
    
    return 0;
}