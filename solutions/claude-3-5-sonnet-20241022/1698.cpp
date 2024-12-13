#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    
    vector<vector<pair<int,int>>> ans;
    
    while(true) {
        vector<pair<int,int>> round;
        vector<bool> used(n);
        
        for(int i = 0; i < n; i++) {
            if(used[i] || a[i] == i) continue;
            int j = i;
            vector<int> cycle;
            
            while(!used[j]) {
                used[j] = true;
                cycle.push_back(j);
                j = a[j];
            }
            
            for(int k = 0; k < (int)cycle.size()-1; k += 2) {
                round.push_back({cycle[k], cycle[k+1]});
                swap(a[cycle[k]], a[cycle[k+1]]);
            }
            
            if(cycle.size() % 2) {
                if(!round.empty()) {
                    int x = round.back().second;
                    round.pop_back();
                    swap(a[cycle.back()], a[x]);
                    swap(a[cycle[cycle.size()-2]], a[cycle.back()]);
                    round.push_back({cycle[cycle.size()-2], cycle.back()});
                    round.push_back({x, cycle.back()});
                }
            }
        }
        
        if(round.empty()) break;
        ans.push_back(round);
    }
    
    cout << ans.size() << "\n";
    for(auto round : ans) {
        cout << round.size() << "\n";
        for(auto p : round) {
            cout << p.first+1 << " " << p.second+1 << "\n";
        }
    }
    
    return 0;
}