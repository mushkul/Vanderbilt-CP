#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> players(n);
    for (int i = 0; i < n; i++) {
        cin >> players[i].first;
        players[i].second = i + 1;
    }
    
    sort(players.rbegin(), players.rend());
    
    vector<pair<int, int>> matches;
    
    for (int i = 0; i < n; i++) {
        int current_games = players[i].first;
        
        for (int j = i + 1; j < n && current_games > 0; j++) {
            if (players[j].first > 0) {
                matches.emplace_back(players[i].second, players[j].second);
                players[i].first--;
                players[j].first--;
                current_games--;
            }
        }
        
        if (current_games > 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (players[i].first > 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    
    cout << matches.size() << endl;
    for (auto& match : matches) {
        cout << match.first << " " << match.second << endl;
    }
    
    return 0;
}