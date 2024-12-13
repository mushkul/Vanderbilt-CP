#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to, capacity, reverse;
};

class FlowNetwork {
public:
    FlowNetwork(int n) : graph(n), level(n), start(n) {}

    void add_edge(int from, int to, int capacity) {
        Edge a = {to, capacity, graph[to].size()};
        Edge b = {from, 0, graph[from].size()};
        graph[from].push_back(a);
        graph[to].push_back(b);
    }

    int max_flow(int source, int sink);

private:
    vector<vector<Edge>> graph;
    vector<int> level;
    vector<int> start;

    bool bfs(int source, int sink);
    int dfs(int node, int sink, int flow);
};

bool FlowNetwork::bfs(int source, int sink) {
    fill(level.begin(), level.end(), -1);
    queue<int> q;
    level[source] = 0;
    q.push(source);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (const auto& e : graph[curr]) {
            if (level[e.to] == -1 && e.capacity > 0) {
                q.push(e.to);
                level[e.to] = level[curr] + 1;
                if (e.to == sink) return true;
            }
        }
    }
    return false;
}

int FlowNetwork::dfs(int node, int sink, int flow) {
    if (node == sink) return flow;
    for (int& i = start[node]; i < graph[node].size(); ++i) {
        Edge &e = graph[node][i];
        if (e.capacity > 0 && level[e.to] == level[node] + 1) {
            int curr_flow = min(flow, e.capacity);
            int temp_flow = dfs(e.to, sink, curr_flow);
            if (temp_flow > 0) {
                e.capacity -= temp_flow;
                graph[e.to][e.reverse].capacity += temp_flow;
                return temp_flow;
            }
        }
    }
    return 0;
}

int FlowNetwork::max_flow(int source, int sink) {
    int max_flow = 0;
    while (bfs(source, sink)) {
        fill(start.begin(), start.end(), 0);
        while (int flow = dfs(source, sink, INT_MAX)) {
            max_flow += flow;
        }
    }
    return max_flow;
}

int main() {
    int n, m;
    cin >> n >> m;
    FlowNetwork fn(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        fn.add_edge(a, b, c);
    }
    cout << fn.max_flow(1, n) << endl;
    return 0;
}