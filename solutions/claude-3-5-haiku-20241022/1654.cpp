#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        int divisible_count = 0, bitwise_and_cover_count = 0, bitwise_and_nonzero_count = 0;
        
        for (int j = 0; j < n; j++) {
            int y = arr[j];
            
            if ((x | y) == x) {
                divisible_count++;
            }
            
            if ((x & y) == x) {
                bitwise_and_cover_count++;
            }
            
            if ((x & y) != 0) {
                bitwise_and_nonzero_count++;
            }
        }
        
        cout << divisible_count << " " << bitwise_and_cover_count << " " << bitwise_and_nonzero_count << "\n";
    }
    
    return 0;
}