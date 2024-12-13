#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll dp[19][2][10];
string s;

ll f(int pos, int smaller, int last){
    if(pos==s.size()) return 1;

    ll &ret=dp[pos][smaller][last];
    if(ret!=-1) return ret;

    ret=0;
    int LMT = smaller?s[pos]-'0':9;

    for(int dgt=0;dgt<=LMT;dgt++)
        if(dgt!=last)
            ret+=f(pos+1, smaller&&(dgt==(s[pos]-'0')), dgt);

    return ret;
}

void convert(ll b){
    s.clear();
    while(b>0){
        s+=b%10+'0';
        b/=10;
    }
    reverse(s.begin(),s.end());
}

ll solve(ll b){
    convert(b);
    memset(dp, -1, sizeof dp);
    return f(0,1,0)-1;
}

int main()
{
    ll a,b;
    cin>>a>>b;
    cout<<solve(b)-solve(a-1)<<endl;

    return 0;
}