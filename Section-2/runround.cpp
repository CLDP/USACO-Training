/*
ID: CHN
PROG: runround
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
bool z[10], zp[10];


bool check(int a) {
    if (a <= n) return false;
    vector<int> p;
    while (a > 0) {
        p.push_back(a % 10);
        a /= 10;
    }
    int len = p.size();
    int pos = len - 1, diff = 0;
    memset(z, 0, sizeof(z));
    for (int i = 0; i < len; ++i) {
        if (!z[pos]) {
            z[pos] = true;
            ++diff;
        } else {
            break;
        }
        pos = (pos + len * 10 - p[pos]) % len;
    }
    return (diff == len && pos == len - 1);
}


bool dfs(int a, int b, int exist, int len) {
    if (a == len) {
        if (check(b)) {
            cout << b << endl;
            return true;
        }
        return false;
    }
    for (int i = 1; i <= 9; ++i) 
     if ((exist & (1 << (i - 1))) == 0) {
         if (dfs(a+1, b * 10 + i, exist | (1 << (i - 1)), len)) return true;
     }
    return false;
}


int main() {
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
    cin >> n;
    int m = n, len = 0;
    while (m > 0) {
        m /= 10;
        ++len;
    }
    while (true) 
     if (dfs(0, 0, 0, len++)) break;
    
    return 0;
}
