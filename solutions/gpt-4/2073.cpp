#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    int n, m;
    string s;
    cin >> n >> m >> s;
    while(m--) {
        int a, b;
        cin >> a >> b;
        reverse(s.begin() + a - 1, s.begin() + b);
    }
    cout << s << "\n";
    return 0;
}