#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    long long arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    long long count = 0, prefixSum = 0;
    unordered_map<long long, int> sumFreq;
    sumFreq[0] = 1;
    
    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        
        if (sumFreq.find(prefixSum - x) != sumFreq.end()) {
            count += sumFreq[prefixSum - x];
        }
        
        sumFreq[prefixSum]++;
    }
    
    cout << count << endl;
    
    return 0;
}