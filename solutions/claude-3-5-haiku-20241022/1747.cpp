#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());
    
    int peak_index = max_element(sorted_a.begin(), sorted_a.end()) - sorted_a.begin();
    
    vector<int> target(n);
    for (int i = 0; i <= peak_index; i++) {
        target[i] = sorted_a[i];
    }
    for (int i = peak_index + 1; i < n; i++) {
        target[i] = sorted_a[n - i + peak_index];
    }
    
    int moves = 0;
    for (int i = 0; i < n; i++) {
        int j = find(a.begin() + i, a.end(), target[i]) - a.begin();
        while (j > i) {
            swap(a[j], a[j-1]);
            j--;
            moves++;
        }
    }
    
    cout << moves << endl;
    
    return 0;
}