#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    ll prefix[200001] = {0}, total = 0, answer = 0;
    prefix[0]++; //there's always a prefix of 0 at the beginning of an array
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        total = ((total + a) % n + n) % n; //prevent negative mod
        answer += prefix[total]++;
    }
    cout << answer;
    return 0;
}