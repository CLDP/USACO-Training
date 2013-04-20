/*
ID: CHN
PROG: nuggets
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100000;

int n;
bool f[MAXN];

int gcd(int a, int b) {
    int t;
    while (b > 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}


int main() {
    freopen("nuggets.in", "r", stdin);
    freopen("nuggets.out", "w", stdout);
    cin >> n;
    f[0] = true;
    int all_gcd, a;
    bool one = false;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a == 1) one = true;
        if (i == 0) 
            all_gcd = a; 
        else 
            all_gcd = gcd(all_gcd, a);
        for (int j = a; j < MAXN; ++j) f[j] |= f[j-a];
    }
    if (all_gcd > 1 || one) {
        cout << 0 << endl;
        return 0;
    }
    
    for (int j = MAXN-1; j >= 0; --j) 
     if (!f[j]) {
         cout << j << endl;
         return 0;
     }
    
    return 0;
}
