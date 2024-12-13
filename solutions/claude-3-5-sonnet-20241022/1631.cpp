#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> times(n);
    for(int i = 0; i < n; i++) {
        cin >> times[i];
    }
    
    long long sum = 0;
    long long maxTime = 0;
    
    for(int i = 0; i < n; i++) {
        sum += times[i];
        maxTime = max(maxTime, times[i]);
    }
    
    cout << max(2*maxTime, sum) << endl;
    
    return 0;
}