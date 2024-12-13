#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string transformed;
    cin >> transformed;

    int n = transformed.size();
    vector<int> count(256, 0);
    vector<int> pos(256, 0);
    vector<int> perm(n);

    for (char c : transformed) count[c]++;
    for (int i = 1; i < 256; i++) pos[i] = pos[i - 1] + count[i - 1];
    for (int i = 0; i < n; i++) perm[pos[transformed[i]]++] = i;

    int idx = find(transformed.begin(), transformed.end(), '#') - transformed.begin();
    string original(n - 1, ' ');

    for (int i = 0; i < n - 1; i++) {
        idx = perm[idx];
        original[i] = transformed[idx];
    }

    cout << original << endl;
    return 0;
}