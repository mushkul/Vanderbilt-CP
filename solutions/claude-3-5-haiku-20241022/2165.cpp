#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> moves;

void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        moves.push_back({from, to});
        return;
    }
    
    hanoi(n-1, from, aux, to);
    moves.push_back({from, to});
    hanoi(n-1, aux, to, from);
}

int main() {
    int n;
    cin >> n;
    
    hanoi(n, 1, 3, 2);
    
    cout << moves.size() << endl;
    for (auto move : moves) {
        cout << move.first << " " << move.second << endl;
    }
    
    return 0;
}