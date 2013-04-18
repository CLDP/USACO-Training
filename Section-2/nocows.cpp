/*
ID: CHN
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 300;
const int INF = 9901;

int n, k;
int f[MAXN][MAXN];


int main() {
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) f[1][i] = 1;
    for (int i = 1; i <= n; ++i)
     if (i & 1)
      for (int j = 1; j <= k; ++j)
       for (int l = 1; l <= i-2; ++l)
        if (l & 1) f[i][j] = (f[i][j] + f[l][j-1] * f[i-l-1][j-1]) % INF;
    
    cout << (f[n][k] - f[n][k-1] + INF) % INF << endl;
    
    return 0;
}
