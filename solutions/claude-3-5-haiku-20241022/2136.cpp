#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<bitset<30>> strings(n);
    
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        strings[i] = bitset<30>(s);
    }
    
    int min_distance = INT_MAX;
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int distance = (strings[i] ^ strings[j]).count();
            min_distance = min(min_distance, distance);
        }
    }
    
    cout << min_distance << endl;
    
    return 0;
}