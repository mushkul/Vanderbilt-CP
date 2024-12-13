#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solve(string s) {
    vector<bool> found(64);
    for (int a = 0; a < 4; a++)
        for (int b = 0; b < 4; b++)
            for (int c = 0; c < 4; c++) {
                string subseq = string(1, "ACGT"[a]) + "ACGT"[b] + "ACGT"[c];
                int j = 0;
                for (char ch : s) {
                    if (j < 3 && ch == subseq[j])
                        j++;
                }
                if (j < 3)
                    return subseq;
            }
    return "AAAAA";
}

int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}