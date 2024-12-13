#include <bits/stdc++.h>
using namespace std;

string s;
set<int> zeros, ones;

void add_boundaries() {
    zeros.insert(0);
    zeros.insert(s.size()+1);
    ones.insert(0); 
    ones.insert(s.size()+1);
}

void init_string() {
    int n = s.size();
    for(int i=1; i<=n; i++) {
        if(s[i-1]=='0') zeros.insert(i);
        else ones.insert(i);
    }
}

void get_max_len() {
    int maxlen = 0;
    
    vector<int> zero_vec(zeros.begin(), zeros.end());
    vector<int> one_vec(ones.begin(), ones.end());
    
    for(int i=1; i<zero_vec.size(); i++) {
        maxlen = max(maxlen, zero_vec[i]-zero_vec[i-1]-1);
    }
    
    for(int i=1; i<one_vec.size(); i++) {
        maxlen = max(maxlen, one_vec[i]-one_vec[i-1]-1);
    }
    
    cout << maxlen << " ";
}

void flip_bit(int pos) {
    if(zeros.count(pos)) {
        zeros.erase(pos);
        ones.insert(pos);
    } else {
        ones.erase(pos);
        zeros.insert(pos);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> s;
    int m;
    cin >> m;
    
    add_boundaries();
    init_string();
    
    for(int i=0; i<m; i++) {
        int pos;
        cin >> pos;
        flip_bit(pos);
        get_max_len();
    }
    
    return 0;
}