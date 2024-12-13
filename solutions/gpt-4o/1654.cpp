#include <iostream>
#include <vector>
using namespace std;

const int MAX_X = 1000000;

vector<int> countDivisors(vector<int> &arr, int n) {
    vector<int> div(MAX_X + 1, 0);
    vector<int> result(n);
    for(int i = 0; i < n; ++i) {
        ++div[arr[i]];
    }
    for(int i = 1; i <= MAX_X; ++i) {
        for(int j = i; j <= MAX_X; j += i) {
            div[i] += div[j];
        }
    }
    for(int i = 0; i < n; ++i) {
        result[i] = div[arr[i]];
    }
    return result;
}

vector<int> countAndEquals(vector<int> &arr, int n) {
    vector<int> result(n, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if((arr[i] & arr[j]) == arr[i]) {
                ++result[i];
            }
        }
    }
    return result;
}

vector<int> countAndNotZero(vector<int> &arr, int n) {
    vector<int> result(n, 0);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if((arr[i] & arr[j]) != 0) {
                ++result[i];
            }
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    vector<int> divisors = countDivisors(arr, n);
    vector<int> andEquals = countAndEquals(arr, n);
    vector<int> andNotZero = countAndNotZero(arr, n);
    
    for(int i = 0; i < n; ++i) {
        cout << divisors[i] << " " << andEquals[i] << " " << andNotZero[i] << '\n';
    }
    
    return 0;
}