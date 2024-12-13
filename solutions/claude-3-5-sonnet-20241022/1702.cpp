#include <bits/stdc++.h>
using namespace std;

void findPostorder(vector<int>& pre, vector<int>& in, int inStart, int inEnd, int& preIndex, vector<int>& post) {
    if (inStart > inEnd) return;
    
    if (inStart == inEnd) {
        post.push_back(pre[preIndex++]);
        return;
    }
    
    int inIndex = find(in.begin(), in.end(), pre[preIndex]) - in.begin();
    preIndex++;
    
    findPostorder(pre, in, inStart, inIndex-1, preIndex, post);
    findPostorder(pre, in, inIndex+1, inEnd, preIndex, post);
    
    post.push_back(in[inIndex]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> pre(n), in(n);
    for(int i = 0; i < n; i++) cin >> pre[i];
    for(int i = 0; i < n; i++) cin >> in[i];
    
    vector<int> post;
    int preIndex = 0;
    
    findPostorder(pre, in, 0, n-1, preIndex, post);
    
    for(int i = 0; i < n; i++) {
        cout << post[i];
        if(i < n-1) cout << " ";
    }
    
    return 0;
}