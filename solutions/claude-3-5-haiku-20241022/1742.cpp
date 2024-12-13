#include <iostream>
#include <set>
#include <utility>

int main() {
    int n;
    std::cin >> n;
    
    int x = 0, y = 0, total_dist = 0;
    std::set<std::pair<int, int>> visited;
    visited.insert({0, 0});
    
    for (int i = 0; i < n; i++) {
        char dir;
        int dist;
        std::cin >> dir >> dist;
        
        for (int j = 0; j < dist; j++) {
            if (dir == 'U') y++;
            else if (dir == 'D') y--;
            else if (dir == 'R') x++;
            else if (dir == 'L') x--;
            
            if (visited.count({x, y}) > 0) {
                std::cout << total_dist << std::endl;
                return 0;
            }
            
            visited.insert({x, y});
            total_dist++;
        }
    }
    
    std::cout << total_dist << std::endl;
    return 0;
}