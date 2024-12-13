#include<bits/stdc++.h>
using namespace std;
const int P = 31;
const int M = 1e9 + 9;
long long pw[100005],hsh[100005];
string s;
int n;

long long get(int l, int r){
    return ((hsh[r] - hsh[l-1]*pw[r-l+1])%M + M)%M;
}

bool check(int x){
    unordered_set<long long>hs;
    for(int i=1;i<=n-x+1;i++){
        long long val = get(i, i+x-1);
        if(hs.count(val))return 1;
        hs.insert(val);
    }
    return 0;
}

int main(){
    cin>>s;
    n = s.size();s = " "+s;
    pw[0] = 1;
    for(int i=1;i<=n;i++){
        hsh[i] = (hsh[i-1]*P + (s[i] - 'a' + 1))%M;
        pw[i] = (pw[i-1]*P)%M;
    }
    int l = 1, r = n, ans = 0;
    while(l<=r){
        int mid = (l+r)>>1;
        if(check(mid))l = mid+1, ans = mid;
        else r = mid-1;
    }
    if(!ans)cout<<-1;
    else{
        unordered_set<long long>hs;
        for(int i=1;i<=n-ans+1;i++){
            long long val = get(i, i+ans-1);
            if(hs.count(val)){
                cout<<s.substr(i, ans);break;
            }
            hs.insert(val);
        }
    }
}