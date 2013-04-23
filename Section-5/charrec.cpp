/*
ID: CHN
PROG: charrec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAPS = 21;
const int MAPL = 570;
const int MAXN = 1250;
const int INF = 1000000000;

int n, m;
bool x[MAXN][MAPS];
int y[MAXN][MAPL];
bool z[MAPL][MAPS];
int c[MAXN][24], cc[MAXN][24];
int f[MAXN], ff[MAXN], fa[MAXN];
bool cz[MAXN];


int find(int a, int b, int &c, int &d) {
    int p = INF, r;
    if (b == 20) {
        for (int k = 0; k <= 26; ++k) {
            int i = k * 20, q = 0;
            for (int j = 1; j <= 20; ++j) q += y[a+j][i+j];
            if (q < p) {
                p = q;
                r = k;
            }
        }
    } else
    if (b == 19) {
        for (int k = 0; k <= 26; ++k) {
            int i = k * 20;
            for (int l = 1; l <= 20; ++l) {
                int q = 0;
                for (int j = 1; j <= 19; ++j) 
                 if (j < l)
                     q += y[a+j][i+j];
                 else 
                     q += y[a+j][i+j+1];
                
                if (q < p) {
                    p = q;
                    r = k;
                }
            }
        }
    } else {
        for (int k = 0; k <= 26; ++k) {
            int i = k * 20;
            for (int l = 1; l <= 20; ++l) {
                int q = 0;
                for (int j = 1; j <= 21; ++j)
                 if (j <= l)
                     q += y[a+j][i+j];
                 else
                     q += y[a+j][i+j-1];
                
                if (q < p) {
                    p = q;
                    r = k;
                }
            }
        }
    }
    
    if (p <= 120) {
        c = r;
        d = p;
    } else {
        c = MAXN;
        d = MAXN;   
    }
    
    return 0;
}




int main() {
    ifstream font("font.in");
    freopen("charrec.in", "r", stdin);
    freopen("charrec.out", "w", stdout);
    
    // Input of fonts
    font >> m;
    for (int i = 1; i <= m; ++i) {
        char p;
        for (int j = 1; j <= 20; ++j) {
            font >> p;
            if (p == '1') z[i][j] = true;
        }
    }
    
    // Input and initialization
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        char p;
        for (int j = 1; j <= 20; ++j) {
            cin >> p;
            if (p == '1') x[i][j] = true;
        }
        
        for (int j = 1; j <= m; ++j) 
         for (int k = 1; k <= 20; ++k)
          y[i][j] += (x[i][k] ^ z[j][k]);
    }
    
    // Find which points can be reached
    cz[n+1] = true;
    for (int i = n; i >= 1; --i) 
     cz[i] = cz[i+21] || cz[i+20] || cz[i+19];
     
    // Get all values needed before hand
    for (int i = 1; i <= n-18; ++i)
     for (int j = 19; j <= 21; ++j) 
      if (i+j <= n+1) find(i-1, j, cc[i][j], c[i][j]);
    
    // Dynamic programming
    for (int i = n-18; i >= 1; --i) {
        if (!cz[i]) continue;
        if (i + 18 == n && cz[i + 19]) {
            f[i] = c[i][19];
            ff[i] = i + 19;
            fa[i] = cc[i][19];
        } else
        if (i + 19 == n) {
            int k = f[i + 19] + c[i][19];
            int l = f[i + 20] + c[i][20];
            if (k <= l && cz[i + 19]) {
                f[i] = k;
                ff[i] = i + 19;
                fa[i] = cc[i][19];
            } else 
            if (cz[i + 20]) {
                f[i] = l;
                ff[i] = i + 20;
                fa[i] = cc[i][20];
            }
        } else {
            int k = f[i + 19] + c[i][19]; 
            int l = f[i + 20] + c[i][20];
            int r = f[i + 21] + c[i][21];
            int a = 19, b = 20, d = 21;
            
            if (k > l) { swap(k, l); swap(a, b); }
            if (k > r) { swap(k, r); swap(a, d); }
            if (l > r) { swap(l, r); swap(b, d); }
            
            if (cz[i + a]) {
                f[i] = k;
                ff[i] = i + a;
                fa[i] = cc[i][a];
            } else 
            if (cz[i + b]) {
                f[i] = l;
                ff[i] = i + b;
                fa[i] = cc[i][b];
            } else
            if (cz[i + d]) {
                f[i] = r;
                ff[i] = i + d;
                fa[i] = cc[i][d];
            }
            
        }
    }
    
    int i = fa[1], j = 1;
    
    while (j <= n) {
        if (i == 0) {
            cout << " ";
        } else
        if (i > MAXN) {
            cout << "?";
        } else {
            cout << (char)(i + 'a' - 1);
        }
        j = ff[j];
        i = fa[j];
    }
    
    cout << endl;
    
    return 0;
}
