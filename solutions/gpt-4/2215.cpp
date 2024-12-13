#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(k > sqrt(2*n)) {
            cout << "IMPOSSIBLE\n";
        } else {
            for(int i=1; i<n-k+1; i++) {
                cout << i << " ";
            }
            for(int i=n; i>=n-k+1; i--) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}