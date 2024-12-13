#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k, n, m;
    cin >> k >> n >> m;
    
    vector<long long> apple(k+1);
    vector<long long> banana(k+1);
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        apple[x]++;
    }
    
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x; 
        banana[x]++;
    }
    
    for(int sum = 2; sum <= 2*k; sum++) {
        long long ways = 0;
        for(int i = 1; i <= min(k,sum-1); i++) {
            if(sum-i <= k) {
                ways += apple[i] * banana[sum-i];
            }
        }
        cout << ways << " ";
    }
    
    return 0;
}