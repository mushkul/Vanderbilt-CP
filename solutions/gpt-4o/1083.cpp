#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long total_sum = (long long)n * (n + 1) / 2;
    long long sum = 0;
    for (int i = 0, num; i < n - 1; ++i) {
        cin >> num;
        sum += num;
    }
    cout << total_sum - sum << endl;
    return 0;
}