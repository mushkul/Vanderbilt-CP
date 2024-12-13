#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 2e5+5;
int n, q;
int t[MAX], dp[MAX][30];
int main(){
	cin >> n >> q;
	for(int i=1; i<=n; i++){
		cin >> t[i];
		dp[i][0] = t[i];
	}
	for(int i=1; i<30; i++){
		for(int j=1; j<=n; j++){
			dp[j][i] = dp[dp[j][i-1]][i-1];
		}
	}
	while(q--){
		int x, k;
		cin >> x >> k;
		for(int i=29; i>=0; i--){
			if(k&(1<<i)) x = dp[x][i];
		}
		cout << x << "\n";
	}
	return 0;
}