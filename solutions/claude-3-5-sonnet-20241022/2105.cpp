#include <bits/stdc++.h>
using namespace std;
 
struct SuffixArray {
    vector<int> sa, lcp;
    SuffixArray(string& s) {
        int n = s.length();
        sa.resize(n);
        vector<int> c(n), r(n);
        for(int i = 0; i < n; i++) sa[i] = i;
        for(int i = 0; i < n; i++) c[i] = s[i];
        
        for(int k = 0; k < n; k ? k *= 2 : k = 1) {
            r = c;
            c.resize(n);
            vector<int> cnt(max(n, 256)), pos(n);
            for(int i = 0; i < n; i++) cnt[r[i]]++;
            for(int i = 1; i < cnt.size(); i++) cnt[i] += cnt[i-1];
            for(int i = n-1; i >= 0; i--) pos[--cnt[r[i]]] = i;
            
            cnt.assign(n, 0);
            for(int i = 0; i < n; i++) cnt[(i + k < n ? r[i + k] : 0)]++;
            for(int i = 1; i < n; i++) cnt[i] += cnt[i-1];
            
            vector<int> temp = sa;
            for(int i = n-1; i >= 0; i--) {
                int j = pos[i];
                temp[--cnt[(j + k < n ? r[j + k] : 0)]] = j;
            }
            sa = temp;
            
            c[sa[0]] = 0;
            for(int i = 1; i < n; i++) {
                pair<int,int> prev = {r[sa[i-1]], (sa[i-1] + k < n ? r[sa[i-1] + k] : 0)};
                pair<int,int> curr = {r[sa[i]], (sa[i] + k < n ? r[sa[i] + k] : 0)};
                c[sa[i]] = c[sa[i-1]] + (prev != curr);
            }
        }
        
        lcp.resize(n-1);
        for(int i = 0, k = 0; i < n-1; i++) {
            int pi = c[i];
            int j = sa[pi-1];
            while(s[i + k] == s[j + k]) k++;
            lcp[pi-1] = k;
            k = max(k-1, 0);
        }
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    SuffixArray sa(s);
    long long n = s.length();
    long long result = (n * (n + 1)) / 2;
    
    for(int i = 0; i < n-1; i++) {
        result -= sa.lcp[i];
    }
    
    cout << result << "\n";
    return 0;
}