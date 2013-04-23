/*
ID: CHN
PROG: tour
LANG: C++
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 101;


int n, m, ans;
bool x[MAXN][MAXN];
int f[MAXN][MAXN];
vector<int> y[MAXN];
map<string, int> z;


int main() {
    freopen("tour.in", "r", stdin);
    freopen("tour.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string p;
        cin >> p;
        z[p] = i;
    }
    
    for (int i = 0; i < m; ++i) {
        string p, q;
        cin >> p >> q;
        x[z[p]][z[q]] = x[z[q]][z[p]] = true;
        y[z[p]].push_back(z[q]);
        y[z[q]].push_back(z[p]);
    }
    
    
    f[0][0] = 1;
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j)
         for (int k = 0; k < y[j].size(); ++k)
          if (f[i][y[j][k]] > 0 && f[i][y[j][k]] + 1 > f[i][j] && y[j][k] < j) {
              f[i][j] = f[i][y[j][k]] + 1;
              f[j][i] = f[i][j];
          }
          
        if (x[i][n-1] && f[i][n-1] > ans) ans = f[i][n-1];
    }
    
    if (ans == 0) ans = 1;
    cout << ans << endl;
    
    return 0;
}
