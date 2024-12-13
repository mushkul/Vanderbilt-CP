#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    vector<int> result(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        
        result[i] = st.empty() ? 0 : st.top() + 1;
        st.push(i);
    }
    
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}