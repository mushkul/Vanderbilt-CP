#include <iostream>
#include <iomanip>
#include <vector>
#define N 8
#define MAX 100 + 5

double dp[N][N][MAX], ans[N][N];
 
int main() {
    int k;
    std::cin >> k;
  
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            dp[i][j][0] = 1;
        }
    }
 
    for(int s = 1; s <= k; s++) {
        for(int x = 0; x < N; x++) {
            for(int y = 0; y < N; y++) {
                double a = 0;
                if(x > 0) a += dp[x-1][y][s-1];
                if(x < N - 1) a += dp[x+1][y][s-1];
                if(y > 0) a += dp[x][y-1][s-1];
                if(y < N - 1) a += dp[x][y+1][s-1];
                dp[x][y][s] = a / 4;
            }
        }
    }
  
  double res = 0;
  for(int x = 0; x < N; x++) {
      for(int y = 0; y < N; y++) {
          res += 1 - dp[x][y][k];
      }
  }
  std::cout << std::fixed << std::setprecision(6) << res << "\n";
  return 0;
}