#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n >> x;
    
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    
    sort(a.begin(), a.end());
    
    int left = 0, right = n-1;
    while(left < right) {
        int sum = a[left].first + a[right].first;
        if(sum == x) {
            cout << a[left].second << " " << a[right].second;
            return 0;
        }
        if(sum < x) left++;
        else right--;
    }
    
    cout << "IMPOSSIBLE";
    return 0;
}