#include<bits/stdc++.h>
using namespace std;

int n, a[200010], b[200010], temp[200010], ans1, ans2, ans3, ans4;
set<int> s;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[a[i]] = i;
    }
    for(int i = n; i >= 1; i--)
        temp[i] = temp[i + 1] + (b[i] < b[i + 1]);
    for(int i = 1; i <= n; i++)
        ans1 += abs(a[i] - i), ans2 = max(ans2, b[i] - 1), ans4 = max(ans4, a[i] - i), ans3 = max(ans3, ++temp[a[i]]);
    printf("%d %d %d %d\n", ans1, n - ans3, n - ans4 - 1, n - ans2 - 1);
    return 0;
}