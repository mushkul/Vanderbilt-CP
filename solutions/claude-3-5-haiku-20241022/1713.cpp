#include <iostream>
#include <cmath>

using namespace std;

int countDivisors(int x) {
    int count = 0;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            if (x / i == i)
                count++;
            else
                count += 2;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << countDivisors(x) << "\n";
    }

    return 0;
}