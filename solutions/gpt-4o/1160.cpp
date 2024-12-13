#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q;
    std::cin >> n >> q;
    std::vector<int> teleporters(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> teleporters[i];
    }

    std::vector<int> distance(n + 1, -1);
    std::vector<int> cycleIdx(n + 1, -1);
    std::vector<int> cycleLength(n + 1, 0);
    std::vector<int> inCycle(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        if (distance[i] == -1) {
            std::unordered_map<int, int> visited;
            int curr = i, dist = 0;
            while (visited.find(curr) == visited.end() && distance[curr] == -1) {
                visited[curr] = dist++;
                curr = teleporters[curr];
            }

            if (distance[curr] == -1) {
                int startCycle = curr;
                int cycleSize = dist - visited[curr];
                curr = i;
                while (visited[curr] >= visited[startCycle]) {
                    inCycle[curr] = 1;
                    distance[curr] = 0;
                    cycleIdx[curr] = startCycle;
                    cycleLength[curr] = cycleSize;
                    curr = teleporters[curr];
                }
            }

            for (auto &[planet, distFromStart] : visited) {
                if (distance[planet] == -1) {
                    if (inCycle[teleporters[planet]]) {
                        distance[planet] = (distFromStart + 1);
                        cycleIdx[planet] = cycleIdx[teleporters[planet]];
                        cycleLength[planet] = cycleLength[teleporters[planet]];
                    }
                    else {
                        distance[planet] = distance[teleporters[planet]] + 1;
                        cycleIdx[planet] = cycleIdx[teleporters[planet]];
                        cycleLength[planet] = cycleLength[teleporters[planet]];
                    }
                }
            }
        }
    }
    
    while (q--) {
        int a, b;
        std::cin >> a >> b;

        if (cycleIdx[a] == cycleIdx[b]) {
            if (!inCycle[a]) {
                int dist_a = distance[a];
                a = teleporters[a];
                while (!inCycle[a]) {
                    a = teleporters[a];
                }
                int cycleStart = a;
                int cycleEntrySteps = dist_a + 1;
                if (b == cycleStart) {
                    std::cout << cycleEntrySteps << "\n";
                } else {
                    int cyclePos_b = 0;
                    while (b != cycleStart) {
                        b = teleporters[b];
                        cyclePos_b++;
                    }
                    std::cout << cycleEntrySteps + cyclePos_b << "\n";
                }
            } else {
                int cyclePos_a = 0;
                while (a != cycleIdx[a]) {
                    a = teleporters[a];
                    cyclePos_a++;
                }
                int cyclePos_b = 0;
                while (b != cycleIdx[b]) {
                    b = teleporters[b];
                    cyclePos_b++;
                }
                if (cyclePos_a <= cyclePos_b) {
                    std::cout << cyclePos_b - cyclePos_a << "\n";
                } else {
                    std::cout << cycleLength[b] - (cyclePos_a - cyclePos_b) << "\n";
                }
            }
        } else {
            std::cout << -1 << "\n";
        }
    }

    return 0;
}