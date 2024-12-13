#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    pair<int, int> a[n];
    for(int i=0;i<n;i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a, a+n);
    int l = 0, r = n-1;
    while(l<r){
        if(a[l].first + a[r].first == x){
            cout << a[l].second << " " << a[r].second;
            return 0;
        }
        else if(a[l].first + a[r].first < x) l++;
        else r--;
    }
    cout << "IMPOSSIBLE";
}