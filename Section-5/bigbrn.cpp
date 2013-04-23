/*
ID: CHN
PROG: bigbrn
LANG: C++
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1001;
bool x[MAXN][MAXN];
int u[MAXN][MAXN], l[MAXN][MAXN], f[MAXN][MAXN];


int main() {
    freopen("bigbrn.in", "r", stdin);
    freopen("bigbrn.out", "w", stdout);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        x[a][b] = true;
    }
    
    for (int i = 1; i <= n; ++i)
     for (int j = 1; j <= n; ++j) 
      if (!x[i][j]) {
          u[i][j] = u[i-1][j] + 1;
          l[i][j] = l[i][j-1] + 1;
      } else {
          u[i][j] = 0;
          l[i][j] = 0;
      }
    
    int ans = 0;
    for (int i = 1; i <= n; ++i)
     for (int j = 1; j <= n; ++j) {
         if (!x[i][j]) f[i][j] = min(min(u[i][j], l[i][j]), f[i-1][j-1] + 1);
         if (f[i][j] > ans) ans = f[i][j];
     }

    cout << ans << endl;
    
    return 0;
}
