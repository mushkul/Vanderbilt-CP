#include<bits/stdc++.h>
using namespace std;

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        char c[m+1][n+1];
        
        if(n*m%2 or n==1 and m==2 or m==1 and n==2 or n==2 and m==2){
            cout<<"NO\n";
            continue;}
        cout<<"YES\n";
	// this is how the trominos will get printed

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                c[i][j] = char((i+j)%26+97);
        if(n%2==0 && m%2){
            for(int i = 1; i <= m; i++)
            c[i][n] = c[i][n-1];}
        if(n%2 && m%2==0){
            for(int i = 1; i <= n; i++)
            c[m][i] = c[m-1][i];}
        if(n%2 && m%2){
            for(int i = 1; i < n; i += 2){
            c[m][i] = c[m-1][i];
            c[m][i+1] = c[m-1][i+1];}}

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                cout<<c[i][j];
    }
}