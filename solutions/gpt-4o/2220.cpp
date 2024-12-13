#include <iostream>
#include <cstring>

using namespace std;

long long dp[20][10][2];
string start, end;

long long solve(string& num, int pos, int prev_digit, bool tight) {
    if (pos == num.size()) return 1;
    if (dp[pos][prev_digit][tight] != -1) return dp[pos][prev_digit][tight];

    int limit = tight ? num[pos] - '0' : 9;
    long long result = 0;
    for (int digit = 0; digit <= limit; digit++) {
        if (digit != prev_digit) {
            result += solve(num, pos + 1, digit, tight && (digit == limit));
        }
    }
    return dp[pos][prev_digit][tight] = result;
}

long long countNumbers(long long x) {
    string num = to_string(x);
    memset(dp, -1, sizeof(dp));
    return solve(num, 0, 10, true);
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << countNumbers(b) - countNumbers(a - 1) << endl;
    return 0;
}