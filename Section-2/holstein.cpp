/*
ID: CHN
PROG: holstein
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

int v;
int x[30], z[30], zz[30];
int n;
int y[30][30];
int ans = 10000;
int anst[30];

int dfs(int a, int b) {
    if (a == n) {
        bool flag = true;
        for (int i = 0; i < v; ++i) {
            flag &= (z[i] >= x[i]);
            if (!flag) break;
        }
        if (!flag) return 0;
        if (b < ans) {
            ans = b;
            for (int i = 0; i < ans; ++i) anst[i] = zz[i];
        }
        return 0;
    }
    
    zz[b] = a;
    for (int i = 0; i < v; ++i) z[i] += y[a][i];
    dfs(a+1, b+1);
    for (int i = 0; i < v; ++i) z[i] -= y[a][i];
    
    dfs(a+1, b);
    return 0;
}

int main() {
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    cin >> v;
    for (int i = 0; i < v; ++i) cin >> x[i];
    cin >> n;
    for (int i = 0; i < n; ++i)
     for (int j = 0; j < v; ++j) cin >> y[i][j];
     
    dfs(0, 0);
    
    cout << ans;
    for (int i = 0; i < ans; ++i) cout << " " << anst[i]+1;
    cout << endl;
    
    return 0;
}
