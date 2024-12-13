#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> stack_tracker(n+1, 0);
    set<int> left, right;
    while(n--){
        int c, s;
        cin >> c >> s;
        if(s == 1) left.insert(c);
        else right.insert(c);
        if(*right.rbegin() < *left.rbegin()) cout << ">\n";
        else if (*right.rbegin() > *left.rbegin()) cout << "<\n";
        else cout << "?\n";
    }

    return 0;
}