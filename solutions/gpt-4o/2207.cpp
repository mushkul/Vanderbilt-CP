#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n % 2 == 1) cout << "second" << endl;
        else cout << "first" << endl;
    }
    return 0;
}