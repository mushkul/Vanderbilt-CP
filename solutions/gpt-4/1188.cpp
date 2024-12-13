#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
int prv[mxN + 1], nxt[mxN + 1], n, q, qu;
string s;

int main(){
    cin >> s;
    s = " " + s + " ";
    n = s.size();
    for (int i = 1; i < n; ++i){
        if(s[i] != s[i - 1])
            prv[i] = i;
        else
            prv[i] = prv[i - 1];
    }
    for (int i = n - 2; i; --i){
        if(s[i] != s[i + 1])
            nxt[i] = i;
        else
            nxt[i] = nxt[i + 1];
    }

    cin >> q;
    int ans = 0;
    while(q--){
        cin >> qu;
        s[qu] = '0' + '1' - s[qu];
        if(s[qu - 1] == s[qu])
            prv[qu] = prv[qu - 1];
        else
            prv[qu] = qu;
        if(s[qu + 1] == s[qu])
            nxt[qu] = nxt[qu + 1];
        else
            nxt[qu] = qu;
        ans = 0;
        if(s[qu - 1] == s[qu])
            ans = max(ans, nxt[qu] - prv[prv[qu - 1]] + 1);
        if(s[qu + 1] == s[qu])
            ans = max(ans, nxt[nxt[qu + 1]] - prv[qu] + 1);
        cout << ans << " ";
    }
}