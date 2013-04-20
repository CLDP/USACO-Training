/*
ID: CHN
PROG: rockers
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 21;

int f[MAXN][MAXN][MAXN];
int x[MAXN];

int main() {
    freopen("rockers.in", "r", stdin);
    freopen("rockers.out", "w", stdout);
    int n, m, t;
    cin >> n >> t >> m;
    
    for (int k = 1; k <= n; ++k) cin >> x[k];
    
    for (int i = 1; i <= n; ++i)
     for (int j = 1; j <= m; ++j)
      for (int k = 0; k <= t; ++k) {
          f[i][j][k] = max(f[i-1][j][k], f[i][j-1][t]);
          if (k >= x[i]) f[i][j][k] = max(f[i][j][k], f[i-1][j][k-x[i]] + 1);
      }
      
      
    cout << f[n][m][t] << endl;
    
    return 0;
}
