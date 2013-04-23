/*
ID: CHN
PROG: hidden
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

int n, ans;
string p;

bool check(int &a) {
    for (int i = 0; i < n; ++i) {
        if (p[a+i] < p[ans+i]) {
            if (i > 1) a += i-1;
            return true;
        }
        if (p[a+i] > p[ans+i]) {
            if (i > 1) a += i-1;
            return false;
        }
    }
    a += n-1;
    return false;
}



int main() {
    freopen("hidden.in", "r", stdin);
    freopen("hidden.out", "w", stdout);
    cin >> n;
    string q;
    while (cin >> q) p += q;
    p = p + p;
    
    int i;
    ans = i = 0;
    while (i < n) {
        ++i;
        int j = i;
        if (check(i)) ans = j;
    }
    
    cout << ans << endl;
    
    return 0;
}
