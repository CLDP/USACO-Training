/*
ID: CHN
PROG: sort3
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

int x[1010];


int main() {
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);
    int n, y[4], z[4][4];
    cin >> n;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) z[i][j] = 0;
        y[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        ++y[x[i]];
    }
    
    for (int i = 0; i < n; ++i) {
        if (i < y[1]) {
            ++z[1][x[i]];
        } else 
        if (i < y[1] + y[2]) {
            ++z[2][x[i]];
        } else {
            ++z[3][x[i]];
        }
    }
    
    int ans = 0, temp;
    
    temp = min(z[1][2], z[2][1]);
    ans += temp;
    z[1][2] -= temp;
    z[2][1] -= temp;
    
    temp = min(z[1][3], z[3][1]);
    ans += temp;
    z[1][3] -= temp;
    z[3][1] -= temp;
    
    temp = min(z[2][3], z[3][2]);
    ans += temp;
    z[2][3] -= temp;
    z[3][2] -= temp;
   
    
    ans += (z[1][2] + z[1][3]) * 2;
    
    cout << ans << endl;
    
    return 0;
}
