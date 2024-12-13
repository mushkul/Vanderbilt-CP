#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PalindromeQueries {
private:
    string s;
    
    bool isPalindrome(int a, int b) {
        while (a < b) {
            if (s[a-1] != s[b-1]) return false;
            a++;
            b--;
        }
        return true;
    }

public:
    void solve() {
        int n, m;
        cin >> n >> m;
        cin >> s;

        while (m--) {
            int type;
            cin >> type;

            if (type == 1) {
                int k;
                char x;
                cin >> k >> x;
                s[k-1] = x;
            } else {
                int a, b;
                cin >> a >> b;
                cout << (isPalindrome(a, b) ? "YES" : "NO") << endl;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    PalindromeQueries pq;
    pq.solve();
    
    return 0;
}