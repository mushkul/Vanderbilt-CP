#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    set<int> sums;
    sums.insert(0);
    for (int coin : coins) {
        vector<int> toAdd;
        for (int sum : sums) {
            toAdd.push_back(sum + coin);
        }
        for (int newSum : toAdd) {
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