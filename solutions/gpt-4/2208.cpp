#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n, 0);
        for(int i=0; i<n; ++i){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int counter = 0;
        for(int i=0; i<n; ++i){
            if(a[i] == 1) counter++;
            else break;
        }
        if(counter % 2 == 0) cout << "first\n";
        else cout << "second\n";
    }
    return 0;
}