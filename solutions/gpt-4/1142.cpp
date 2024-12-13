#include<bits/stdc++.h>
using namespace std;

int n, a[200005], l[200005], r[200005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); 
    cin >> n;

    for(int i=1;i<=n;i++)
        cin >> a[i];
  
    stack<int> s;
    a[0]=a[n+1]=-1;

    for(int i=1;i<=n+1;i++){
        while(!s.empty() and a[s.top()]>a[i]){
            r[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty())
        s.pop();

    for(int i=n;i>=0;i--){
        while(!s.empty() and a[s.top()]>a[i]){
            l[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    long long mx=0;
    for(int i=1;i<=n;i++)
        mx = max(mx, 1LL*a[i]*(r[i]-l[i]-1));

    cout << mx << endl;
    return 0;
}