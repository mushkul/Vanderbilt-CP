#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    int k;
    cin >> k;

    set<string> str_set;
    for(int i = 0; i < s.size(); i++){
        string temp = "";
        for(int j = i; j < s.size(); j++){
            temp += s[j];
            str_set.insert(temp);
        }
    }

    while(k--){
        string pattern;
        cin >> pattern;
        if(str_set.count(pattern)){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
    return 0;
}