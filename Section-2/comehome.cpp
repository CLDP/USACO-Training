/*
ID: CHN
PROG: comehome
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
using namespace std;

const int INF = 10000000;

int n;
int z[60][60];
map<char, int> y;


int main() {
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);
    for (int i = 0; i < 26; ++i) {
        y['A' + i] = i;
        y['a' + i] = i + 26;
    }
    
    cin >> n;
    char a, b;
    int c;
    for (int i = 0; i < 52; ++i)
     for (int j = 0; j < 52; ++j)
      if (i != j) z[i][j] = INF;
    
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c;
        if (c < z[y[a]][y[b]]) z[y[a]][y[b]] = c;
        if (c < z[y[b]][y[a]]) z[y[b]][y[a]] = c;
    }
    
    for (int k = 0; k < 52; ++k)
     for (int i = 0; i < 52; ++i)
      for (int j = 0; j < 52; ++j)
       if (z[i][k] + z[k][j] < z[i][j]) z[i][j] = z[i][k] + z[k][j];
    
    int ans = INF, ansN;
    for (int i = 0; i < 25; ++i)
     if (z[i][25] < ans) {
         ans = z[i][25];
         ansN = i;
     }
    
    cout << char(ansN + 'A') << " " << ans << endl;
    
    return 0;
}
