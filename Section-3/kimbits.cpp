/*
ID: CHN
PROG: kimbits
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

int f[40][40];
    
int main() {
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);
    int n, l;
    long long m;
    cin >> n >> l >> m;
    
    ++l;
    --m;
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i)
     for (int j = 1; j <= min(i, l); ++j)
      for (int k = i-1; k >= j-1; --k) f[i][j] += f[k][j-1];
      
    for (int i = n; i > 0; --i) {
        int t = 0;
        for (int j = l; j > 0; --j) t += f[i][j];
        if (t <= m) {
            cout << 1;
            m -= t;
            --l;
        } else {
            cout << 0;
        }
    }
    cout << endl;
    
    
    return 0;
}
