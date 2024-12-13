#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<long long>> matrix_multiply(vector<vector<long long>>& a, vector<vector<long long>>& b) {
    vector<vector<long long>> result(2, vector<long long>(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return result;
}

vector<vector<long long>> matrix_power(vector<vector<long long>> matrix, long long n) {
    vector<vector<long long>> result = {{1, 0}, {0, 1}};
    while (n > 0) {
        if (n % 2) {
            result = matrix_multiply(result, matrix);
        }
        matrix = matrix_multiply(matrix, matrix);
        n /= 2;
    }
    return result;
}

long long fibonacci(long long n) {
    if (n <= 1) return n;
    
    vector<vector<long long>> base = {{1, 1}, {1, 0}};
    vector<vector<long long>> result = matrix_power(base, n - 1);
    
    return result[0][0];
}

int main() {
    long long n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}