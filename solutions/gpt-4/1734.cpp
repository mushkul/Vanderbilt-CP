#include<bits/stdc++.h>
using namespace std;
#define MAX 200005

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> A(MAX);
    vector<int> last(MAX);
    vector<int> tree(4*MAX);
    int n, q;
    cin>>n>>q;
    
    for(int i=1; i<=n; i++)
        cin>>A[i];
    
    for(int i=n; i>=1; i--){
        if(last[A[i]])
            tree[n+i] = last[A[i]];
        else
            tree[n+i] = n;
        last[A[i]] = i;
    }
    for(int i=n-1; i>=1; i--)
        tree[i] = min(tree[i<<1], tree[i<<1|1]);
    
    while(q--){
        int l, r, ans = 1;
        cin>>l>>r;
        for(l+=n, r+=n; l<r; l>>=1, r>>=1){
            if(l&1){
                if(tree[l]<r)
                    ans++;
                l++;
            }
            if(r&1){
                r--;
                if(tree[r]<l)
                    ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}