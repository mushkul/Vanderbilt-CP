#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> moves(k);
    for (int i = 0; i < k; i++) {
        cin >> moves[i];
    }
    
    vector<bool> win(n + 1, false);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (moves[j] <= i && !win[i - moves[j]]) {
                win[i] = true;
                break;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << (win[i] ? 'W' : 'L');
    }
    
    return 0;
}