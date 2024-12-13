#include <bits/stdc++.h>
using namespace std;

double p[8][8][101][8][8];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool valid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int main() {
    int k;
    cin >> k;
    
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            p[i][j][0][i][j] = 1;
        }
    }
    
    for(int step = 0; step < k; step++) {
        for(int x1 = 0; x1 < 8; x1++) {
            for(int y1 = 0; y1 < 8; y1++) {
                for(int x2 = 0; x2 < 8; x2++) {
                    for(int y2 = 0; y2 < 8; y2++) {
                        if(p[x1][y1][step][x2][y2] > 0) {
                            int valid_moves = 0;
                            for(int d = 0; d < 4; d++) {
                                int nx = x2 + dx[d];
                                int ny = y2 + dy[d];
                                if(valid(nx, ny)) valid_moves++;
                            }
                            
                            for(int d = 0; d < 4; d++) {
                                int nx = x2 + dx[d];
                                int ny = y2 + dy[d];
                                if(valid(nx, ny)) {
                                    p[x1][y1][step+1][nx][ny] += p[x1][y1][step][x2][y2] / valid_moves;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    double ans = 64;
    for(int x = 0; x < 8; x++) {
        for(int y = 0; y < 8; y++) {
            double prob = 1;
            for(int x1 = 0; x1 < 8; x1++) {
                for(int y1 = 0; y1 < 8; y1++) {
                    double sum = 0;
                    for(int x2 = 0; x2 < 8; x2++) {
                        for(int y2 = 0; y2 < 8; y2++) {
                            if(x2 == x && y2 == y) {
                                sum += p[x1][y1][k][x2][y2];
                            }
                        }
                    }
                    prob *= (1-sum);
                }
            }
            ans -= prob;
        }
    }
    
    cout << fixed << setprecision(6) << ans << endl;
    
    return 0;
}