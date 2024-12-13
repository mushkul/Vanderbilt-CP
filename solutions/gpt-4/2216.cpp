#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n+1);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        p[a] = i;
    }
    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        if (p[i-1] > p[i]) 
            rounds++;
    }
    cout << rounds;
    return 0;
}