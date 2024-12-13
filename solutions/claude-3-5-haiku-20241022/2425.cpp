#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> leftStack, rightStack;
    int leftWeight = 0, rightWeight = 0;
    int minLeft = INT_MAX, maxLeft = INT_MIN;
    int minRight = INT_MAX, maxRight = INT_MIN;

    for (int i = 0; i < n; i++) {
        int coin, stack;
        cin >> coin >> stack;

        if (stack == 1) {
            leftStack.push_back(coin);
            leftWeight += coin;
            minLeft = min(minLeft, coin);
            maxLeft = max(maxLeft, coin);
        } else {
            rightStack.push_back(coin);
            rightWeight += coin;
            minRight = min(minRight, coin);
            maxRight = max(maxRight, coin);
        }

        if (leftWeight > rightWeight) cout << ">" << endl;
        else if (rightWeight > leftWeight) cout << "<" << endl;
        else if (maxLeft > minRight) cout << ">" << endl;
        else if (maxRight > minLeft) cout << "<" << endl;
        else cout << "?" << endl;
    }

    return 0;
}