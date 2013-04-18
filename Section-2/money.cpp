/*
ID: CHN
PROG: money
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

long long f[10010];

int main() {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    int n, m, a;
    cin >> n >> m;
    f[0] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        for (int j = a; j <= m; ++j) f[j] += f[j-a];
    }
    cout << f[m] << endl;
    
    return 0;
}
