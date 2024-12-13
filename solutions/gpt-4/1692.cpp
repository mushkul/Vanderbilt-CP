#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    string seq = "0";
    vector<bool> seen(1<<n);

    for(int i=0; i<(1<<n); i++) {
        string tmp = seq;
        tmp += '1';

        int mask = 0;

        for (int j=tmp.size()-1, k=0; k<n; j--, k++)
            mask = mask | ((tmp[j]-'0')<<k);

        if(!seen[mask]) {
            seq = tmp;
            seen[mask] = true;
        }
        else{
            tmp = seq;
            tmp += '0';

            mask = 0;

            for(int j=tmp.size()-1, k=0; k<n; j--, k++)
                mask = mask | ((tmp[j] - '0') << k);

            seq = tmp;
            seen[mask] = true;
        }
    }
    cout<<seq;
    return 0;
}