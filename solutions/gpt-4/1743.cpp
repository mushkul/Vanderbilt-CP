#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> count(26,0);
    priority_queue<pair<int, char>> pq;
    for(auto c : s){
        count[c-'A']++;
    }
    for(int i = 0;i<26;i++){
        if(count[i]){
            pq.push({count[i],'A'+i});
        }
    }
    pair<int,char> prev = {-1,'#'};
    s= "";
    while(!pq.empty()){
        pair<int,char> fp = pq.top();
        pq.pop();
        s += fp.second;
        if(prev.first > 0){
            pq.push(prev);
        }
        fp.first--;
        prev = fp;
    }
    if(s.length() != s.size()){
        cout<<"-1";
    }else{
        cout<<s;
    }
    return 0;
}