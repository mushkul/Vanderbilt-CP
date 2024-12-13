#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m = n * (n - 1) / 2;
    vector<int> B(m);
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }
    sort(B.begin(), B.end());
    vector<int> A(n);
    
    A[0] = B[0] - B[n - 2];
    A[1] = B[n - 2] - B[m - 1];
    for (int i = 2; i < n; i++) {
        A[i] = B[i - 1] - A[0];
    }
    
    sort(A.begin(), A.end());
    do {
        vector<int> tempB;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                tempB.push_back(A[i] + A[j]);
            }
        }
        sort(tempB.begin(), tempB.end());
        if (tempB == B) {
            for (int i = 0; i < n; i++) {
                cout << A[i] << " ";
            }
            cout << endl;
            break;
        }
    } while (next_permutation(A.begin(), A.end()));

    return 0;
}