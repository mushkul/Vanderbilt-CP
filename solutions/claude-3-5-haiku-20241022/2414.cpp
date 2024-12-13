#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> B(n * (n - 1) / 2);
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        cin >> B[i];
    }
    
    sort(B.begin(), B.end());
    
    vector<int> A(n);
    A[0] = B[0];
    set<int> used;
    used.insert(A[0]);
    
    for (int i = 1; i < n; i++) {
        vector<int> sums;
        for (int j : used) {
            sums.push_back(j + A[0]);
        }
        
        sort(sums.begin(), sums.end());
        
        int index = 0;
        while (index < sums.size() && binary_search(B.begin(), B.end(), sums[index])) {
            index++;
        }
        
        A[i] = sums[index] - A[0];
        used.insert(A[i]);
    }
    
    for (int x : A) {
        cout << x << " ";
    }
    
    return 0;
}