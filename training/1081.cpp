#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &num : a) cin >> num;

    const int MAX_VALUE = 1000000;
    vector<int> count(MAX_VALUE + 1, 0);

    for (int num : a) count[num]++;

    int bestGCD = 1;
    for (int gcd = 1; gcd <= MAX_VALUE; ++gcd) {
        int multiples = 0;
        for (int multiple = gcd; multiple <= MAX_VALUE; multiple += gcd) {
            multiples += count[multiple];
            if (multiples >= 2) {
                bestGCD = gcd;
                break;
            }
        }
    }

    cout << bestGCD << endl;
    return 0;
}