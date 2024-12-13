#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<array<int, 3>> ranges(n);
    for (int i = 0; i < n; i++) {
        cin >> ranges[i][0] >> ranges[i][1];
        ranges[i][2] = i;
    }
    
    sort(ranges.begin(), ranges.end(), [](const auto& a, const auto& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    
    vector<int> contains(n, 0);
    vector<int> contained(n, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            
            if (ranges[i][0] <= ranges[j][0] && ranges[j][1] <= ranges[i][1]) {
                contains[ranges[i][2]]++;
            }
            
            if (ranges[j][0] <= ranges[i][0] && ranges[i][1] <= ranges[j][1]) {
                contained[ranges[i][2]]++;
            }
        }
    }
    
    for (int x : contains) cout << x << " ";
    cout << "\n";
    
    for (int x : contained) cout << x << " ";
    cout << "\n";
    
    return 0;
}