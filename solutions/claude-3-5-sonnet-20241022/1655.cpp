#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[2];
    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

void insert(TrieNode* root, int num) {
    TrieNode* curr = root;
    for(int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if(!curr->child[bit]) {
            curr->child[bit] = new TrieNode();
        }
        curr = curr->child[bit];
    }
}

int findMaxXor(TrieNode* root, int num) {
    TrieNode* curr = root;
    int maxNum = 0;
    for(int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if(curr->child[1-bit]) {
            maxNum |= (1 << i);
            curr = curr->child[1-bit];
        } else {
            curr = curr->child[bit];
        }
    }
    return maxNum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> prefix(n+1, 0);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        prefix[i+1] = prefix[i] ^ x;
    }
    
    TrieNode* root = new TrieNode();
    int maxXor = 0;
    
    for(int i = 0; i <= n; i++) {
        maxXor = max(maxXor, findMaxXor(root, prefix[i]));
        insert(root, prefix[i]);
    }
    
    cout << maxXor;
    return 0;
}