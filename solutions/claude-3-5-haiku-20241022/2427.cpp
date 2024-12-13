#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<int,int>> solve(int n, string& s) {
    vector<pair<int,int>> moves;
    
    // Find initial empty positions 
    int empty1 = -1, empty2 = -1;
    for (int i = 0; i < 2*n; i++) {
        if (s[i] == '.') {
            if (empty1 == -1) empty1 = i;
            else empty2 = i;
        }
    }

    // Count initial A's and B's
    int a_count = 0, b_count = 0;
    for (int i = 0; i < 2*n; i++) {
        if (s[i] == 'A') a_count++;
        if (s[i] == 'B') b_count++;
    }

    if (a_count != n-1 || b_count != n-1) return {};

    // Solve problem
    while (true) {
        // Check if goal configuration is reached
        bool all_as_before_bs = true;
        int first_b_index = 2*n;
        int last_a_index = -1;
        for (int i = 0; i < 2*n; i++) {
            if (s[i] == 'B' && first_b_index == 2*n) first_b_index = i;
            if (s[i] == 'A') last_a_index = i;
            if (s[i] == 'B' && i < last_a_index) {
                all_as_before_bs = false;
                break;
            }
        }

        if (all_as_before_bs) break;

        // Find letter not in correct position
        int wrong_letter_pos = -1;
        for (int i = 0; i < 2*n-1; i++) {
            if ((s[i] == 'A' && s[i+1] == 'B') || (s[i] == 'B' && s[i+1] == 'A')) {
                wrong_letter_pos = i;
                break;
            }
        }

        if (wrong_letter_pos == -1) break;

        // Try to swap letters
        for (int i = 0; i < 2*n-1; i++) {
            if ((s[i] == 'A' || s[i] == 'B') && (s[i+1] == 'A' || s[i+1] == 'B')) {
                if (s[empty1] == '.' && s[empty2] == '.') {
                    char temp1 = s[i];
                    char temp2 = s[i+1];
                    s[i] = '.';
                    s[i+1] = '.';
                    s[empty1] = temp1;
                    s[empty2] = temp2;
                    moves.push_back({i, empty1});
                    empty1 = i;
                    empty2 = i+1;
                    break;
                }
            }
        }
    }

    // Check validity of solution
    int count_valid_moves = 0;
    for (int i = 0; i < 2*n-1; i++) {
        if (s[i] == 'A' && s[i+1] == 'B') count_valid_moves++;
    }

    if (count_valid_moves > 0) return {};

    return moves;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<pair<int,int>> solution = solve(n, s);

    if (solution.empty()) {
        cout << "-1\n";
    } else {
        cout << solution.size() << "\n";
        for (auto m : solution) {
            cout << m.first+1 << " " << m.second+1 << "\n";
        }
    }

    return 0;
}