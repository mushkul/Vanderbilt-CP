#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    
    vector<vector<pair<int, int>>> rounds;
    vector<bool> used(n, false);
    
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        
        vector<pair<int, int>> round;
        for (int j = i + 1; j < n; j++) {
            if (used[j]) continue;
            
            if (p[i] > p[j]) {
                round.emplace_back(i, j);
                used[i] = true;
                used[j] = true;
                break;
            }
        }
        
        if (!used[i]) {
            for (int j = i + 1; j < n; j++) {
                if (!used[j] && p[i] > p[j]) {
                    round.emplace_back(i, j);
                    used[i] = true;
                    used[j] = true;
                    break;
                }
            }
        }
        
        if (!round.empty()) {
            rounds.push_back(round);
        }
    }
    
    cout << rounds.size() << endl;
    for (const auto& round : rounds) {
        cout << round.size() << endl;
        for (const auto& [x, y] : round) {
            cout << x + 1 << " " << y + 1 << endl;
        }
    }
    
    return 0;
}