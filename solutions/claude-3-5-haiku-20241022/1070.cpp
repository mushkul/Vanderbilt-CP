#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    
    vector<int> ans;
    
    for (int i = 2; i <= n; i += 2) {
        ans.push_back(i);
    }
    
    for (int i = 1; i <= n; i += 2) {
        ans.push_back(i);
    }
    
    for (int num : ans) {
        cout << num << " ";
    }
    
    return 0;
}