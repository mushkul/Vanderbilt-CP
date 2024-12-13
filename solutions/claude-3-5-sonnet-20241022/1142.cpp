#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> left(n), right(n);
    stack<int> st;
    
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    
    while(!st.empty()) st.pop();
    
    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, a[i] * (right[i] - left[i] - 1));
    }
    
    cout << ans << '\n';
    
    return 0;
}