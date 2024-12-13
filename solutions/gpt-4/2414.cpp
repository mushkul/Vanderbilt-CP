#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin>>n;
    vector<ll> B(n*(n-1)/2);
    map<ll,int> m;
    for(int i=0;i<n*(n-1)/2;i++) {
        cin>>B[i];
        m[B[i]]++;
    }
     
    sort(B.begin(),B.end());
 
    for(int i=1;i<n*(n-1)/2;i++){
        if(m[B[i]]>m[B[i-1]]) {
            vector<ll>A;
            A.push_back(B[i]);
            A.push_back(B[i]-B[0]);

            map<ll,int> s=m;

            s[B[i]]--;
            s[B[i]-B[0]]--;

            for(int j=0;j<n*(n-1)/2 && A.size()<n;j++){
                if(s[B[j]]>0) {
                    A.push_back(B[j]-A[0]);
                    for(int k=0;k<A.size()-1;k++) s[A[k]+A[A.size()-1]]--;
                }
            }

            bool flag=1;
            for(auto it:s) {
                if(it.second>0) flag=0;
            }
             
            if(flag) {
                for(auto it:A) cout<<it<<" ";
                return 0;
            }
        }
    }
    return 0;
}