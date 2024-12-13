#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long sum = n * (n + 1LL) / 2;
    
    if (sum % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    vector<int> set1, set2;
    sum /= 2;
    for (int i = n; i >= 1; --i) {
        if (sum - i >= 0) {
            set1.push_back(i);
            sum -= i;
        } else {
            set2.push_back(i);
        }
    }

    cout << "YES" << endl;
    cout << set1.size() << "\n";
    for (int num : set1)
        cout << num << " ";
    cout << "\n" << set2.size() << "\n";
    for (int num : set2)
        cout << num << " ";
    cout << endl;

    return 0;
}