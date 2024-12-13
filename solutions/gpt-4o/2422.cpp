#include <iostream>
using namespace std;

int countLessOrEqual(int n, int x) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        count += min(n, x / i);
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    int left = 1, right = n * n, middle, answer;
    int k = (n * n + 1) / 2;
    while (left <= right) {
        middle = left + (right - left) / 2;
        if (countLessOrEqual(n, middle) >= k) {
            answer = middle;
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    cout << answer << endl;
    return 0;
}