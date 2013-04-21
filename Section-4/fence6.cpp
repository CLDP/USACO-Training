/*
ID: CHN
PROG: fence6
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1000000;
const int MAXN = 101;

int n, ans = INF;
int len[MAXN];
bool xx[MAXN][MAXN], yy[MAXN][MAXN];
bool x1[MAXN], y1[MAXN];
vector<int> x[MAXN], y[MAXN];

// Current line, side, len, back point
int dfs(int a, bool right, int lent, int start) {
    if (lent > ans) return 0;
    if (start == a) {
        ans = min(ans, lent);
        return 0;
    }
    
    x1[a] = y1[a] = true;
    if (right) {
        for (int i = 0; i < x[a].size(); ++i) {
            int j = x[a][i];
            if (xx[j][a] && !x1[j]) dfs(j, false, lent + len[a], start);
            if (yy[j][a] && !y1[j]) dfs(j, true, lent + len[a], start);
        }
    } else {
        for (int i = 0; i < y[a].size(); ++i) {
            int j = y[a][i];
            if (xx[j][a] && !x1[j]) dfs(j, false, lent + len[a], start);
            if (yy[j][a] && !y1[j]) dfs(j, true, lent + len[a], start);
        }
    }
    x1[a] = y1[a] = false;
    return 0;
}



int main() {
    freopen("fence6.in", "r", stdin);
    freopen("fence6.out", "w", stdout);
    cin >> n;
    int a, b, c, d;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c >> d;
        len[a] = b;
        for (int j = 0; j < c; ++j) {
            cin >> b;
            x[a].push_back(b);
            xx[a][b] = true;
        }
        for (int j = 0; j < d; ++j) {
            cin >> b;
            y[a].push_back(b);
            yy[a][b] = true;
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        x1[i] = true;
        for (int j = 0; j < x[i].size(); ++j) {
            int k = x[i][j];
            if (xx[k][i]) 
                dfs(k, false, len[i], i);
            else
                dfs(k, true, len[i], i);
        }
        x1[i] = false;
    }
    
    cout << ans << endl;
    
    return 0;
}
