#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> left, right;
    
    for(int i = 0; i < n; i++) {
        int coin, side;
        cin >> coin >> side;
        
        if(side == 1) left.push_back(coin);
        else right.push_back(coin);
        
        if(left.empty()) {
            cout << "<\n";
            continue;
        }
        if(right.empty()) {
            cout << ">\n";
            continue;
        }
        
        int maxLeft = *max_element(left.begin(), left.end());
        int maxRight = *max_element(right.begin(), right.end());
        int minLeft = *min_element(left.begin(), left.end());
        int minRight = *min_element(right.begin(), right.end());
        
        int sumLeft = 0;
        for(int x : left) sumLeft += x;
        
        int sumRight = 0;
        for(int x : right) sumRight += x;
        
        if(sumLeft > sumRight && minLeft > maxRight) cout << ">\n";
        else if(sumRight > sumLeft && minRight > maxLeft) cout << "<\n";
        else cout << "?\n";
    }
    
    return 0;
}