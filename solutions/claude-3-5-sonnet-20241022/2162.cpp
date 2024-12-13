#include <iostream>
#include <queue>

int main() {
    int n;
    std::cin >> n;
    
    std::queue<int> q;
    for(int i = 1; i <= n; i++) {
        q.push(i);
    }
    
    bool skip = true;
    while(!q.empty()) {
        if(skip) {
            q.push(q.front());
        } else {
            std::cout << q.front() << " ";
        }
        q.pop();
        skip = !skip;
    }
    
    return 0;
}