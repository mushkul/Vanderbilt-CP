#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> songs(n);
    for (int i = 0; i < n; ++i) {
        cin >> songs[i];
    }
    
    unordered_set<int> unique_songs;
    int left = 0, max_length = 0;
    
    for (int right = 0; right < n; ++right) {
        while (unique_songs.count(songs[right])) {
            unique_songs.erase(songs[left]);
            ++left;
        }
        unique_songs.insert(songs[right]);
        max_length = max(max_length, right - left + 1);
    }
    
    cout << max_length << endl;
    
    return 0;
}