#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int hammingDistance(const string& a, const string& b) {
    int dist = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) ++dist;
    }
    return dist;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> strings(n);
    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
    }
    
    int minDist = INT_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dist = hammingDistance(strings[i], strings[j]);
            if (dist < minDist) {
                minDist = dist;
            }
        }
    }
    
    cout << minDist << endl;
    return 0;
}