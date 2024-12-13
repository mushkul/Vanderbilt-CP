#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1005;
char arr[maxn][maxn];
int sum[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    memset(sum, 0, sizeof(sum));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (arr[i][j] == '*');
        }
    }
    while(q--)
    {
        int operation, x, y, x2, y2; cin >> operation;
        if(operation == 1)
        {
            cin >> y >> x;
            if(arr[y][x] == '*')
            {
                arr[y][x] = '.';
                for(int i = y; i <= n; i++)
                {
                    for(int j = x; j <= n; j++)
                        sum[i][j] -= 1;
                }
            }
            else
            {
                arr[y][x] = '*';
                for(int i = y; i <= n; i++)
                {
                    for(int j = x; j <= n; j++)
                        sum[i][j] += 1;
                }
            }
        }
        else
        {
            cin >> y >> x >> y2 >> x2;
            y--; x--;
            cout << sum[y2][x2] - sum[y][x2] - sum[y2][x] + sum[y][x] << "\n";
        }
    }
    return 0;
}