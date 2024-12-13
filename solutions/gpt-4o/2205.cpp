#include <iostream>
#include <vector>
using namespace std;

vector<string> generateGrayCode(int n) {
    if (n == 0) return {""};
    vector<string> prev = generateGrayCode(n - 1);
    vector<string> result;
    for (auto &code : prev) result.push_back("0" + code);
    for (auto it = prev.rbegin(); it != prev.rend(); ++it) result.push_back("1" + *it);
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> grayCode = generateGrayCode(n);
    for (const string &code : grayCode) {
        cout << code << endl;
    }
    return 0;
}