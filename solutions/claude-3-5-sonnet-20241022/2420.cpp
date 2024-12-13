#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    string s;
    cin >> s;
    
    while(m--) {
        int type;
        cin >> type;
        
        if(type == 1) {
            int k;
            char x;
            cin >> k >> x;
            s[k-1] = x;
        }
        else {
            int a, b;
            cin >> a >> b;
            a--; b--;
            
            bool isPalindrome = true;
            while(a < b) {
                if(s[a] != s[b]) {
                    isPalindrome = false;
                    break;
                }
                a++;
                b--;
            }
            cout << (isPalindrome ? "YES\n" : "NO\n");
        }
    }
    
    return 0;
}