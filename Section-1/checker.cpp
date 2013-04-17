/*
ID: CHN
PROG: checker
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

int n, ans;
int x[15];

// line number, left check, right, column
int dfs(int line, int lc, int rc, int cc) {
    if (line == n) {
        ++ans;
        if (ans > 3) return 0;
        for (int i = 0; i < n; ++i) {
            cout << x[i];
            if (i != n-1) cout << " ";
        }
        cout << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        int pos = 1 << (n - i);
        if (cc & pos) continue;
        if (lc & pos) continue;
        if (rc & pos) continue;
        x[line] = i;
        dfs(line + 1, (lc | pos) << 1, (rc | pos) >> 1, cc | pos);
    }
}


int main() {
    freopen("checker.in", "r", stdin);
    freopen("checker.out", "w", stdout);
    cin >> n;
    
    dfs(0, 0, 0, 0);
    cout << ans << endl;
    
    
    return 0;
}
