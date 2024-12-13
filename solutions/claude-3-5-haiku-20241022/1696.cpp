#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> graph(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
    }
    
    vector<int> boyMatch(n + 1, 0);
    vector<int> girlMatch(m + 1, 0);
    
    int maxPairs = 0;
    vector<pair<int, int>> pairs;
    
    for (int boy = 1; boy <= n; boy++) {
        for (int girl = 1; girl <= m; girl++) {
            if (graph[boy][girl] && !boyMatch[boy] && !girlMatch[girl]) {
                boyMatch[boy] = girl;
                girlMatch[girl] = boy;
                maxPairs++;
                pairs.push_back({boy, girl});
            }
        }
    }
    
    cout << maxPairs << endl;
    for (auto& p : pairs) {
        cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}