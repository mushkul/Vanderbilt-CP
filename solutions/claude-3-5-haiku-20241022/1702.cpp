#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> postorder;
unordered_map<int, int> inorderIndex;

void reconstructTree(vector<int>& preorder, int preStart, int preEnd, 
                     int inStart, int inEnd) {
    if (preStart > preEnd) return;
    
    int root = preorder[preStart];
    int inRoot = inorderIndex[root];
    int numsLeft = inRoot - inStart;
    
    reconstructTree(preorder, preStart + 1, preStart + numsLeft, 
                    inStart, inRoot - 1);
    reconstructTree(preorder, preStart + numsLeft + 1, preEnd, 
                    inRoot + 1, inEnd);
    
    postorder.push_back(root);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> preorder(n), inorder(n);
    
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        inorderIndex[inorder[i]] = i;
    }
    
    reconstructTree(preorder, 0, n - 1, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        cout << postorder[i] << " ";
    }
    
    return 0;
}