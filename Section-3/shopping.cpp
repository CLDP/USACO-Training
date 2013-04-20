/*
ID: CHN
PROG: shopping
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

const int INF = 100000000;

struct node {
    int num, price;
    int x[5], y[5], z[5];
};

int n, m;
map<int, int> z;
node offer[105];
int need[5];
int f[6][6][6][6][6];


int main() {
    freopen("shopping.in", "r", stdin);
    freopen("shopping.out", "w", stdout);
    int a, b, c;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> offer[i].num;
        for (int j = 0; j < offer[i].num; ++j) cin >> offer[i].x[j] >> offer[i].y[j];
        cin >> offer[i].price;
    }
    
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a;
        z[a] = i;
        cin >> b >> c;
        offer[n+i].num = 1;
        offer[n+i].price = c;
        offer[n+i].z[i] = 1;
        need[i] = b;
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) offer[i].z[j] = 0;
        for (int j = 0; j < offer[i].num; ++j) offer[i].z[z[offer[i].x[j]]] = offer[i].y[j];
    }
    
    n += m;
    
    for (int i0 = 0; i0 <= 5; ++i0)
     for (int i1 = 0; i1 <= 5; ++i1)
      for (int i2 = 0; i2 <= 5; ++i2)
       for (int i3 = 0; i3 <= 5; ++i3)
        for (int i4 = 0; i4 <= 5; ++i4) f[i0][i1][i2][i3][i4] = INF;
    
    f[0][0][0][0][0] = 0;
    for (int i0 = 0; i0 <= need[0]; ++i0)
     for (int i1 = 0; i1 <= need[1]; ++i1)
      for (int i2 = 0; i2 <= need[2]; ++i2)
       for (int i3 = 0; i3 <= need[3]; ++i3)
        for (int i4 = 0; i4 <= need[4]; ++i4)
         for (int j = 0; j < n; ++j) {
             if (i0 < offer[j].z[0] || i1 < offer[j].z[1] || i2 < offer[j].z[2] ||
                 i3 < offer[j].z[3] || i4 < offer[j].z[4]) continue;
             f[i0][i1][i2][i3][i4] = min(f[i0][i1][i2][i3][i4], 
                 f[i0-offer[j].z[0]][i1-offer[j].z[1]][i2-offer[j].z[2]][i3-offer[j].z[3]][i4-offer[j].z[4]]
                     + offer[j].price);
         }
    
    cout << f[need[0]][need[1]][need[2]][need[3]][need[4]] << endl;
    
    return 0;
}
