#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<pair<int, pair<int, int>>> pairSums;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pairSums.push_back({arr[i] + arr[j], {i, j}});
        }
    }
    
    sort(pairSums.begin(), pairSums.end());
    
    for (int i = 0; i < pairSums.size(); i++) {
        int complement = x - pairSums[i].first;
        
        auto it = lower_bound(pairSums.begin(), pairSums.end(), make_pair(complement, make_pair(0, 0)));
        
        while (it != pairSums.end() && it->first == complement) {
            int a = pairSums[i].second.first;
            int b = pairSums[i].second.second;
            int c = it->second.first;
            int d = it->second.second;
            
            if (a != c && a != d && b != c && b != d) {
                cout << a+1 << " " << b+1 << " " << c+1 << " " << d+1 << endl;
                return 0;
            }
            
            it++;
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
    return 0;
}