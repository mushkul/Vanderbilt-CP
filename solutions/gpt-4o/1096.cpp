#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<long long>> multiply(const vector<vector<long long>>& a, const vector<vector<long long>>& b) {
    vector<vector<long long>> res(6, vector<long long>(6, 0));
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            for (int k = 0; k < 6; ++k) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return res;
}

vector<vector<long long>> matrixExpo(vector<vector<long long>> base, long long exp) {
    vector<vector<long long>> result(6, vector<long long>(6, 0));
    for (int i = 0; i < 6; ++i) result[i][i] = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        exp /= 2;
    }
    return result;
}

int main() {
    long long n;
    cin >> n;

    if (n <= 6) {
        long long baseCases[] = {0, 1, 2, 4, 8, 16, 32};
        cout << baseCases[n] << endl;
        return 0;
    }

    vector<vector<long long>> transition = {
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0}
    };

    vector<vector<long long>> result = matrixExpo(transition, n - 6);

    vector<long long> initialCases = {32, 16, 8, 4, 2, 1};

    long long totalWays = 0;

    for (int i = 0; i < 6; ++i) {
        totalWays = (totalWays + result[0][i] * initialCases[i]) % MOD;
    }

    cout << totalWays << endl;
    return 0;
}