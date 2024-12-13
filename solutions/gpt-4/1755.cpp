#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    vector<int> cnt(26, 0);
    for (char c : s) {
        ++cnt[c - 'A'];
    }
    int odds = 0;
    for (int i : cnt) {
        if(i % 2 !=0){
            ++odds;
        }
    }
    if (odds > 1) {
        cout << "NO SOLUTION" << "\n";
    } else {
        string t;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % 2 == 0) {
                t += string(cnt[i] / 2, i + 'A');
            }
        }
        cout << t;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % 2 != 0) {
                cout << string(cnt[i], i + 'A');
            }
        }
        reverse(t.begin(), t.end());
        cout << t << "\n";
    }
    return 0;
}