#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> count_ones(n + 1, 0);
    int current_ones = 0;
    vector<int> prefix_count(n + 1, 0);
    prefix_count[0] = 1;

    for (int i = 0; i < n; ++i) {
        current_ones += (s[i] == '1');
        if (current_ones >= 1) {
            count_ones[current_ones] += prefix_count[current_ones - 1];
        }
        prefix_count[current_ones]++;
    }

    cout << prefix_count[0] - 1;
    for (int i = 1; i <= n; ++i) {
        cout << " " << count_ones[i];
    }
    cout << endl;
    
    return 0;
}