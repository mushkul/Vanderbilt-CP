#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].first >> movies[i].second;
    }

    sort(movies.begin(), movies.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    for (int i = 0; i < q; i++) {
        int arrival, leaving;
        cin >> arrival >> leaving;

        int count = 0;
        int lastEndTime = arrival;

        for (const auto& movie : movies) {
            if (movie.first >= arrival && movie.second <= leaving && movie.first >= lastEndTime) {
                count++;
                lastEndTime = movie.second;
            }
        }

        cout << count << '\n';
    }

    return 0;
}