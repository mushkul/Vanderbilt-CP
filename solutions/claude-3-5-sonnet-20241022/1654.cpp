#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+1;
int n, cnt[maxN];
vector<int> nums;

int main() {
    cin >> n;
    nums.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        cnt[nums[i]]++;
    }
    
    for(int i = 0; i < n; i++) {
        int a = 0, b = 0, c = 0;
        int x = nums[i];
        
        // For OR and AND
        for(int sub = 0; sub < maxN; sub++) {
            if((sub & x) == x) b += cnt[sub];
            if((sub & x) != 0) c += cnt[sub];
        }
        
        // For divisibility
        for(int j = x; j < maxN; j += x) {
            if(j % x == 0) a += cnt[j];
        }
        
        cout << a << " " << b << " " << c << "\n";
    }
    return 0;
}