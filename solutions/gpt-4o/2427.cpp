#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int m = 2 * n;
    vector<pair<int, int>> moves;
    
    while (true) {
        int empty1 = s.find('.');
        int empty2 = s.find('.', empty1 + 1);
        if (empty2 == string::npos) break;
        
        bool moved = false;
        
        if (empty1 > 0 && empty2 > 1 && s[empty1 - 1] == 'B' && s[empty2 - 2] == 'A') {
            moves.emplace_back(empty1 - 1, empty2 - 2);
            swap(s[empty1 - 1], s[empty2 - 2]);
            moved = true;
        } else if (empty1 > 1 && s[empty1 - 1] == 'A' && s[empty1 - 2] == 'B') {
            moves.emplace_back(empty1 - 2, empty1);
            swap(s[empty1 - 2], s[empty1]);
            moved = true;
        } else if (empty2 < m - 1 && empty1 < m - 2 && s[empty2 + 1] == 'A' && s[empty1 + 2] == 'B') {
            moves.emplace_back(empty1, empty1 + 2);
            swap(s[empty1], s[empty1 + 2]);
            moved = true;
        }

        if (!moved) break;
    }
    
    if (s.substr(0, n - 1) == string(n - 1, 'A') && s.substr(n - 1, n - 1) == string(n - 1, 'B')) {
        cout << moves.size() << endl;
        for (const auto &move : moves) {
            cout << move.first + 1 << " " << move.second + 1 << endl;
        }
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}