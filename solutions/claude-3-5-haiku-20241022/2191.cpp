#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<long long, long long>> vertices(n);
    
    for (int i = 0; i < n; i++) {
        cin >> vertices[i].first >> vertices[i].second;
    }
    
    long long area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += vertices[i].first * vertices[j].second - vertices[j].first * vertices[i].second;
    }
    
    cout << abs(area) << endl;
    
    return 0;
}