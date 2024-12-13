#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
private:
    vector<int> tree;
public:
    FenwickTree(int n) : tree(n + 1, 0) {}

    void update(int idx, int val) {
        while (idx < tree.size()) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    int rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> salaries(n + 1);
    set<int> uniqueSalaries;
    
    for (int i = 1; i <= n; i++) {
        cin >> salaries[i];
        uniqueSalaries.insert(salaries[i]);
    }

    vector<pair<char, array<int, 3>>> queries(q);
    for (int i = 0; i < q; i++) {
        char type;
        cin >> type;
        if (type == '!') {
            int k, x;
            cin >> k >> x;
            queries[i] = {type, {k, x, 0}};
            uniqueSalaries.insert(x);
        } else {
            int a, b;
            cin >> a >> b;
            queries[i] = {type, {a, b, 0}};
            uniqueSalaries.insert(a);
            uniqueSalaries.insert(b);
        }
    }

    map<int, int> salaryToIndex;
    int index = 1;
    for (int salary : uniqueSalaries) {
        salaryToIndex[salary] = index++;
    }

    FenwickTree ft(salaryToIndex.size());
    
    for (int i = 1; i <= n; i++) {
        ft.update(salaryToIndex[salaries[i]], 1);
    }

    for (auto& [type, params] : queries) {
        if (type == '!') {
            int k = params[0], x = params[1];
            ft.update(salaryToIndex[salaries[k]], -1);
            salaries[k] = x;
            ft.update(salaryToIndex[x], 1);
        } else {
            int a = params[0], b = params[1];
            cout << ft.rangeQuery(salaryToIndex[a], salaryToIndex[b]) << '\n';
        }
    }

    return 0;
}