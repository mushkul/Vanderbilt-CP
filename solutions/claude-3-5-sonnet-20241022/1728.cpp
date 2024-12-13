#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    
    double ans = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            double prob = 0;
            
            for (int x = 1; x <= r[i]; x++) {
                for (int y = 1; y <= r[j]; y++) {
                    if (x > y) {
                        prob += 1.0 / (r[i] * r[j]);
                    }
                }
            }
            
            ans += prob;
        }
    }
    
    cout << fixed << setprecision(6) << ans << endl;
    
    return 0;
}