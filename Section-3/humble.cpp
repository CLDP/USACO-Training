/*
ID: CHN
PROG: humble
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

const int INF = 2100000000;

long long x[101];
long long z[101];
long long hum[1000001];
set<long long> previous;


int main() {
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);
    int k, n;
    cin >> k >> n;
    for (int i = 0; i < k; ++i) cin >> x[i];
    sort(x, x + k);
    for (int i = 0; i < k; ++i) z[i] = 0;
    hum[0] = 1;
    
    long long ans;
    int nn = 0;
    while (nn <= n) {
        int a;
        long long b = INF;
        for (int i = 0; i < k; ++i) {
            while (x[i] * hum[z[i]] <= hum[nn]) ++z[i];
            if (x[i] * hum[z[i]] < b) {
                b = x[i] * hum[z[i]];
                a = i;
            }
        }
        hum[++nn] = b;
        ++z[a];
    }
    cout << hum[n] << endl;
    
    return 0;
}
