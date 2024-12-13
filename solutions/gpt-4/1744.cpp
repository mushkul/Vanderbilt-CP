#include<bits/stdc++.h>
#define MAX 505
#define INF 1000000007
using namespace std;

int dp[MAX][MAX];

int cut(int a, int b) {
    if(a == b) return 0;
    if(dp[a][b] != INF) return dp[a][b];
    for(int i=1; i<a; i++)
        dp[a][b] = min(dp[a][b], cut(i, b) + cut(a-i, b) + 1);
    for(int i=1; i<b; i++)
        dp[a][b] = min(dp[a][b], cut(a, i) + cut(a, b-i) + 1);
    return dp[a][b];
}

int main() {
    int a, b;
    cin >> a >> b;
    for(int i=0; i<=a; i++)
        for(int j=0; j<=b; j++)
            dp[i][j] = INF;
    cout << cut(a, b);
    return 0;
}