#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<tuple<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        arr[i] = make_tuple(a, i + 1);
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; ++i) {
        int a = get<0>(arr[i]);
        int left = i + 1, right = n - 1;
        while (left < right) {
            int b = get<0>(arr[left]);
            int c = get<0>(arr[right]);
            if (a + b + c == x) {
                cout << get<1>(arr[i]) << " " << get<1>(arr[left]) << " " << get<1>(arr[right]) << endl;
                return 0;
            } else if (a + b + c < x) {
                ++left;
            } else {
                --right;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}