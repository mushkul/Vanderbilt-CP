#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    ll max_area = 0;
    stack<int> st;

    for (int i = 0; i <= n; i++) {
        ll height = (i == n) ? 0 : heights[i];

        while (!st.empty() && height < heights[st.top()]) {
            ll h = heights[st.top()];
            st.pop();
            ll w = st.empty() ? i : i - st.top() - 1;
            max_area = max(max_area, h * w);
        }
        st.push(i);
    }

    cout << max_area << endl;
    return 0;
}