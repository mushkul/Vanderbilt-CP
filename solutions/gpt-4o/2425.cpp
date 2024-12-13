#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int leftMax = 0, rightMax = 0;
    for (int i = 0; i < n; ++i) {
        int c, s;
        cin >> c >> s;
        
        if (s == 1) {
            leftMax = max(leftMax, c);
        } else {
            rightMax = max(rightMax, c);
        }
        
        if (leftMax > rightMax) {
            cout << ">" << endl;
        } else if (rightMax > leftMax) {
            cout << "<" << endl;
        } else {
            cout << "?" << endl;
        }
    }
    
    return 0;
}