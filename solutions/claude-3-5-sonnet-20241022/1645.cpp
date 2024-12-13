#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    stack<pair<int,int>> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && st.top().first >= a[i]) {
            st.pop();
        }
        if(st.empty()) {
            cout << "0 ";
        } else {
            cout << st.top().second + 1 << " ";
        }
        st.push({a[i], i});
    }
    
    return 0;
}