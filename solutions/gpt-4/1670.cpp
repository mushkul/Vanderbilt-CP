#include <bits/stdc++.h>
using namespace std;
int a[3][3];
int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int main() {
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      cin >> a[i][j];
  int res = 1e9;
  do {
    int sum = 0;
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        sum += abs(a[i][j]-b[i*3+j]);
    res = min(res, sum);
  } while (next_permutation(b, b+9));
  cout << res/2;
  return 0;
}