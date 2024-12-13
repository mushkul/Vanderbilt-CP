#include<bits/stdc++.h>
using namespace std;

int PI[1000005], Z[1000005], n;
string s;

void computePI() {
    int j = 0;
    PI[0] = 0;
    for(int i = 1; i < n; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = PI[j-1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        PI[i] = j;
    }
}

void computeZ() {
    int l = 0, r = 0;
    Z[0] = 0;
    for(int i = 1; i < n; i++) {
        if(i <= r) {
            Z[i] = min(Z[i-l], r-i+1);
        }
        while(i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
            Z[i]++;
        }
        if(i + Z[i] - 1 > r) {
            l = i, r = i + Z[i] - 1;
        }
    }
}

int main() {
    cin >> s;
    n = s.length();
    computeZ();
    computePI();
    for(int i = 0; i < n; i++) {
        cout << Z[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < n; i++) {
        cout << PI[i] << " ";
    }
    cout << "\n";
    return 0;
}