/*
ID: CHN
PROG: game1
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

const int MAXN = 110;

int n;
int x[MAXN], f[MAXN][MAXN], g[MAXN][MAXN];
bool z[MAXN][MAXN];

int dp(int a, int b, bool player) {
    if (z[a][b]) return g[a][b];
    if (a == b) {
        z[a][b] = true;
        f[a][b] = x[a];
        g[a][b] = 0;
        return g[a][b];
    }
    
    z[a][b] = true;
    
    int temp1 = dp(a, b-1, !player) + x[b];
    int temp2 = dp(a+1, b, !player) + x[a];
    if (temp1 > temp2) {
        f[a][b] = temp1;
        g[a][b] = f[a][b-1];
    } else {
        f[a][b] = temp2;
        g[a][b] = f[a+1][b];
    }
    return g[a][b];
}


int main() {
    freopen("game1.in", "r", stdin);
    freopen("game1.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i];
    
    dp(0, n-1, true);
    cout << f[0][n-1] << " " << g[0][n-1] << endl;
    
    return 0;
}
