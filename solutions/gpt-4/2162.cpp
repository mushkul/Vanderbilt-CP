#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;;
    
    deque<int> dq;
    for(int i=1; i<=n; i++)
        dq.push_back(i);
    
    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
        if(!dq.empty()){
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }
    return 0;
}