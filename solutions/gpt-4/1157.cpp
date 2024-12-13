C++
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long x, y;
    cin >> y >> x;
    long long ans = max(x, y);
    ans = ans * ans - (max(x, y) - min(x, y)) - 1;
    if(ans < max(x, y)){
        ans += 2 * (max(x, y) - ans - 1);
    }
    cout << ans;
    return 0;
}