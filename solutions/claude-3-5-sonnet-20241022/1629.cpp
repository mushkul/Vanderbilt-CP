#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> movies(n);
    
    for(int i = 0; i < n; i++) {
        cin >> movies[i].second >> movies[i].first;
    }
    
    sort(movies.begin(), movies.end());
    
    int count = 1;
    int current_end = movies[0].first;
    
    for(int i = 1; i < n; i++) {
        if(movies[i].second >= current_end) {
            count++;
            current_end = movies[i].first;
        }
    }
    
    cout << count;
    return 0;
}