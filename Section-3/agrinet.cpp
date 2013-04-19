/*
ID: CHN
PROG: agrinet
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

const int MAXN = 101;
const int INF = 1000000000;
int x[MAXN][MAXN];
int d[MAXN];
bool z[MAXN];


int main() {
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
     for (int j = 0; j < n; ++j) cin >> x[i][j];
    
    for (int i = 0; i < n; ++i) {
        z[i] = false;
        d[i] = INF;
    }
    d[0] = 0;
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int pos = 0, len = INF;
        for (int j = 0; j < n; ++j) {
            if (z[j]) continue;
            if (d[j] < len) {
                len = d[j];
                pos = j;
            }
        }
        ans += len;
        z[pos] = true;
        for (int j = 0; j < n; ++j) {
            if (z[j]) continue;
            if (x[pos][j] < d[j]) d[j] = x[pos][j];
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
