#include <bits/stdc++.h>
using namespace std;
 
void grayCode(int n) {
    vector<string> arr;
    arr.push_back("0");
    arr.push_back("1");
    
    for(int i = 2; i <= n; i++) {
        int size = arr.size();
        for(int j = size-1; j >= 0; j--) {
            arr.push_back(arr[j]);
        }
        
        for(int j = 0; j < size; j++) {
            arr[j] = "0" + arr[j];
        }
        
        for(int j = size; j < 2*size; j++) {
            arr[j] = "1" + arr[j];
        }
    }
    
    for(string s : arr) {
        cout << s << "\n";
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    grayCode(n);
    return 0;
}