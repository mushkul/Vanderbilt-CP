#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    sort(coins.begin(), coins.end());
    
    long long smallest_sum = 1;
    
    for(int i = 0; i < n; i++) {
        if(coins[i] > smallest_sum) {
            break;
        }
        smallest_sum += coins[i];
    }
    
    cout << smallest_sum << endl;
    
    return 0;
}