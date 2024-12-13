#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> b(n*(n-1)/2);
    for(int i = 0; i < n*(n-1)/2; i++) {
        cin >> b[i];
    }
    
    sort(b.begin(), b.end());
    vector<int> a(n);
    
    a[0] = (b[0] + b[1] - b[n-1])/2;
    
    for(int i = 1; i < n; i++) {
        a[i] = b[i-1] - a[0];
    }
    
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}