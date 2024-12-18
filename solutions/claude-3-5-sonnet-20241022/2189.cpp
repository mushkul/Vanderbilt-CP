#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        ll x1,y1,x2,y2,x3,y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        
        ll cross = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);
        
        if(cross > 0) cout << "LEFT\n";
        else if(cross < 0) cout << "RIGHT\n"; 
        else cout << "TOUCH\n";
    }
    
    return 0;
}