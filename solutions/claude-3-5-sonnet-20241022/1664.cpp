#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1000001;
int dp[1024][1024];
int jump[1024][21];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<pair<int,int>> movies(n);
    for(int i = 0; i < n; i++) {
        cin >> movies[i].second >> movies[i].first;
    }
    
    sort(movies.begin(), movies.end());
    
    vector<int> times;
    for(auto p : movies) {
        times.push_back(p.first);
        times.push_back(p.second);
    }
    sort(times.begin(), times.end());
    times.erase(unique(times.begin(), times.end()), times.end());
    
    int m = times.size();
    for(int i = 0; i < m; i++) {
        for(int j = i; j < m; j++) {
            int start = times[i];
            int end = times[j];
            
            int best = 0;
            int pos = i;
            for(auto p : movies) {
                if(p.second >= start && p.first <= end) {
                    best++;
                    start = p.first;
                }
            }
            dp[i][j] = best;
        }
    }
    
    for(int i = 0; i < m; i++) {
        jump[i][0] = upper_bound(times.begin(), times.end(), times[i]) - times.begin() - 1;
    }
    for(int j = 1; j < 21; j++) {
        for(int i = 0; i < m; i++) {
            jump[i][j] = jump[jump[i][j-1]][j-1];
        }
    }
    
    while(q--) {
        int a, b;
        cin >> a >> b;
        
        int l = lower_bound(times.begin(), times.end(), a) - times.begin();
        int r = lower_bound(times.begin(), times.end(), b) - times.begin();
        
        if(l >= m || times[l] > b) {
            cout << "0\n";
            continue;
        }
        
        if(r >= m || times[r] > b) r--;
        
        cout << dp[l][r] << "\n";
    }
}