#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    set<pair<long long,long long>> visited;
    pair<long long,long long> curr = {0,0};
    visited.insert(curr);
    
    long long dist = 0;
    bool done = false;
    
    for(int i = 0; i < n; i++) {
        char d;
        long long x;
        cin >> d >> x;
        
        if(done) continue;
        
        pair<long long,long long> next = curr;
        
        if(d == 'U') next.second += x;
        else if(d == 'D') next.second -= x;
        else if(d == 'L') next.first -= x;
        else next.first += x;
        
        long long dx = abs(next.first - curr.first);
        long long dy = abs(next.second - curr.second);
        
        if(d == 'U' || d == 'D') {
            long long y1 = min(curr.second, next.second);
            long long y2 = max(curr.second, next.second);
            
            for(long long y = y1+1; y <= y2; y++) {
                pair<long long,long long> p = {curr.first, y};
                if(visited.count(p)) {
                    dist += abs(y - curr.second);
                    done = true;
                    break;
                }
                visited.insert(p);
            }
        } else {
            long long x1 = min(curr.first, next.first);
            long long x2 = max(curr.first, next.first);
            
            for(long long x = x1+1; x <= x2; x++) {
                pair<long long,long long> p = {x, curr.second};
                if(visited.count(p)) {
                    dist += abs(x - curr.first);
                    done = true;
                    break;
                }
                visited.insert(p);
            }
        }
        
        if(!done) {
            dist += dx + dy;
            curr = next;
        }
    }
    
    cout << dist << "\n";
    
    return 0;
}