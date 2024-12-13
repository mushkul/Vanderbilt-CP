#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX = 2e5+5;
ll ar[MAX];
ll tree[MAX<<2], lazy[MAX<<2];

void build(int node, int start, int end){
  if(start == end)
    tree[node] = ar[start];
  else{
    int mid = (start + end) >> 1;
    build(node<<1, start, mid);
    build(node<<1|1, mid+1, end);
    tree[node] = max(tree[node<<1], tree[node<<1|1]);
  }
}

void update(int node, int start, int end, int idx, int val){
  if(start == end){
    tree[node] = ar[start] = val;
  }
  else{
    int mid = (start + end) >> 1;
    if(start <= idx && idx <= mid)
      update(node<<1, start, mid, idx, val);
    else
      update(node<<1|1, mid+1, end, idx, val);
    tree[node] = max(tree[node<<1], tree[node<<1|1]);
  }
}

ll query(int node, int start, int end, int l, int r){
  if(end < l || start > r)
    return -2e9;
  if(l <= start && end <= r)
    return tree[node];

  int mid = (start + end) >> 1;
  ll p1 = query(node<<1, start, mid, l, r);
  ll p2 = query(node<<1|1, mid+1, end, l, r);
  return max(p1, p2);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  for(int i = 1; i <= n ; ++i )
    cin >> ar[i];
  build(1, 1, n);
  while(q--){
    int type;
    cin >> type;
    if(type == 1){
      int k, u;
      cin >> k >> u;
      update(1, 1, n, k, u);
    }
    else{
      int a, b;
      cin >> a >> b;
      cout << max(0LL,query(1, 1, n, a, b)) << "\n";
    }
  }
  return 0;
}