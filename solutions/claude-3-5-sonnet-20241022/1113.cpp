#include <bits/stdc++.h>
using namespace std;

string process(string s) {
    int n = s.length();
    vector<int> p(n), c(n);
    
    vector<pair<char,int>> a(n);
    for(int i = 0; i < n; i++) a[i] = {s[i], i};
    sort(a.begin(), a.end());
    
    for(int i = 0; i < n; i++) p[i] = a[i].second;
    c[p[0]] = 0;
    for(int i = 1; i < n; i++) {
        if(a[i].first == a[i-1].first)
            c[p[i]] = c[p[i-1]];
        else
            c[p[i]] = c[p[i-1]] + 1;
    }
    
    int k = 0;
    while((1 << k) < n) {
        vector<pair<pair<int,int>, int>> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i = 1; i < n; i++) {
            if(a[i].first == a[i-1].first)
                c[p[i]] = c[p[i-1]];
            else 
                c[p[i]] = c[p[i-1]] + 1;
        }
        k++;
    }
    
    string res;
    for(int i = 0; i < n; i++) {
        int j = (p[i] - 1 + n) % n;
        res += s[j];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    cout << process(s) << "\n";
    return 0;
}