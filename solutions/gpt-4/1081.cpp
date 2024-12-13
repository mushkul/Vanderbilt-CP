#include<bits/stdc++.h>
using namespace std;
#define maxn 1000005
int cnt[maxn];
vector<int> multiple[maxn];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int maxnum = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        maxnum = max(maxnum, x);
        cnt[x]++;
        for(int j : multiple[x]) {
            cnt[j]++;
        }
        multiple[x].push_back(x);
    }
    for(int i = maxnum; i; --i) {
        if (cnt[i] >= 2) {
            cout << i;
            return 0;
        }
    }
    return 0;
}