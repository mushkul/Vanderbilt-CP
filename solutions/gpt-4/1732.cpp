#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> v(s.size());
    for (int i = 1, j = 0; i < s.size(); i++) {
        while (j > 0 && s[i] != s[j])
            j = v[j-1];
        if (s[i] == s[j])
            j++;
        v[i] = j;
    }

    stack<int> st;
    for (int i = v.back(); i > 0; i = v[i-1])
        st.push(i);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}