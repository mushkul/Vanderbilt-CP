#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TrieNode {
    TrieNode* children[2];
    TrieNode() : children{nullptr, nullptr} {}
};

class Trie {
public:
    Trie() : root(new TrieNode()) {}
    
    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }
    
    int query(int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->children[1 - bit]) {
                maxXor |= (1 << i);
                node = node->children[1 - bit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXor;
    }
    
private:
    TrieNode* root;
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    Trie trie;
    int maxXor = 0, prefixXor = 0;
    trie.insert(0);
    for (int num : nums) {
        prefixXor ^= num;
        maxXor = max(maxXor, trie.query(prefixXor));
        trie.insert(prefixXor);
    }
    
    cout << maxXor << endl;
    return 0;
}