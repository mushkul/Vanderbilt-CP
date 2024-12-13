#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; ++i) {
        cin >> movies[i].first >> movies[i].second;
    }
    
    sort(movies.begin(), movies.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    vector<tuple<int, int, int>> queries;
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        queries.push_back({a, b, i});
    }
    
    sort(queries.begin(), queries.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<1>(a) < get<1>(b);
    });
    
    vector<int> results(q);
    multiset<int> activeMovies;
    int movieIndex = 0;

    for (auto& [a, b, queryIndex] : queries) {
        while (movieIndex < n && movies[movieIndex].second <= b) {
            if (movies[movieIndex].first >= a) {
                activeMovies.insert(movies[movieIndex].second);
            }
            ++movieIndex;
        }
        
        auto it = activeMovies.lower_bound(a);
        int count = 0;
        
        while (it != activeMovies.end() && *it <= b) {
            ++count;
            it = activeMovies.upper_bound(*it);
        }
        
        results[queryIndex] = count;
    }
    
    for (int result : results) {
        cout << result << "\n";
    }

    return 0;
}