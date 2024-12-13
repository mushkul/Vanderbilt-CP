#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 2e5 + 5;
int n, q;
int price[MAXN];
int left_dist[MAXN];
int right_dist[MAXN];
 
void update_left() {
    left_dist[1] = price[1];
    for (int i = 2; i <= n; i++) {
        left_dist[i] = min(price[i] + i, left_dist[i-1] - 1);
    }
}
 
void update_right() {
    right_dist[n] = price[n];
    for (int i = n-1; i >= 1; i--) {
        right_dist[i] = min(price[i] - i, right_dist[i+1] - 1);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }
 
    update_left();
    update_right();
 
    while (q--) {
        int type;
        cin >> type;
 
        if (type == 1) {
            int k, x;
            cin >> k >> x;
            price[k] = x;
            update_left();
            update_right();
        } else {
            int k;
            cin >> k;
            int ans = min(left_dist[k] - k, right_dist[k] + k);
            cout << ans << '\n';
        }
    }
 
    return 0;
}