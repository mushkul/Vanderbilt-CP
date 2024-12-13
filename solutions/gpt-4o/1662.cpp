#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_map<int, int> remainder_count;
    remainder_count[0] = 1;
    long long sum = 0, result = 0;

    for (int i = 0; i < n; ++i) {
        sum += a[i];
        int remainder = ((sum % n) + n) % n;
        result += remainder_count[remainder];
        remainder_count[remainder]++;
    }

    cout << result << '\n';
    return 0;
}