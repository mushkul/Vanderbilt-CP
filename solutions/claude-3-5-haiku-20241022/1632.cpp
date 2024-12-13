#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].second >> movies[i].first;
    }
    
    sort(movies.begin(), movies.end());
    
    multiset<int> watchers;
    int total_movies = 0;
    
    for (auto& movie : movies) {
        auto it = watchers.upper_bound(movie.second);
        
        if (it == watchers.begin() && watchers.size() == k) continue;
        
        if (watchers.size() < k) {
            watchers.insert(movie.first);
            total_movies++;
        } else {
            watchers.erase(--it);
            watchers.insert(movie.first);
            total_movies++;
        }
    }
    
    cout << total_movies << endl;
    return 0;
}