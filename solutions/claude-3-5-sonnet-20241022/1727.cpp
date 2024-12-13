#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    double result = 0;
    
    for(int max_val = 1; max_val <= k; max_val++) {
        double prob = 1;
        double prob_at_most = pow((double)max_val/k, n);
        double prob_at_most_prev = max_val > 1 ? pow((double)(max_val-1)/k, n) : 0;
        prob = prob_at_most - prob_at_most_prev;
        result += max_val * prob;
    }
    
    cout << fixed << setprecision(6) << result << "\n";
    
    return 0;
}