#include<bits/stdc++.h>
using namespace std;

typedef pair<string, int> psi;
const int MAXN = 1e5 + 1;
const int MOD = 1e9+7;

int power26[MAXN], hashArray[MAXN], inv26[MAXN];
void precalculate() {
    power26[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        power26[i] = 26LL * power26[i - 1] % MOD;
    }

    inv26[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        inv26[i] = 1LL * (MOD - MOD / i) * inv26[MOD % i] % MOD;
    }
    for (int i = 2; i < MAXN; i++) {
        inv26[i] = 1LL * inv26[i] * inv26[i - 1] % MOD;
    }
}

int get_hash(int l, int r) {
    return ((0LL + hashArray[r] - hashArray[l - 1] + MOD) * inv26[l - 1] % MOD + MOD) % MOD;
}

int main() {
    precalculate();
    string s;
    int le = 1, k;
    cin>>s;
    cin>>k;
    int n = s.length();

    for (int i = 1; i <= n; i++) {
        hashArray[i] = (hashArray[i - 1] + 1LL * (s[i - 1] - 'a' + 1) * power26[i - 1] ) % MOD;
    }

    set<psi> substring_set;
    for(int i = n; i > 0; i--) {
        substring_set.insert({s.substr(i-1, 1), i});
    }

    while(k > 0) {
        auto it = substring_set.begin();
        string current = it->first;
        int currentIndex = it->second + current.size();
        substring_set.erase(it);
        k--;

        if(current.size() == k) {
            cout<<current<<'\n';
            return 0;
        }

        if(currentIndex <= n) {
            current += s[currentIndex - 1];
            psi newSubstr = {current, currentIndex};
            it = substring_set.lower_bound(newSubstr);
            if(it == substring_set.end() || it->first != current)
                substring_set.insert(newSubstr);
        }
    }

    return 0;
}