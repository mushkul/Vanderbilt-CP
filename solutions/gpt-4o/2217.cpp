#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    
    set<int> rounds;
    for (int i = 1; i <= n; ++i) {
        if (i == 1 || pos[i] < pos[i - 1]) {
            rounds.insert(i);
        }
    }
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        
        int va = arr[a], vb = arr[b];
        
        auto check = [&](int x) {
            if (x > 1) {
                if (pos[x] < pos[x - 1]) rounds.insert(x);
                else rounds.erase(x);
            }
            if (x < n) {
                if (pos[x + 1] < pos[x]) rounds.insert(x + 1);
                else rounds.erase(x + 1);
            }
        };
        
        swap(arr[a], arr[b]);
        swap(pos[va], pos[vb]);
        
        check(va);
        check(vb);
        
        cout << rounds.size() << endl;
    }
    
    return 0;
}