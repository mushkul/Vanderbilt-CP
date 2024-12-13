#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;
const int MAXN = 100;

ll matrixMul(ll a[MAXN][MAXN], ll b[MAXN][MAXN], int n) {
    ll res[MAXN][MAXN] = {0};
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = res[i][j];
}

void matrixExpo(ll matrix[MAXN][MAXN], int exp, int n) {
    ll result[MAXN][MAXN] = {0};
    for (int i = 0; i < n; i++) result[i][i] = 1;
    while (exp > 0) {
        if (exp % 2) matrixMul(result, matrix, n);
        matrixMul(matrix, matrix, n);
        exp /= 2;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = result[i][j];
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    ll graph[MAXN][MAXN] = {0};
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1][b-1]++;
    }
    matrixExpo(graph, k, n);
    cout << graph[0][n-1] << endl;
    return 0;
}