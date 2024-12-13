#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5, MD = 20;
int lift[MAXN][MD], dep[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    for (int i = 2; i <= N; i++) {
        cin >> lift[i][0];
        dep[i] = dep[lift[i][0]] + 1;
        for (int j = 1; j < MD; j++)
            lift[i][j] = lift[lift[i][j - 1]][j - 1];
    }

    for (int q = 0, x, k; q < Q; q++) {
        cin >> x >> k;
        if (dep[x] < k) {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i < MD; i++)
            if (k & (1 << i))
                x = lift[x][i];
        cout << x << "\n";
    }

    return 0;
}