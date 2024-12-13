#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int size;
    vector<string> value;
    
    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        value.assign(2 * size, "");
    }
    
    void build(const string &s, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)s.size()) {
                value[x] = s[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(s, 2 * x + 1, lx, m);
        build(s, 2 * x + 2, m, rx);
        value[x] = value[2 * x + 1] + value[2 * x + 2];
    }
    
    void build(const string &s) {
        init(s.size());
        build(s, 0, 0, size);
    }

    void set(int i, char v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            value[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        } else {
            set(i, v, 2 * x + 2, m, rx);
        }
        value[x] = value[2 * x + 1] + value[2 * x + 2];
    }
    
    void set(int i, char v) {
        set(i, v, 0, 0, size);
    }
    
    string get(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return "";
        if (lx >= l && rx <= r) return value[x];
        int m = (lx + rx) / 2;
        string left_part = get(l, r, 2 * x + 1, lx, m);
        string right_part = get(l, r, 2 * x + 2, m, rx);
        return left_part + right_part;
    }
    
    string get(int l, int r) {
        return get(l, r, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    
    SegmentTree segTree;
    segTree.build(s);
    
    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k;
            char x;
            cin >> k >> x;
            segTree.set(k - 1, x);
        } else if (type == 2) {
            int a, b;
            cin >> a >> b;
            string substring = segTree.get(a - 1, b);
            string reversed_substring = substring;
            reverse(reversed_substring.begin(), reversed_substring.end());
            if (substring == reversed_substring) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    
    return 0;
}