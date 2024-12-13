#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    multiset<int, greater<int>> tickets;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        tickets.insert(x);
    }
    for(int i = 0; i < m; i++){
        int x;
        cin>>x;
        auto it = tickets.lower_bound(x);
        if(it != tickets.end()){
            cout<<*it<<"\n";
            tickets.erase(it);
        }else{
            cout<<-1<<"\n";
        }
    }

    return 0;
}