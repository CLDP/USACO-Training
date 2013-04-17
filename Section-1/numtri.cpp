/*
ID: CHN
PROG: numtri
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

const int MAXN = 1010;

int ans;
int x[MAXN][MAXN], f[MAXN][MAXN];


int main() {
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
     for (int j = 1; j <= i; ++j) {
         cin >> x[i][j];
         f[i][j] = max(f[i-1][j], f[i-1][j-1]) + x[i][j];
         if (f[i][j] > ans) ans = f[i][j];
     }
    
    cout << ans << endl;
    
    return 0;
}
