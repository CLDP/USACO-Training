/*
ID: CHN
PROG: concom
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int n;
bool f[101][101];
int x[101][101];


int main() {
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
    cin >> n;
    int a, b, c;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b >> c;
        x[a][b] = c;
    }
    
    for (int i = 1; i <= 100; ++i) f[i][i] = true;
    
    bool flag = false;
    while (true) {
        for (int i = 1; i <= 100; ++i)
         for (int j = 1; j <= 100; ++j)
          if (i != j && !f[i][j]) {
              int control = 0;
              for (int k = 1; k <= 100; ++k)
               if (f[i][k]) control += x[k][j];
              if (control > 50) {
                  f[i][j] = true;
                  flag = true;
              }
          }
        
        if (!flag) break;
        flag = false;
    }
    
    for (int i = 1; i <= 100; ++i)
     for (int j = 1; j <= 100; ++j)
      if (i != j && f[i][j]) cout << i << " " << j << endl;
    
    return 0;
}
