c++
#include<bits/stdc++.h>
using namespace std;

int cnt[26][100005];
vector<pair<int,int>> v[26];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int k;
    cin >> k;
    s = " " + s;

    int n = s.size();
    for(int i=1; i<n; i++){
        for(int j=0; j<26; j++)
            cnt[j][i] = cnt[j][i-1];
        cnt[s[i]-'a'][i]++;
    }

    for(int i=0; i<26; i++)
        if(cnt[i][n-1] >= k){
            string t = "";
            for(int j=1; j<n; j++){
                if(s[j] == 'a'+i){
                    int l = 0;
                    int j1 = j;
                    for(int b=19; b>=0; b--){
                        if(j1+(1<<b) < n && l+cnt[i][j1+(1<<b)]-cnt[i][j-1] < k){
                            l += cnt[i][j1+(1<<b)]-cnt[i][j-1];
                            t += s.substr(j1+1, (1<<b));
                            j1 += (1<<b);
                        }
                    }
                    k -= l+1;
                    if(!k){
                        cout << t + (char)(i+'a');
                        return 0;
                    }
                }
            }
        } else
            k -= cnt[i][n-1];

    cout << -1;
}