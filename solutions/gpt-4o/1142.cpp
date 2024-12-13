#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    stack<int> st;
    int max_area = 0;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            max_area = max(max_area, h * width);
        }
        st.push(i);
    }

    while (!st.empty()) {
        int h = heights[st.top()];
        st.pop();
        int width = st.empty() ? n : n - st.top() - 1;
        max_area = max(max_area, h * width);
    }

    cout << max_area << endl;
    return 0;
}