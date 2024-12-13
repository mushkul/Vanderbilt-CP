#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, x;
    cin >> n >> x;
    
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    
    sort(a.begin(), a.end());
    
    for(int i = 0; i < n; i++) {
        int target = x - a[i].first;
        int left = i+1;
        int right = n-1;
        
        while(left < right) {
            int sum = a[left].first + a[right].first;
            if(sum == target) {
                cout << a[i].second << " " << a[left].second << " " << a[right].second;
                return 0;
            }
            if(sum > target) right--;
            else left++;
        }
    }
    
    cout << "IMPOSSIBLE";
    return 0;
}