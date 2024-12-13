#include <bits/stdc++.h>
using namespace std;
 
int n;
int a[200001], pos[200001];
 
int method1() {
    int cnt = 0;
    vector<int> b(a+1, a+n+1);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<n; j++) {
            if(b[j] > b[j+1]) {
                swap(b[j], b[j+1]);
                cnt++;
            }
        }
    }
    return cnt;
}
 
int method2() {
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        if(pos[i] != i) {
            cnt++;
            int j = pos[i];
            pos[a[i]] = j;
            swap(a[i], a[j]);
        }
    }
    return cnt;
}
 
int method3() {
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        if(pos[i] != i) {
            cnt++;
            int j = pos[i];
            pos[a[i]] = pos[i];
            a[pos[i]] = a[i];
            pos[i] = i;
            a[i] = i;
        }
    }
    return cnt;
}
 
int method4() {
    vector<bool> vis(n+1);
    int cnt = 0;
    for(int i=n; i>=1; i--) {
        if(!vis[i]) {
            int j = i;
            while(!vis[j]) {
                vis[j] = true;
                j = pos[j];
            }
            if(j != i) cnt++;
        }
    }
    return n - cnt;
}
 
int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    cout << method1() << " ";
    cout << method2() << " ";
    cout << method3() << " ";
    cout << method4() << endl;
    return 0;
}