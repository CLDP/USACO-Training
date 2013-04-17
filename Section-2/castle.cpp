/*
ID: CHN
PROG: castle
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

const int MAXN = 52;


int n, m;
int x[MAXN][MAXN], f[MAXN * MAXN], d[MAXN * MAXN];
bool z[MAXN * MAXN];

int find(int x) {
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

int unionn(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    if (d[x] > d[y]) 
        f[y] = f[x];
    else
        f[x] = f[y];
    d[x] += d[y];
    d[y] = d[x];
    return 0;
}



int main() {
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) 
     for (int j = 1; j <= m; ++j) {
         cin >> x[i][j];
         f[i * m + j] = i * m + j;
         d[i * m + j] = 1;
         int temp = x[i][j];
         if (j > 1 && temp % 2 == 0) unionn(i * m + j, i * m + j - 1);
         temp /= 2;
         if (i > 1 && temp % 2 == 0) unionn(i * m + j, (i-1) * m + j); 
     }
    
    int ans = 0;
    
    for (int i = 1; i <= n; ++i) 
     for (int j = 1; j <= m; ++j) {
         if (!z[find(i * m + j)]) {
             ++ans;
             z[find(i * m + j)] = true;
         }
     }
    cout << ans << endl;
    
    ans = 0;
    for (int i = 1; i <= n; ++i) 
     for (int j = 1; j <= m; ++j) {
         if (d[find(i * m + j)] > ans) ans = d[find(i * m + j)];
     }
    cout << ans << endl;
    
    int a, b, dir;
    for (int i = 1; i <= m; ++i)
     for (int j = n; j >= 1; --j)  {
         int temp = x[j][i];
         temp /= 2;
         if (j > 1 && temp % 2 == 1) {
             if (find(j * m + i) != find((j-1) * m + i)) {
                 if (d[find(j * m + i)] + d[find((j-1) * m + i)] > ans) {
                     ans = d[find(j * m + i)] + d[find((j-1) * m + i)];
                     a = j, b = i, dir = 0;
                 }
             }
         }
         temp /= 2;
         if (i < m && temp % 2 == 1) {
             if (find(j * m + i) != find(j * m + i + 1)) {
                 if (d[find(j * m + i)] + d[find(j * m + i + 1)] > ans) {
                     ans = d[find(j * m + i)] + d[find(j * m + i + 1)];
                     a = j, b = i, dir = 1;
                 }
             }
         }
     }
     
    cout << ans << endl;
    cout << a << " " << b << " ";
    if (dir == 0)
        cout << "N";
    else 
        cout << "E";
    
    cout << endl;
    
    return 0;
}
