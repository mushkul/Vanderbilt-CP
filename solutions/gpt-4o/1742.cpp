#include <iostream>
#include <unordered_set>
#include <utility>

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int main() {
    int n;
    cin >> n;
    char d;
    int x, total_distance = 0, cx = 0, cy = 0;
    unordered_set<pair<int, int>, pair_hash> visited;
    visited.insert({0, 0});
    
    for (int i = 0; i < n; ++i) {
        cin >> d >> x;
        for (int step = 0; step < x; ++step) {
            if(d == 'U') cy++;
            else if(d == 'D') cy--;
            else if(d == 'L') cx--;
            else if(d == 'R') cx++;
            
            if (visited.count({cx, cy})) {
                cout << total_distance << endl;
                return 0;
            }
            visited.insert({cx, cy});
            total_distance += 1;
        }
    }
    cout << total_distance << endl;
    return 0;
}