#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
const int MAXN = 5001;
 
struct TrieNode {
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode() {
        children.resize(26, nullptr);
        isEnd = false;
    }
};
 
void insert(TrieNode* root, string& word) {
    TrieNode* curr = root;
    for(char c : word) {
        int idx = c - 'a';
        if(curr->children[idx] == nullptr) {
            curr->children[idx] = new TrieNode();
        }
        curr = curr->children[idx];
    }
    curr->isEnd = true;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    int k;
    cin >> k;
    
    TrieNode* root = new TrieNode();
    for(int i = 0; i < k; i++) {
        string word;
        cin >> word;
        insert(root, word);
    }
    
    int n = s.length();
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    
    for(int i = 0; i < n; i++) {
        TrieNode* curr = root;
        for(int j = i; j < n; j++) {
            int idx = s[j] - 'a';
            if(curr->children[idx] == nullptr) break;
            curr = curr->children[idx];
            if(curr->isEnd) {
                dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
            }
        }
    }
    
    cout << dp[n] << '\n';
    
    return 0;
}