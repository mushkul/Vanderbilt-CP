#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Applicant {
    int x, y, diff; // x = programming skill, y = artistic skill, diff = x - y
};

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    vector<Applicant> applicants(n);

    for (int i = 0; i < n; ++i) {
        cin >> applicants[i].x >> applicants[i].y;
        applicants[i].diff = applicants[i].x - applicants[i].y;
    }

    // Sort applicants by their differential in descending order
    sort(applicants.begin(), applicants.end(), [](const Applicant &u, const Applicant &v) {
        return u.diff > v.diff;
    });

    long long max_sum = 0;
    for (int i = 0; i < a; ++i) {
        max_sum += applicants[i].x; // take top a as programmers
    }
    for (int i = a; i < a + b; ++i) {
        max_sum += applicants[i].y; // take next b as artists
    }

    cout << max_sum << endl;

    return 0;
}