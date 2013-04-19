/*
ID: CHN
PROG: inflate
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

int f[10100];


int main() {
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);
    int n, v, a, b;
    cin >> v >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        for (int j = b; j <= v; ++j) f[j] = max(f[j], f[j-b] + a);
    }
    
    int ans = 0;
    for (int i = 0; i <= v; ++i) 
     if (f[i] > ans) ans = f[i];
    
    cout << ans << endl;
    
    return 0;
}
