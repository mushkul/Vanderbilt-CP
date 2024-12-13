#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    vector<int> output(n);
    vector<int> stackAssignment(n);
    stack<int> stack1, stack2;
    
    int next = 1;
    int outputIndex = 0;
    bool impossible = false;
    
    for (int i = 0; i < n; i++) {
        if (!stack1.empty() && stack1.top() == next) {
            output[outputIndex++] = stack1.top();
            stackAssignment[i] = 1;
            stack1.pop();
            next++;
            i--;
            continue;
        }
        
        if (!stack2.empty() && stack2.top() == next) {
            output[outputIndex++] = stack2.top();
            stackAssignment[i] = 2;
            stack2.pop();
            next++;
            i--;
            continue;
        }
        
        if (input[i] == next) {
            output[outputIndex++] = input[i];
            stackAssignment[i] = 0;
            next++;
            i--;
            continue;
        }
        
        if (stack1.empty() || input[i] < stack1.top()) {
            stack1.push(input[i]);
            stackAssignment[i] = 1;
        } else if (stack2.empty() || input[i] < stack2.top()) {
            stack2.push(input[i]);
            stackAssignment[i] = 2;
        } else {
            impossible = true;
            break;
        }
    }
    
    while (!stack1.empty() && stack1.top() == next) {
        output[outputIndex++] = stack1.top();
        stack1.pop();
        next++;
    }
    
    while (!stack2.empty() && stack2.top() == next) {
        output[outputIndex++] = stack2.top();
        stack2.pop();
        next++;
    }
    
    if (impossible || outputIndex < n) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << stackAssignment[i] + 1 << " ";
        }
        cout << endl;
    }
    
    return 0;
}