#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 101;

class Matrix {
public:
    vector<vector<ll>> mat;
    int n;

    Matrix(int size) {
        n = size;
        mat.resize(n, vector<ll>(n, 0));
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    result.mat[i][j] = (result.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return result;
    }
};

Matrix matrix_power(Matrix base, ll k) {
    int n = base.n;
    Matrix result(n);
    for (int i = 0; i < n; i++) result.mat[i][i] = 1;

    while (k > 0) {
        if (k & 1) result = result * base;
        base = base * base;
        k >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    Matrix adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj.mat[a - 1][b - 1]++;
    }

    Matrix result = matrix_power(adj, k);
    cout << result.mat[0][n - 1] << endl;

    return 0;
}