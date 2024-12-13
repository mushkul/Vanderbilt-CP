#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> p(n), c(n);
    {
        vector<pair<char, int>> a(n);
        for(int i = 0; i<n; i++)a[i] = {s[i], i};
        sort(a.begin(), a.end());
        for(int i = 0; i<n; i++)p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i = 1; i<n; i++){
            if(a[i].first == a[i-1].first){
                c[p[i]] = c[p[i-1]];
            } else{
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
    }
    int k = 0;
    while((1<<k) < n){
        vector<pair<pair<int, int>, int>>a(n);
        for(int i = 0; i<n; i++){
            a[i] = {{c[i], c[(i+(1<<k))%n]}, i};
        }
        sort(a.begin(), a.end());
        for(int i = 0; i<n; i++)p[i] = a[i].second;
        c[p[0]] = 0;
        for(int i = 1; i<n; i++){
            if(a[i].first == a[i-1].first){
                c[p[i]] = c[p[i-1]];
            } else{
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
        k++;
    }
    vector<int> lcp(n);
    k = 0;
    for(int i = 0; i<n-1; i++){
        int pi = c[i];
        int j = p[pi-1];
        while(s[i+k] == s[j+k])k++;
        lcp[pi] = k;
        k = max(k-1, 0);
    }
    long long ans = 0;
    for(int i = 1; i<n; i++){
        ans += n-p[i]-lcp[i];
    }
    for(int i = 1; i<=n; i++){
        cout<<ans+i<<" ";
        ans -= lcp[i];
    }
    return 0;
}