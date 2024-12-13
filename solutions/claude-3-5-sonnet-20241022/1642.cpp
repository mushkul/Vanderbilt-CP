#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<pair<int,pair<int,int>>> sums;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            sums.push_back({a[i]+a[j], {i+1,j+1}});
        }
    }
    
    sort(sums.begin(), sums.end());
    
    for(int i = 0; i < sums.size(); i++) {
        int target = x - sums[i].first;
        int left = i+1, right = sums.size()-1;
        
        while(left < right) {
            if(sums[left].first + sums[right].first == target) {
                pair<int,int> p1 = sums[i].second;
                pair<int,int> p2 = sums[left].second;
                pair<int,int> p3 = sums[right].second;
                
                if(p1.first != p2.first && p1.first != p2.second && 
                   p1.second != p2.first && p1.second != p2.second &&
                   p1.first != p3.first && p1.first != p3.second && 
                   p1.second != p3.first && p1.second != p3.second &&
                   p2.first != p3.first && p2.first != p3.second &&
                   p2.second != p3.first && p2.second != p3.second) {
                    cout << p1.first << " " << p1.second << " ";
                    cout << p2.first << " " << p2.second;
                    return 0;
                }
                left++;
                right--;
            }
            else if(sums[left].first + sums[right].first < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    
    cout << "IMPOSSIBLE";
    return 0;
}