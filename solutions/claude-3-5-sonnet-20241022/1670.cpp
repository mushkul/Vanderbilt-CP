#include <bits/stdc++.h>
using namespace std;

const int N = 3;
const string target = "123456789";
int grid[N][N];
map<string, int> dist;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

string get_state() {
    string s = "";
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            s += (char)(grid[i][j] + '0');
    return s;
}

int bfs() {
    queue<string> q;
    string start = get_state();
    dist[start] = 0;
    q.push(start);
    
    while(!q.empty()) {
        string curr = q.front();
        q.pop();
        
        if(curr == target) return dist[curr];
        
        int pos = 0;
        int board[N][N];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                board[i][j] = curr[pos++] - '0';
                
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                for(int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    
                    if(ni >= 0 && ni < N && nj >= 0 && nj < N) {
                        string next = curr;
                        int pos1 = i*N + j;
                        int pos2 = ni*N + nj;
                        swap(next[pos1], next[pos2]);
                        
                        if(!dist.count(next)) {
                            dist[next] = dist[curr] + 1;
                            q.push(next);
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> grid[i][j];
            
    cout << bfs() << endl;
    return 0;
}