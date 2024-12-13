#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long n; 
    cin>>n; 
    pair<long long, long long> p[n]; 
    for(long long i=0; i<n; i++) cin>>p[i].first>>p[i].second; 
    
    long long sum = 0; 
    for(long long i=0; i<n-1; i++) sum += p[i].first*p[i+1].second - p[i+1].first*p[i].second; 
    sum += p[n-1].first*p[0].second - p[0].first*p[n-1].second; 

    cout << abs(sum) << "\n";
    return 0;
}