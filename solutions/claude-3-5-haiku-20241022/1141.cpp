#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> songs(n);
    for (int i = 0; i < n; i++) {
        cin >> songs[i];
    }
    
    unordered_set<int> seen;
    int maxLength = 0;
    int left = 0;
    
    for (int right = 0; right < n; right++) {
        while (seen.count(songs[right])) {
            seen.erase(songs[left]);
            left++;
        }
        
        seen.insert(songs[right]);
        maxLength = max(maxLength, right - left + 1);
    }
    
    cout << maxLength << endl;
    
    return 0;
}