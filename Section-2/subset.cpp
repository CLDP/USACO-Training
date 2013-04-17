/*
ID: CHN
PROG: subset
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
long long f[2000];

int main() {
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    cin >> n;
    f[0] = 1;
    int maxf = 0;
    for (int i = 1; i <= n; ++i) {
        maxf += i;
        for (int j = maxf; j >= i; --j) f[j] += f[j-i];
    }
    
    int sum = n * (n + 1) / 2;
    if (sum % 2 == 1) 
        cout << 0 << endl;
    else {
        sum /= 2;
        cout << f[sum] / 2 << endl;
    }
    
    
    return 0;
}
