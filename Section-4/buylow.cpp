/*
ID: CHN
PROG: buylow
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class HP {
public:
    int len, s[201];
    HP() {
        *this = 0;
    };
    
    HP(int init) {
        *this = init;
    };
    
    
    friend ostream &operator << (ostream &cout, const HP &x) {
        for (int i = x.len; i >= 1; --i) printf("%d", x.s[i]);
        return cout;
    }
    
    HP operator = (int init) {
        if (init == 0) {
            len = 1;
            s[1] = 0;
            return (*this);
        }
        len = 0;
        while (init > 0) {
            s[++len] = init % 10;
            init /= 10;
        }
        return (*this);
    }
    
    HP operator + (const HP &b) {
        int i;
        HP c;
        c.s[1] = 0;
        for (i = 1; i <= len || i <= b.len || c.s[i]; ++i) {
            if (i <= len) c.s[i] += s[i];
            if (i <= b.len) c.s[i] += b.s[i];
            c.s[i+1] = c.s[i] / 10;
            c.s[i] %= 10;
        }
        c.len = i-1;
        if (c.len == 0) c.len = 1;
        return c;
    }
};


int n;
int x[5001], f[5001];
HP g[5001];


int main() {
    freopen("buylow.in", "r", stdin);
    freopen("buylow.out", "w", stdout);
    
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i];
    x[n++] = -1;
    
    
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        f[i] = 1;
        for (int j = i-1; j >= 0; --j) 
         if (x[j] > x[i] && f[j] + 1 > f[i]) {
             f[i] = f[j] + 1;
             if (f[i] > ans) ans = f[i];
         }
         
        g[i] = 0;
        if (f[i] == 1) {
            g[i] = 1;
        } else {
            vector<int> same;
            for (int j = i-1; j >= 0; --j) 
             if (x[j] > x[i] && f[j] + 1 == f[i]) {
                 bool flag = true;
                 for (int k = 0; k < same.size(); ++k) 
                  if (same[k] == x[j]) flag = false;
                 if (!flag) continue;
                 
                 same.push_back(x[j]);
                 g[i] = g[i] + g[j];
             }
        }
    }
      
    cout << ans - 1 << " " << g[n-1] << endl;
    
    return 0;
}
