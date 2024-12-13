#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    string s;
    cin >> s;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        reverse(s.begin() + a - 1, s.begin() + b);
    }
    
    cout << s << endl;
    
    return 0;
}