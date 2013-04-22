/*
ID: CHN
PROG: snail
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 122;
const int INF = 2;
const int MX[4] = {-1, 0, 1, 0};
const int MY[4] = {0, 1, 0, -1};


int n, m, ans;
int x[MAXN][MAXN];
bool z[MAXN][MAXN][4];
bool DEBUG = false;

bool check(int a, int b) {
    if (a < 0 || a > n+1) return false;
    if (b < 0 || b > n+1) return false;
    return true;
}

int dfs(int a, int b, int d, int len) {
    if (len > ans) ans = len;
    if (check(a + MX[d], b + MY[d])) {
        if (x[a+MX[d]][b+MY[d]] == 0 && !z[a+MX[d]][b+MY[d]][d]) {
            x[a+MX[d]][b+MY[d]] = 1;
            z[a+MX[d]][b+MY[d]][d] = true;
            dfs(a + MX[d], b + MY[d], d, len + 1);
            z[a+MX[d]][b+MY[d]][d] = false;
            x[a+MX[d]][b+MY[d]] = 0;
        } else 
        if (x[a+MX[d]][b+MY[d]] == INF) {
            if (d == 0 || d == 2) {
                if (!z[a][b][1]) {
                    z[a][b][1] = true;
                    dfs(a, b, 1, len);
                    z[a][b][1] = false;
                }
                if (!z[a][b][3]) {
                    z[a][b][3] = true;
                    dfs(a, b, 3, len);
                    z[a][b][3] = false;
                }
            } else {
                if (!z[a][b][2]) {
                    z[a][b][2] = true;
                    dfs(a, b, 2, len);
                    z[a][b][2] = false;
                }
                if (!z[a][b][0]) {
                    z[a][b][0] = true;
                    dfs(a, b, 0, len);
                    z[a][b][0] = false;
                }
            }
        }
    }
    
}


int main() {
    freopen("snail.in", "r", stdin);
    freopen("snail.out", "w", stdout);
    cin >> n >> m;
    char p;
    int a;
    for (int i = 0; i < m; ++i) {
        cin >> p >> a;
        x[a][p-'A'+1] = INF;
    }
    for (int i = 0; i <= n+1; ++i)
        x[0][i] =  x[n+1][i] = x[i][0] = x[i][n+1] = INF;
    
    x[1][1] = 1;
    z[1][1][1] = true;
    dfs(1, 1, 1, 1);
    z[1][1][1] = false;
    z[1][1][2] = true;
    dfs(1, 1, 2, 1);
    z[1][1][2] = false;
    
    cout << ans << endl;
    
    return 0;
}
