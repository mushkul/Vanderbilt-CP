#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    string s;
    int k;
    cin >> s >> k;

    unordered_set<string> wordDict;
    for (int i = 0; i < k; ++i) {
        string word;
        cin >> word;
        wordDict.insert(word);
    }

    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = i; j > 0; --j) {
            if (wordDict.find(s.substr(j - 1, i - j + 1)) != wordDict.end()) {
                dp[i] = (dp[i] + dp[j - 1]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}