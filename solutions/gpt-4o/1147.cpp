#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    stack<int> indices;
    int max_area = 0;
    for (int i = 0; i < heights.size(); i++) {
        while (!indices.empty() && heights[indices.top()] > heights[i]) {
            int h = heights[indices.top()];
            indices.pop();
            int w = indices.empty() ? i : i - indices.top() - 1;
            max_area = max(max_area, h * w);
        }
        indices.push(i);
    }
    return max_area;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int max_area = 0;
    vector<int> heights(matrix[0].size(), 0);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            heights[j] = matrix[i][j] == '.' ? heights[j] + 1 : 0;
        }
        max_area = max(max_area, largestRectangleArea(heights));
    }
    return max_area;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> forest(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> forest[i][j];
    cout << maximalRectangle(forest) << endl;
    return 0;
}