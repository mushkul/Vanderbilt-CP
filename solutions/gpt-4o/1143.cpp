#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> hotels(n);
    for (int i = 0; i < n; i++) {
        cin >> hotels[i];
    }
    
    for (int i = 0; i < m; i++) {
        int roomsNeeded;
        cin >> roomsNeeded;
        int assignedHotel = 0;
        for (int j = 0; j < n; j++) {
            if (hotels[j] >= roomsNeeded) {
                assignedHotel = j + 1;
                hotels[j] -= roomsNeeded;
                break;
            }
        }
        cout << assignedHotel << " ";
    }
    
    return 0;
}