#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool inside(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int main() {
    int k;
    cin >> k;
    
    long double result = 0.0;
    
    for (int x1 = 0; x1 < 8; x1++) {
        for (int y1 = 0; y1 < 8; y1++) {
            for (int x2 = 0; x2 < 8; x2++) {
                for (int y2 = 0; y2 < 8; y2++) {
                    vector<vector<long double>> dp(8, vector<long double>(8, 1.0));
                    
                    for (int turn = 0; turn < k; turn++) {
                        vector<vector<long double>> newDp(8, vector<long double>(8, 0.0));
                        
                        for (int x = 0; x < 8; x++) {
                            for (int y = 0; y < 8; y++) {
                                int validMoves = 0;
                                
                                for (int dir = 0; dir < 4; dir++) {
                                    int nx = x + dx[dir];
                                    int ny = y + dy[dir];
                                    
                                    if (inside(nx, ny)) {
                                        validMoves++;
                                    }
                                }
                                
                                for (int dir = 0; dir < 4; dir++) {
                                    int nx = x + dx[dir];
                                    int ny = y + dy[dir];
                                    
                                    if (inside(nx, ny)) {
                                        newDp[nx][ny] += dp[x][y] / validMoves;
                                    }
                                }
                            }
                        }
                        
                        dp = newDp;
                    }
                    
                    if (x1 == x2 && y1 == y2) {
                        result += 64.0 - accumulate(dp.begin(), dp.end(), 0.0, 
                            [](long double a, const vector<long double>& row) {
                                return a + 1.0 - accumulate(row.begin(), row.end(), 0.0);
                            });
                    }
                }
            }
        }
    }
    
    result /= 64.0 * 64.0;
    
    cout << fixed << setprecision(6) << result << endl;
    
    return 0;
}