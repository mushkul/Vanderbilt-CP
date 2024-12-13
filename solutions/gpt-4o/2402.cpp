#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> input(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    stack<int> stack1, stack2;
    vector<int> output;
    int expected = 1;
    
    for (int i = 0; i < n; ++i) {
        int num = input[i];
        if (!stack1.empty() && stack1.top() == expected) {
            output.push_back(1);
            stack1.pop();
            --i;
            ++expected;
        } else if (!stack2.empty() && stack2.top() == expected) {
            output.push_back(2);
            stack2.pop();
            --i;
            ++expected;
        } else if (stack1.empty() || stack1.top() > num) {
            stack1.push(num);
            output.push_back(1);
        } else {
            stack2.push(num);
            output.push_back(2);
        }
    }

    while (!stack1.empty() || !stack2.empty()) {
        if (!stack1.empty() && stack1.top() == expected) {
            output.push_back(1);
            stack1.pop();
            ++expected;
        } else if (!stack2.empty() && stack2.top() == expected) {
            output.push_back(2);
            stack2.pop();
            ++expected;
        } else {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    for (int move : output) {
        cout << move << " ";
    }
    
    return 0;
}