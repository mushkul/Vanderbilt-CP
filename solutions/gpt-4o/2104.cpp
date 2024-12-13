#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct TrieNode {
    map<char, TrieNode*> children;
    int idx;
    TrieNode() : idx(-1) {}
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word, int index) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->idx = index;
    }

    void searchInText(const string& text, vector<int>& result) {
        for (int i = 0; i < text.size(); ++i) {
            TrieNode* node = root;
            for (int j = i; j < text.size(); ++j) {
                char c = text[j];
                if (!node->children.count(c)) break;
                node = node->children[c];
                if (node->idx != -1 && result[node->idx] == -1) {
                    result[node->idx] = i + 1;
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int k;
    cin >> k;

    vector<string> patterns(k);
    Trie trie;
    for (int i = 0; i < k; i++) {
        cin >> patterns[i];
        trie.insert(patterns[i], i);
    }

    vector<int> result(k, -1);
    trie.searchInText(s, result);

    for (int i = 0; i < k; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}