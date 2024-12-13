#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> movies[200000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> movies[i].second >> movies[i].first;
    }
    sort(movies, movies + n);
    int count = 0;
    int current_end = 0;
    for (int i = 0; i < n; ++i) {
        if (movies[i].second >= current_end) {
            current_end = movies[i].first;
            ++count;
        }
    }
    cout << count << endl;
    return 0;
}