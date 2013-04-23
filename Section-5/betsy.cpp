/*
ID: CHN
PROG: betsy
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MX[4] = {-1, 0, 0, 1};
const int MY[4] = {0, -1, 1, 0};

int n, ans;
bool x[9][9];
int y[9][9];


bool check(int a, int b, int c, int d) {
    if (a == c) {
        if (x[a-1][d+d-b] && !x[a-1][d] && !x[a][d+d-b]) return false;
        if (x[a+1][d+d-b] && !x[a+1][d] && !x[a][d+d-b]) return false;
        if (x[a][d+d-b] && !x[a-1][d] && !x[a+1][d]) return false;
    }
    
    if (b == d) {
        if (x[c+c-a][b-1] && !x[c][b-1] && !x[c+c-a][b]) return false;
        if (x[c+c-a][b+1] && !x[c][b+1] && !x[c+c-a][b]) return false;
        if (x[c+c-a][b] && !x[c][b-1] && !x[c][b+1]) return false;
    }
    
    return true;
}

int dfs(int a, int b, int c) {
    if (a == n && b == 1) {
        if (c == n * n) ++ans;
        return 0;
    }
    if (a == n-1 && b == 2 && !x[n-1][1] && !x[n][2]) return 0;
    
    x[a][b] = true;
    
    int j = 0, k;
    for (int i = 0; i < 4; ++i) {
        int p = a + MX[i], q = b + MY[i];
        --y[p][q];
        if (y[p][q] < 2 && !x[p][q] && (p < n || q > 1)) {
            ++j;
            k = i;
        }
    }
    
    if (j == 0) {
        for (int i = 0; i < 4; ++i)
         if (!x[a + MX[i]][b + MY[i]] && check(a, b, a + MX[i], b + MY[i]))
          dfs(a + MX[i], b + MY[i], c + 1);
    }
    
    if (j == 1 && check(a, b, a + MX[k], b + MY[k])) 
        dfs(a + MX[k], b + MY[k], c + 1);
    
    for (int i = 0; i < 4; ++i) ++y[a + MX[i]][b + MY[i]];
    x[a][b] = false;
    return 0;
}

int main() {
    freopen("betsy.in", "r", stdin);
    freopen("betsy.out", "w", stdout);
    cin >> n;
    for (int i = 0; i <= n+1; ++i) 
     x[i][0] = x[0][i] = x[n+1][i] = x[i][n+1] = true;
     
    y[1][1] = y[1][n] = y[n][1] = y[n][n] = 2;
    
    for (int i = 2; i <= n-1; ++i) 
     y[1][i] = y[i][1] = y[n][i] = y[i][n] = 3;
    
    for (int i = 2; i <= n-1; ++i)
     for (int j = 2; j <= n-1; ++j) y[i][j] = 4;
    
    for (int i = 0; i <= n+1; ++i) 
     y[0][i] = y[i][0] = y[n+1][i] = y[i][n+1] = 4;
     
    dfs(1, 1, 1);
    
    cout << ans << endl;
    
    return 0;
}
