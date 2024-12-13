#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> prufer(n-2);
    vector<int> degree(n+1, 1);
    
    for(int i = 0; i < n-2; i++) {
        cin >> prufer[i];
        degree[prufer[i]]++;
    }
    
    set<int> leaves;
    for(int i = 1; i <= n; i++) {
        if(degree[i] == 1) {
            leaves.insert(i);
        }
    }
    
    vector<pair<int,int>> edges;
    for(int i = 0; i < n-2; i++) {
        int leaf = *leaves.begin();
        leaves.erase(leaves.begin());
        
        edges.push_back({leaf, prufer[i]});
        
        degree[leaf]--;
        degree[prufer[i]]--;
        
        if(degree[prufer[i]] == 1) {
            leaves.insert(prufer[i]);
        }
    }
    
    edges.push_back({*leaves.begin(), *leaves.rbegin()});
    
    for(auto [a, b] : edges) {
        cout << a << " " << b << "\n";
    }
    
    return 0;
}