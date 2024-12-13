#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n >> x;
    pair<int,int> arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    
    sort(arr, arr+n);
    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int left = j+1;
            int right = n-1;
            while(left < right){
                int sum = arr[i].first + arr[j].first + arr[left].first + arr[right].first;
                if(sum == x){
                    cout << arr[i].second << ' ' << arr[j].second << ' ' << arr[left].second << ' ' << arr[right].second << '\n';
                    return 0;
                }
                else if(sum < x)
                    left++;
                else
                    right--;
            }
        }
    }
    
    cout << "IMPOSSIBLE\n";
    return 0;
}