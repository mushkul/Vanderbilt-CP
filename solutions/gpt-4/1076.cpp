#include<bits/stdc++.h>
using namespace std;
#define int long long

multiset<int> up , down;
void balance() {
    while(up.size() > down.size()) {
        down.insert(*up.begin());
        up.erase(up.begin());
    }
    while(down.size() > up.size() + 1) {
        up.insert(*--down.end());
        down.erase(--down.end());
    }
}
void add(int x){
    down.insert(x);
    balance();
}
void remove(int x){
    if(x < *down.rbegin())
        down.erase(down.lower_bound(x));
    else
        up.erase(up.lower_bound(x));
    balance();
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k; cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;++i) cin >> arr[i];
    for(int i=0;i<k;++i) add(arr[i]);
    cout << *down.rbegin() << " ";
    for(int i=k;i<n;++i){
        add(arr[i]);
        remove(arr[i-k]);
        cout << *down.rbegin() << " ";
    }
    return 0;
}