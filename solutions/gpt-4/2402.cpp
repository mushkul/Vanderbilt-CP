#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> nums(n), storage, move_to_stack1(n), move_to_stack2(n);
    stack<int> stack1, stack2;

    for(int i=0; i<n; i++) cin >> nums[i];

    int idx = n-1;
    while(idx >= 0) {
        if(!stack1.empty() && stack1.top() < nums[idx]) {
            move_to_stack1[stack1.top()-1] = stack1.size();
            stack1.pop();
            continue;
        }
        if(!stack2.empty() && stack2.top() < nums[idx]) {
            if(!stack1.empty() && stack1.top() < stack2.top()) {
                cout << "IMPOSSIBLE" << "\n";
                return 0;
            }
            move_to_stack2[stack2.top()-1] = stack2.size();
            stack2.pop();
            continue;
        }
        stack1.push(nums[idx]);
        idx--;
    }
    while(!stack1.empty()) {
        move_to_stack1[stack1.top()-1] = stack1.size();
        stack1.pop();
    }
    while(!stack2.empty()) {
        move_to_stack2[stack2.top()-1] = stack2.size();
        stack2.pop();
    }

    for(int i = 0; i < n; ++i) {
        if(move_to_stack1[i] && (!move_to_stack2[i] || move_to_stack1[i] < move_to_stack2[i])) cout << 1 << "\n";
        else if(move_to_stack2[i]) cout << 2 << "\n";
    }

    return 0;
}