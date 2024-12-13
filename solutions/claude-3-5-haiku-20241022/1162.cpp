#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> sorted_arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sorted_arr[i] = arr[i];
    }
    
    sort(sorted_arr.begin(), sorted_arr.end());
    
    int method1 = 0;
    vector<int> method1_arr = arr;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (method1_arr[j] > method1_arr[j + 1]) {
                swap(method1_arr[j], method1_arr[j + 1]);
                method1++;
            }
        }
    }
    
    int method2 = 0;
    vector<int> method2_arr = arr;
    for (int i = 0; i < n; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (method2_arr[j] < method2_arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(method2_arr[i], method2_arr[minIdx]);
            method2++;
        }
    }
    
    int method3 = 0;
    vector<int> method3_arr = arr;
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        pos[method3_arr[i]] = i;
    }
    
    for (int i = 0; i < n; i++) {
        while (method3_arr[i] != sorted_arr[i]) {
            int val = method3_arr[i];
            int correctPos = pos[sorted_arr[i]];
            swap(method3_arr[i], method3_arr[correctPos]);
            pos[val] = correctPos;
            pos[sorted_arr[i]] = i;
            method3++;
        }
    }
    
    int method4 = 0;
    vector<int> method4_arr = arr;
    for (int i = 0; i < n; i++) {
        while (method4_arr[i] != sorted_arr[i]) {
            int val = method4_arr[i];
            method4_arr.erase(method4_arr.begin() + i);
            method4_arr.insert(method4_arr.begin(), val);
            method4++;
        }
    }
    
    cout << method1 << " " << method2 << " " << method3 << " " << method4 << endl;
    
    return 0;
}