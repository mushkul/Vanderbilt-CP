#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    string s;
    cin >> s;
    
    while(m--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        
        string cut = s.substr(l, r-l+1);
        s.erase(l, r-l+1);
        s += cut;
    }
    
    cout << s << endl;
    return 0;
}