C++
#include<bits/stdc++.h>
using namespace std;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> v;
    do {
        v.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << v.size() << "\n";
    for (string s : v) {
        cout << s << "\n";
    }
    return 0;
}