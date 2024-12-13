#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    vector<bool> A(s.length() + 1, false);
    vector<bool> C(s.length() + 1, false);
    vector<bool> G(s.length() + 1, false);
    vector<bool> T(s.length() + 1, false);
    
    A[s.length()] = C[s.length()] = G[s.length()] = T[s.length()] = true;
    
    for(int i = s.length() - 1; i >= 0; i--) {
        A[i] = A[i + 1];
        C[i] = C[i + 1];
        G[i] = G[i + 1];
        T[i] = T[i + 1];
        
        if(s[i] == 'A') A[i] = true;
        if(s[i] == 'C') C[i] = true;
        if(s[i] == 'G') G[i] = true;
        if(s[i] == 'T') T[i] = true;
    }
    
    if(!A[0]) { cout << "A\n"; return 0; }
    if(!C[0]) { cout << "C\n"; return 0; }
    if(!G[0]) { cout << "G\n"; return 0; }
    if(!T[0]) { cout << "T\n"; return 0; }
    
    for(int i = 0; i < s.length(); i++) {
        if(!A[i+1]) { cout << "A" << s[i] << "\n"; return 0; }
        if(!C[i+1]) { cout << "C" << s[i] << "\n"; return 0; }
        if(!G[i+1]) { cout << "G" << s[i] << "\n"; return 0; }
        if(!T[i+1]) { cout << "T" << s[i] << "\n"; return 0; }
    }
    
    cout << "AA\n";
    
    return 0;
}