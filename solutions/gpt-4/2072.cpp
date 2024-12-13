#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    while(m--){
	int a, b;
        cin >> a >> b;
        a--,b--;
        string t = s.substr(a, b-a+1);
        s = s.substr(0,a)+s.substr(b+1) + t;
    }
    cout << s << "\n";
    return 0;
}