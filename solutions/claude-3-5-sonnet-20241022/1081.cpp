#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    
    int maxNum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        maxNum = max(maxNum, a[i]);
    }
    
    vector<int> div(maxNum + 1);
    for(int i = 0; i < n; i++) {
        for(int j = 1; j * j <= a[i]; j++) {
            if(a[i] % j == 0) {
                div[j]++;
                if(j * j != a[i]) {
                    div[a[i] / j]++;
                }
            }
        }
    }
    
    for(int i = maxNum; i >= 1; i--) {
        if(div[i] >= 2) {
            cout << i;
            break;
        }
    }
    
    return 0;
}