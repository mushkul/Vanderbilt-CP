#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    vector<vector<int>> heights(n, vector<int>(m));
    
    for(int j = 0; j < m; j++) {
        int curr = 0;
        for(int i = 0; i < n; i++) {
            if(grid[i][j] == '*') {
                curr = 0;
            } else {
                curr++;
            }
            heights[i][j] = curr;
        }
    }
    
    ll maxArea = 0;
    for(int i = 0; i < n; i++) {
        stack<int> st;
        vector<int> left(m), right(m);
        
        for(int j = 0; j < m; j++) {
            while(!st.empty() && heights[i][st.top()] >= heights[i][j]) {
                st.pop();
            }
            left[j] = st.empty() ? 0 : st.top() + 1;
            st.push(j);
        }
        
        while(!st.empty()) st.pop();
        
        for(int j = m-1; j >= 0; j--) {
            while(!st.empty() && heights[i][st.top()] >= heights[i][j]) {
                st.pop();
            }
            right[j] = st.empty() ? m-1 : st.top() - 1;
            st.push(j);
        }
        
        for(int j = 0; j < m; j++) {
            maxArea = max(maxArea, (ll)heights[i][j] * (right[j] - left[j] + 1));
        }
    }
    
    cout << maxArea << endl;
    return 0;
}