#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct State {
    vector<int> board;
    int zero_pos;
    State(vector<int> b, int z) : board(b), zero_pos(z) {}
};

int solve(vector<int>& start, vector<int>& goal) {
    vector<vector<int>> neighbour = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4, 6}, {1, 3, 5, 7}, {2, 4, 8}, {3, 7}, {4, 6, 8}, {5, 7}};
    string start_s(start.begin(), start.end());
    string goal_s(goal.begin(), goal.end());
    
    unordered_map<string, int> visited;
    queue<State> q;
    q.push(State(start, find(start.begin(), start.end(), 0) - start.begin()));
    visited[start_s] = 0;
    
    while (!q.empty()) {
        State current = q.front();
        q.pop();
        
        string current_s(current.board.begin(), current.board.end());
        
        if (current_s == goal_s) {
            return visited[current_s];
        }
        
        int z = current.zero_pos;
        for (int n : neighbour[z]) {
            vector<int> new_board = current.board;
            swap(new_board[z], new_board[n]);
            string new_s(new_board.begin(), new_board.end());
            if (!visited.count(new_s)) {
                visited[new_s] = visited[current_s] + 1;
                q.push(State(new_board, n));
            }
        }
    }
    return -1;
}

int main() {
    vector<int> start(9), goal = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 9; i++) {
        cin >> start[i];
    }
    cout << solve(start, goal) << endl;
    return 0;
}