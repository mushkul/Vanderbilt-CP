#include<bits/stdc++.h>
using namespace std;

struct Movie {
    int start, end;

    Movie(int start=0, int end=0) : start(start), end(end) {}

    bool operator < (const Movie &other) const {
        return end < other.end;
    }
};

const int MAX = 1e6+5;
int n, q, maxMovies[MAX], lastMovie;
vector<Movie> movies;
vector<pair<int, int>> queries;
vector<vector<int>> queriesAtRt(MAX);

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> n >> q;
    for(int i=0; i<n; i++) {
        int start, end; cin >> start >> end;
        movies.push_back(Movie(start, end));
    }
    for(int i=0; i<q; i++) {
        int start, end; cin >> start >> end;
        queries.push_back({start, end});
        queriesAtRt[end].push_back(i);
    }
    sort(movies.begin(), movies.end());
    multiset<int> watching;
    int movie_ptr = 0;
    for(int i = 1; i < MAX; i++) {
        while(movie_ptr < n && movies[movie_ptr].end < i) {
            watching.erase(watching.find(movies[movie_ptr].start));
            movie_ptr++;
        }
        maxMovies[i] = max((int)watching.size(), maxMovies[i-1]);
        for(int id : queriesAtRt[i]) {
            while(!watching.empty() && *watching.begin() < queries[id].first) {
                watching.erase(watching.begin());
            }
            maxMovies[i] = max((int)watching.size(), maxMovies[i]);
        }
        while(movie_ptr < n && movies[movie_ptr].end == i) {
            watching.insert(movies[movie_ptr].start);
            movie_ptr++;
        }
    }
    for(auto &query : queries) {
        cout << maxMovies[query.second] << "\n";
    }
}