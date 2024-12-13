#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    
    double expected_inversions = 0.0;
    
    for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            double prob_a_greater = 0.0;
            
            for (int x = 1; x <= r[a]; x++) {
                for (int y = 1; y <= r[b]; y++) {
                    if (x > y) {
                        prob_a_greater += 1.0 / (r[a] * r[b]);
                    }
                }
            }
            
            expected_inversions += prob_a_greater;
        }
    }
    
    cout << fixed << setprecision(6) << expected_inversions << endl;
    
    return 0;
}