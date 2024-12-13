#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,total=0,num;
    cin>>n;
    for(int i=1; i<n; i++)
    {
        cin>>num;
        total += num;
    }
    cout<<n*(n+1)/2 - total;
    return 0;
}