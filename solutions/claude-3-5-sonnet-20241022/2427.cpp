#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<pair<int,int>> moves;

bool check(string& t) {
    int na = 0, nb = 0;
    for(char c : t) {
        if(c == 'A') na++;
        if(c == 'B') nb++;
    }
    return na == n-1 && nb == n-1;
}

bool isSorted(string& t) {
    bool sawB = false;
    for(char c : t) {
        if(c == 'B') sawB = true;
        if(sawB && c == 'A') return false;
    }
    return true;
}

bool solve() {
    if(!check(s)) return false;
    
    while(!isSorted(s)) {
        if(moves.size() > 10*n) return false;
        
        bool found = false;
        for(int i = 0; i < 2*n-1; i++) {
            if(s[i] == 'B' && s[i+1] == 'A') {
                // Find closest empty pair
                int j;
                for(j = 0; j < 2*n-1; j++) {
                    if(s[j] == '.' && s[j+1] == '.') break;
                }
                
                moves.push_back({i,j});
                swap(s[i], s[j]);
                swap(s[i+1], s[j+1]);
                found = true;
                break;
            }
        }
        if(!found) break;
    }
    
    return isSorted(s);
}

int main() {
    cin >> n;
    cin >> s;
    
    if(solve()) {
        cout << moves.size() << "\n";
        for(auto m : moves) {
            cout << m.first+1 << " " << m.second+1 << "\n";
        }
    } else {
        cout << "-1\n";
    }
    
    return 0;
}