#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> ranges(n);
    vector<int> idx(n);
    
    for(int i = 0; i < n; i++) {
        cin >> ranges[i].first >> ranges[i].second;
        idx[i] = i;
    }
    
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        if(ranges[i].first == ranges[j].first)
            return ranges[i].second > ranges[j].second;
        return ranges[i].first < ranges[j].first;
    });
    
    vector<int> contains(n), contained(n);
    vector<int> maxRight(n);
    
    maxRight[n-1] = ranges[idx[n-1]].second;
    for(int i = n-2; i >= 0; i--) {
        maxRight[i] = max(ranges[idx[i]].second, maxRight[i+1]);
    }
    
    int minRight = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(maxRight[i] <= ranges[idx[i]].second)
            contains[idx[i]] = 1;
        if(minRight >= ranges[idx[i]].second)
            contained[idx[i]] = 1;
        minRight = min(minRight, ranges[idx[i]].second);
    }
    
    for(int i = 0; i < n; i++)
        cout << contains[i] << " ";
    cout << "\n";
    
    for(int i = 0; i < n; i++) 
        cout << contained[i] << " ";
    cout << "\n";
    
    return 0;
}