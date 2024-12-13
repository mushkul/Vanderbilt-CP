#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;
const int MAXN = 501;

struct Edge {
    int to, capacity, cost, flow, back;
};

vector<Edge> graph[MAXN];
int dist[MAXN], parent[MAXN], parent_edge[MAXN];
bool in_queue[MAXN];
int n, m, k;

void addEdge(int u, int v, int cap, int cost) {
    Edge a = {v, cap, cost, 0, (int)graph[v].size()};
    Edge b = {u, 0, -cost, 0, (int)graph[u].size()};
    graph[u].push_back(a);
    graph[v].push_back(b);
}

bool spfa(int s, int t) {
    fill(dist, dist + MAXN, INF);
    fill(in_queue, in_queue + MAXN, false);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    in_queue[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;
        for (int i = 0; i < graph[u].size(); ++i) {
            Edge &e = graph[u][i];
            if (e.flow < e.capacity && dist[u] + e.cost < dist[e.to]) {
                dist[e.to] = dist[u] + e.cost;
                parent[e.to] = u;
                parent_edge[e.to] = i;
                if (!in_queue[e.to]) {
                    q.push(e.to);
                    in_queue[e.to] = true;
                }
            }
        }
    }
    return dist[t] != INF;
}

pair<int, vector<int>> minCostMaxFlow(int s, int t) {
    int flow = 0, cost = 0;
    vector<int> days;
    while (spfa(s, t) && flow < k) {
        int path_flow = INF, node_list[MAXN], node_count = 0;
        for (int v = t; v != s; v = parent[v]) {
            Edge &e = graph[parent[v]][parent_edge[v]];
            path_flow = min(path_flow, e.capacity - e.flow);
        }
        for (int v = t; v != s; v = parent[v]) {
            Edge &e = graph[parent[v]][parent_edge[v]];
            e.flow += path_flow;
            graph[v][e.back].flow -= path_flow;
            node_list[node_count++] = v;
        }
        node_list[node_count++] = s;
        
        if (flow < k) {
            cost += path_flow * dist[t];
            ++flow;
            vector<int> path;
            for (int i = node_count - 1; i >= 0; --i)
                path.push_back(node_list[i]);
            days.push_back(node_count - 1);
            for (int i = node_count - 1; i >= 0; --i)
                days.push_back(node_list[i]);
        }
    }
    return {flow == k ? cost : -1, days}; 
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        addEdge(a, b, 1, 1);
    }
    auto result = minCostMaxFlow(1, n);
    if (result.first == -1) {
        cout << -1 << endl;
    } else {
        cout << result.first << endl;
        int index = 0;
        for (int day = 0; day < k; day++) {
            int len = result.second[index++];
            cout << len << endl;
            for (int i = 0; i <= len; i++) {
                cout << result.second[index++];
                if (i < len) cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}