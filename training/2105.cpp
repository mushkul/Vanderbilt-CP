#include <bits/stdc++.h>

struct SuffixAutomaton {
    struct Node {
        int length, link;
        std::vector<int> next;
        Node(): length(0), link(-1), next(26, -1) {}
    };

    std::vector<Node> automaton;
    int last;

    SuffixAutomaton(const std::string &s) {
        automaton.push_back(Node());
        last = 0;

        for (char c : s) {
            add_character(c - 'a');
        }
    }

    void add_character(int c) {
        int current = automaton.size();
        automaton.push_back(Node());
        automaton[current].length = automaton[last].length + 1;

        int p = last;
        while (p != -1 && automaton[p].next[c] == -1) {
            automaton[p].next[c] = current;
            p = automaton[p].link;
        }

        if (p == -1) {
            automaton[current].link = 0;
        } else {
            int q = automaton[p].next[c];
            if (automaton[p].length + 1 == automaton[q].length) {
                automaton[current].link = q;
            } else {
                int clone = automaton.size();
                automaton.push_back(Node());
                automaton[clone].length = automaton[p].length + 1;
                automaton[clone].next = automaton[q].next;
                automaton[clone].link = automaton[q].link;
                while (p != -1 && automaton[p].next[c] == q) {
                    automaton[p].next[c] = clone;
                    p = automaton[p].link;
                }
                automaton[q].link = automaton[current].link = clone;
            }
        }
        last = current;
    }

    long long count_distinct_substrings() {
        long long count = 0;
        for (size_t i = 1; i < automaton.size(); ++i) {
            count += automaton[i].length - automaton[automaton[i].link].length;
        }
        return count;
    }
};

int main() {
    std::string s;
    std::cin >> s;
    SuffixAutomaton sa(s);
    std::cout << sa.count_distinct_substrings() << std::endl;
    return 0;
}