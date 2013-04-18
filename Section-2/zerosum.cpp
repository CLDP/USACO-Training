/*
ID: CHN
PROG: zerosum
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


int n;

// pos,  previous sum, previous left
int dfs(int a, int b, int c, string p) {
    if (a == n+1) {
        b += c;
        if (b == 0) cout << p << endl;
        return 0;
    }
    if (c > 0) {
        dfs(a + 1, b, c * 10 + a, p + " " + char(a + '0'));
    } else {
        dfs(a + 1, b, c * 10 - a, p + " " + char(a + '0'));
    }
    dfs(a + 1, b + c, a, p + "+" + char(a + '0'));
    dfs(a + 1, b + c, -a, p + "-" + char(a + '0'));
}


int main() {
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
    cin >> n;
    dfs(2, 0, 1, "1");
    
    return 0;
}
