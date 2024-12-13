#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
typedef long long ll;

ll ways[1000001];
ll n;

int main(){
    cin>>n;
    ways[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i-j>=0)
                ways[i] = (ways[i]+ways[i-j]) % M;
        }
    }
    cout<<ways[n];
    return 0;
}