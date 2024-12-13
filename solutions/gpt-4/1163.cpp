#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    multiset<int> lengths;
    lengths.insert(x);
    set<int> lights;
    lights.insert(0);
    lights.insert(x);
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        auto it = lights.upper_bound(a);
        int r = *it;
        it--;
        int l = *it;
        lengths.erase(lengths.find(r-l));
        lengths.insert(r-a);
        lengths.insert(a-l);
        lights.insert(a);
        it = lengths.end();
        it--;
        cout << *it << ' ';
    }
}