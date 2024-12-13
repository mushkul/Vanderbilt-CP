#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void findPostOrder(vector<int>& inorder, vector<int>& preorder, unordered_map<int, int>& inorderIndexMap, int inStart, int inEnd, int preStart, int preEnd, vector<int>& postorder) {
    if (inStart > inEnd || preStart > preEnd) return;
    
    int root = preorder[preStart];
    int rootIndex = inorderIndexMap[root];
    int leftTreeSize = rootIndex - inStart;

    findPostOrder(inorder, preorder, inorderIndexMap, inStart, rootIndex - 1, preStart + 1, preStart + leftTreeSize, postorder);
    findPostOrder(inorder, preorder, inorderIndexMap, rootIndex + 1, inEnd, preStart + leftTreeSize + 1, preEnd, postorder);
    postorder.push_back(root);
}

int main() {
    int n;
    cin >> n;
    vector<int> preorder(n), inorder(n);
    for (int i = 0; i < n; ++i) cin >> preorder[i];
    for (int i = 0; i < n; ++i) cin >> inorder[i];
    
    unordered_map<int, int> inorderIndexMap;
    for (int i = 0; i < n; ++i) inorderIndexMap[inorder[i]] = i;
    
    vector<int> postorder;
    findPostOrder(inorder, preorder, inorderIndexMap, 0, n - 1, 0, n - 1, postorder);

    for (int i = 0; i < postorder.size(); ++i) {
        if (i > 0) cout << ' ';
        cout << postorder[i];
    }
    cout << '\n';

    return 0;
}