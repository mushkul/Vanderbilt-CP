#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define fr first
#define sc second
#define MAX 100005
#define MOD 1000000007
#define INF 1e18
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);

int in[MAX], pre[MAX], post[MAX];
int idx[MAX], postIdx;

void build(int l, int r)
{
    if(l > r)
        return;
    int root=pre[l];
    int m = idx[root];
    build(l+1, m);
    build(m+1, r);
    post[postIdx++] = root;
}

int main()
{
    io;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    for(int i=0;i<n;i++){
        cin>>in[i];
        idx[in[i]] = i;
    }
    postIdx=0;
    build(0, n-1);
    for(int i=0;i<n;i++)
        cout<<post[i]<<" ";
    return 0;
}