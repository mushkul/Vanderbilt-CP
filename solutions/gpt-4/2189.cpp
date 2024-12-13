#include <iostream>

using namespace std;

string point_location(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long a = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
    if (a > 0)
        return "LEFT";
    else if (a < 0)
        return "RIGHT";
    else
        return "TOUCH";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        cout << point_location(x1, y1, x2, y2, x3, y3) << endl;
    }
    return 0;
}