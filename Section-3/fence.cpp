/*
ID: CHN
PROG: fence
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

const int MAXN = 501;

int n, m;
int d[MAXN];
int x[MAXN][MAXN];
vector<int> ans;

int dfs(int a) {
    for (int i = 1; i <= n; ++i)
     if (x[i][a] > 0) {
         --x[i][a];
         --x[a][i];
         dfs(i);
     }
    
    ans.push_back(a);
}

int main() {
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    int a, b;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        ++x[a][b];
        ++x[b][a];
        if (a > n) n = a;
        if (b > n) n = b;
        ++d[a]; 
        ++d[b];
    }
    
    a = 1;
    for (int i = n; i >= 1; --i)
     if (d[i] & 1) a = i;
    
    dfs(a);
    
    for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i] << endl;
    
    return 0;
}
