#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    s += s;
    int n = s.size();
    vector<int> f(n, -1);
    int k = 0;
    for(int j = 1; j < n; j++) {
        int i = f[j-k-1];
        while(i != -1 && s[j] != s[k+i+1]) {
            if(s[j] < s[k+i+1]) {
                k = j - i - 1;
            }
            i = f[i];
        }
        if(s[j] != s[k+i+1]) {
            if(s[j] < s[k]) {
                k = j;
            }
            f[j-k] = -1;
        } else {
            f[j-k] = i+1;
        }
    }
    cout << s.substr(k, n/2) << "\n";
    return 0;
}