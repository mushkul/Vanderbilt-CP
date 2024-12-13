#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int,int>> players;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        players.push_back({x, i+1});
    }
    
    vector<pair<int,int>> games;
    while(true) {
        sort(players.rbegin(), players.rend());
        if(players[0].first == 0) break;
        
        bool possible = false;
        for(int i = 1; i < n && players[i].first > 0; i++) {
            vector<pair<int,int>> temp = games;
            bool valid = true;
            for(auto g : temp) {
                if((g.first == players[0].second && g.second == players[i].second) ||
                   (g.first == players[i].second && g.second == players[0].second)) {
                    valid = false;
                    break;
                }
            }
            
            if(valid) {
                games.push_back({players[0].second, players[i].second});
                players[0].first--;
                players[i].first--;
                possible = true;
                break;
            }
        }
        
        if(!possible) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    
    cout << games.size() << "\n";
    for(auto g : games) {
        cout << g.first << " " << g.second << "\n";
    }
    
    return 0;
}