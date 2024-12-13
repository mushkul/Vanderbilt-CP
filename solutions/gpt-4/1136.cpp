#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ar array
#define MAX_N 200005

vector<int> L(MAX_N), R(MAX_N);
int add[MAX_N], parent[MAX_N], counts[MAX_N];
vector<int> edges[MAX_N];

void dfs1(int node, int P) {
  L[node] = R[node] = P++;
  for(auto &i : edges[node]) {
    if(i == parent[node]) 
      continue;
    parent[i] = node;
    dfs1(i, P);
    P = R[i]+1;
  }
  R[node] = P-1;
}

void add_paths(int a, int b) {
  add[L[a]]++, add[R[a]+1]--;
  add[L[b]]++, add[R[b]+1]--;
  add[L[parent[a]]]--, add[R[parent[a]]+1]++;
  add[L[parent[b]]]--, add[R[parent[b]]+1]++;
}

void dfs2(int node) {
  for(auto i : edges[node]) {
    if(i == parent[node]) 
      continue;
    dfs2(i);
    counts[node] += counts[i];
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;

  for(int i = 1; i<n; i++) {
    int a, b;
    cin >> a >> b, --a, --b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  
  dfs1(0, 1);
  
  while(m--) {
    int a, b;
    cin >> a >> b, --a, --b;
    add_paths(a, b);
  }
  
  for(int i=1; i<=n; i++)
    add[i] += add[i-1];
  for(int i=0; i<n; i++)
    counts[i] = add[L[i]];
    
  dfs2(0);
  
  for(int i=0; i<n; i++)
    cout << counts[i] << " ";
    
  return 0;
}