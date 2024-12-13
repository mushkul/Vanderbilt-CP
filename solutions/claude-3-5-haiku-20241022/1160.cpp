#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOGN = 20;

int n, q, teleport[MAXN];
int cycle_num[MAXN];
int cycle_start[MAXN];
int cycle_len[MAXN];
vector<int> cycle_planets;

int find_cycle(int start) {
    vector<int> path;
    vector<bool> visited(n+1, false);
    int curr = start;
    
    while (!visited[curr]) {
        visited[curr] = true;
        path.push_back(curr);
        curr = teleport[curr];
    }
    
    int cycle_start_node = curr;
    int start_idx = find(path.begin(), path.end(), cycle_start_node) - path.begin();
    
    cycle_len[start] = path.size() - start_idx;
    cycle_start[start] = start_idx;
    
    for (int i = 0; i < path.size(); i++) {
        if (i >= start_idx) {
            cycle_num[path[i]] = start;
            cycle_planets.push_back(path[i]);
        }
    }
    
    return start_idx;
}

int find_distance(int start, int end) {
    int dist = 0;
    while (start != end) {
        start = teleport[start];
        dist++;
        if (dist > n) return -1;
    }
    return dist;
}

int solve_query(int a, int b) {
    if (a == b) return 0;
    
    if (cycle_num[a] != cycle_num[b]) return -1;
    
    if (cycle_num[a] != 0) {
        int cycle_start_a = cycle_start[cycle_num[a]];
        int cycle_start_b = cycle_start[cycle_num[b]];
        int len = cycle_len[cycle_num[a]];
        
        int pos_a = find(cycle_planets.begin(), cycle_planets.end(), a) - cycle_planets.begin();
        int pos_b = find(cycle_planets.begin(), cycle_planets.end(), b) - cycle_planets.begin();
        
        int diff = (pos_b - pos_a + len) % len;
        return diff;
    }
    
    return find_distance(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        cin >> teleport[i];
    }
    
    for (int i = 1; i <= n; i++) {
        if (cycle_num[i] == 0) {
            find_cycle(i);
        }
    }
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << solve_query(a, b) << "\n";
    }
    
    return 0;
}