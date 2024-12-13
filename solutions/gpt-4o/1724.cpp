#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;
int n, m, k;
vector<vector<pair<int, int>>> adj;

struct Matrix {
    vector<vector<long long>> mat;
    int sz;

    Matrix(int n) : sz(n) {
        mat.assign(n, vector<long long>(n, INF));
        for (int i = 0; i < n; i++) mat[i][i] = 0;
    }
    
    Matrix operator* (const Matrix &o) const {
        Matrix res(sz);
        for (int i = 0; i < sz; i++) 
            for (int j = 0; j < sz; j++) 
                for (int k = 0; k < sz; k++)
                    res.mat[i][j] = min(res.mat[i][j], mat[i][k] + o.mat[k][j]);
        return res;
    }
};

Matrix power(Matrix base, int exp) {
    Matrix res(n);
    while (exp > 0) {
        if (exp % 2) res = res * base;
        base = base * base;
        exp /= 2;
    }
    return res;
}

int main() {
    cin >> n >> m >> k;
    adj.resize(n);
    Matrix mat(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        mat.mat[a][b] = min(mat.mat[a][b], (long long)c);
    }
    
    Matrix result = power(mat, k);
    long long answer = result.mat[0][n-1];
    if (answer >= INF) answer = -1;
    cout << answer << endl;
    return 0;
}