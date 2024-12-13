#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    string s;
    cin >> s;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        string cut = s.substr(a-1, b-a+1);
        s.erase(a-1, b-a+1);
        s += cut;
    }
    
    cout << s << endl;
    
    return 0;
}