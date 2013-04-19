/*
ID: CHN
PROG: stamps
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 2000010;

int f[MAXN];
int x[100];
    
int main() {
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);
    int k, n;
    cin >> k >> n;
    f[0] = 0;
    int maxl = 0;
    for (int i = 0; i < n; ++i) cin >> x[i];
    int i = 1;
    while (true) {
        f[i] = k+1;
        for (int j = 0; j < n; ++j)
         if (i - x[j] >= 0 && f[i-x[j]]+1 < f[i]) f[i] = f[i-x[j]] + 1;
        if (f[i] == k+1) {
            cout << i-1 << endl;
            break;
        }
        ++i;
    }
    
    return 0;
}
