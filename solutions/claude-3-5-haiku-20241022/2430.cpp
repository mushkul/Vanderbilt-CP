#include <iostream>
#include <string>
#include <set>
using namespace std;

string solve(int n) {
    if (n == 1) return "1";
    
    string s = "10";
    set<string> subsequences;
    subsequences.insert("");
    subsequences.insert("0");
    subsequences.insert("1");
    
    while (subsequences.size() < n) {
        string temp = s;
        for (char bit : {'0', '1'}) {
            temp += bit;
            for (const string& subseq : subsequences) {
                string newSubseq = subseq + bit;
                subsequences.insert(newSubseq);
            }
            if (subsequences.size() >= n) break;
            temp.pop_back();
        }
        s = temp;
    }
    
    return s;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}