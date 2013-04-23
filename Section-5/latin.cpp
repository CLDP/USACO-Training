/*
ID: CHN
PROG: latin
LANG: C++
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10;

int n;
long long ans;
bool r[MAXN][MAXN], c[MAXN][MAXN];

long long dfs(int rr, int cc) {
    if (cc == n) return dfs(rr+1, 1);
    if (rr == n-1) return 1;
    long long s[2], sum = 0;
    int t = 0;
    s[0] = s[1] = -1;
    
    for (int i = 0; i < n; ++i) {
        if (r[rr][i] || c[cc][i]) continue;
        if (i > cc) t = 1;
        if (rr == 1 && s[t] != -1) {
            sum += s[t];
        } else {
            r[rr][i] = c[cc][i] = true;
            s[t] = dfs(rr, cc + 1);
            sum += s[t];
            r[rr][i] = c[cc][i] = false;
        }
    }
    return sum;
}


int main() {
    freopen("latin.in", "r", stdin);
    freopen("latin.out", "w", stdout);
    cin >> n;
    
    for (int i = 0; i < n; ++i) c[i][i] = r[i][i] = true;
    
    ans = dfs(1, 1);
    for (int i = 2; i < n; ++i) ans *= i;
    
    cout << ans << endl;
    
    return 0;
}
