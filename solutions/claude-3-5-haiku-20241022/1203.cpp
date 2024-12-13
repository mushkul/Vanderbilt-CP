#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<pair<int, int>> graph[MAXN];
vector<pair<int, int>> rev_graph[MAXN];
vector<long long> dist1(MAXN, LLONG_MAX);
vector<long long> dist2(MAXN, LLONG_MAX);
vector<bool> used(MAXN, false);

void dijkstra1(int start, int n) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist1[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for (auto [v, w] : graph[u]) {
            if (dist1[u] + w < dist1[v]) {
                dist1[v] = dist1[u] + w;
                pq.push({dist1[v], v});
            }
        }
    }
}

void dijkstra2(int end, int n) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist2[end] = 0;
    pq.push({0, end});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        for (auto [v, w] : rev_graph[u]) {
            if (dist2[u] + w < dist2[v]) {
                dist2[v] = dist2[u] + w;
                pq.push({dist2[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        rev_graph[b].push_back({a, c});
    }
    
    dijkstra1(1, n);
    dijkstra2(n, n);
    
    long long shortest = dist1[n];
    
    for (int i = 1; i <= n; i++) {
        for (auto [j, w] : graph[i]) {
            if (dist1[i] + w + dist2[j] == shortest) {
                used[i] = true;
                used[j] = true;
            }
        }
    }
    
    vector<int> result;
    for (int i = 1; i <= n; i++) {
        if (used[i]) result.push_back(i);
    }
    
    cout << result.size() << "\n";
    for (int city : result) {
        cout << city << " ";
    }
    
    return 0;
}