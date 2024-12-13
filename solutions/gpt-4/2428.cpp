#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() 
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n), left(n);
    map<ll, ll> freq;
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll index = 0;
    for (ll i = 0; i < n; i++) {
        if (freq[arr[i]] == 0) {
            k--;
        }
        freq[arr[i]]++;
        while (k < 0) {
            freq[arr[index]]--;
            if (freq[arr[index]] == 0) {
                k++;
            }
            index++;
        }
        left[i] = index;
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
        ans += i - left[i] + 1;
    cout << ans;
    return 0;
}