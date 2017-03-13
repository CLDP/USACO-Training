/*
ID: CHN
PROG: wormhole
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 13;
const int INF = 1000000007;

int N, ans;
int x[MAXN], y[MAXN], z[MAXN];

bool check(int a, int b) {
    if (b > 100) return true;
    int xx = INF, j = -1;
    for (int i = 1; i <= N; ++i) {
        if (y[i] == y[a] && x[i] > x[a] && x[i] < xx) {
            xx = x[i];
            j = i;
        }
    }
    if (j == -1) return false;
    return check(z[j], b + 1);
}


void dfs(int a) {
    if (a == N + 1) {
        for (int i = 1; i <= N; ++i) {
            if (check(i, 0)) {
                ++ans;
                break;
            }
        }
        return ;
    }
    if (z[a]) {
        dfs(a + 1);
        return ;
    }
    for (int i = a + 1; i <= N; ++i) {
        if (z[i]) continue;
        z[i] = a;
        z[a] = i;
        dfs(a + 1);
        z[a] = z[i] = 0;
    }
}

int main() {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> x[i] >> y[i];
    dfs(1);
    cout << ans << endl;
    return 0;
}
