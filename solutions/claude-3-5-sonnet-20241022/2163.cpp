#include <bits/stdc++.h>
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    ordered_set<int> circle;
    for(int i = 1; i <= n; i++) {
        circle.insert(i);
    }
    
    int pos = 0;
    while(!circle.empty()) {
        pos = (pos + k) % circle.size();
        auto it = circle.find_by_order(pos);
        cout << *it << " ";
        circle.erase(it);
    }
    
    return 0;
}