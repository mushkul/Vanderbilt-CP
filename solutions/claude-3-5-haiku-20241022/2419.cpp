#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> bottom(n);
    for (int i = 0; i < n; i++) {
        cin >> bottom[i];
    }
    
    while (bottom.size() > 1) {
        vector<int> next_row(bottom.size() - 1);
        for (int i = 0; i < next_row.size(); i++) {
            next_row[i] = bottom[i] ^ bottom[i + 1];
        }
        bottom = next_row;
    }
    
    cout << bottom[0] << endl;
    
    return 0;
}