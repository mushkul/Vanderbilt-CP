#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n + 1), pos(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    
    vector<pair<int, int>> reversals;
    
    for (int i = 1; i <= n; ++i) {
        if (arr[i] != i) {
            reversals.push_back({i, pos[i]});
            int l = i, r = pos[i];
            while (l < r) {
                swap(arr[l], arr[r]);
                pos[arr[l]] = l;
                pos[arr[r]] = r;
                ++l;
                --r;
            }
        }
    }

    cout << reversals.size() << endl;
    for (auto &r : reversals) {
        cout << r.first << " " << r.second << endl;
    }
    
    return 0;
}