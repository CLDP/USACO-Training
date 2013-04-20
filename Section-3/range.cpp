/*
ID: CHN
PROG: range
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 260;

int n;
bool x[MAXN][MAXN];
int u[MAXN][MAXN], l[MAXN][MAXN], f[MAXN][MAXN];

int main() {
    freopen("range.in", "r", stdin);
    freopen("range.out", "w", stdout);
    cin >> n;
    string p;
    for (int i = 1; i <= n; ++i) {
        cin >> p;
        for (int j = 1; j <= n; ++j) x[i][j] = int(p[j-1] - '0');
    }
    
    for (int i = 1; i <= n; ++i)
     for (int j = 1; j <= n; ++j) 
      if (x[i][j]) {
          l[i][j] = l[i][j-1] + 1;
          u[i][j] = u[i-1][j] + 1;
      } else {
          l[i][j] = 0;
          u[i][j] = 0;
      }
    
    for (int i = 1; i <= n; ++i) 
     for (int j = 1; j <= n; ++j) 
      if (x[i][j])
       f[i][j] = min(min(u[i][j], l[i][j]), f[i-1][j-1] + 1);
       
    int ans;
    for (int k = 2; k <= n; ++k) {
        ans = 0;
        for (int i = k; i <= n; ++i)
         for (int j = k; j <= n; ++j)
          if (f[i][j] >= k) ++ans;
        if (ans == 0) {
            break;
        } else {
            cout << k << " " << ans << endl;
        }
    }
    
    return 0;
}
