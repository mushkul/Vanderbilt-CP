#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> arr(n+1);
    vector<int> prefixXor(n+1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        prefixXor[i] = prefixXor[i-1] ^ arr[i];
    }
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        
        cout << (prefixXor[b] ^ prefixXor[a-1]) << endl;
    }
    
    return 0;
}