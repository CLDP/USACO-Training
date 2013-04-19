/*
ID: CHN
PROG: ratios
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int f[3], x[3][3], z[3];

int main() {
    freopen("ratios.in", "r", stdin);
    freopen("ratios.out", "w", stdout);
    for (int i = 0; i < 3; ++i) cin >> z[i];
    for (int i = 0; i < 3; ++i)
     for (int j = 0; j < 3; ++j) cin >> x[i][j];
    
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 100; ++j) {
            for (int k = 0; k <= 100; ++k) {
                bool flag = true;
                for (int l = 0; l < 3; ++l) flag &= (z[l] == 0 || f[l] % z[l] == 0);
                for (int l = 0; l < 3; ++l) flag &= (f[l] != 0 || z[l] == 0);
                flag &= (f[0] * z[1] == f[1] * z[0]);
                flag &= (f[2] * z[1] == f[1] * z[2]);
                if (flag) {
                    cout << i << " " << j << " " << k << " ";
                    for (int l = 0; l < 3; ++l)
                     if (z[l] > 0) {
                         cout << f[l] / z[l] << endl;
                         break;
                     }
                    return 0;
                }
                for (int l = 0; l < 3; ++l) f[l] += x[2][l];
            }
            for (int l = 0; l < 3; ++l) f[l] += x[1][l] - 101 * x[2][l];
        }
        for (int l = 0; l < 3; ++l) f[l] += x[0][l] - 101 * x[1][l];
    }
    cout << "NONE" << endl;
    
    
    return 0;
}
