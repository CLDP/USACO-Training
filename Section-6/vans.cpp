/*
ID: CHN
PROG: vans
LANG: C++
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

const int z[8][8] = {{0, 0, 1, 0, 0, 0, 0, 1},
                     {0, 0, 0, 0, 1, 0, 0, 0},
                     {1, 0, 0, 1, 0, 1, 1, 0},
                     {0, 0, 1, 0, 0, 0, 0, 0},
                     {0, 1, 0, 0, 0, 0, 0, 0},
                     {0, 0, 1, 0, 0, 0, 0, 1},
                     {1, 0, 0, 0, 0, 1, 1, 0},
                     {0, 0, 1, 0, 0, 0, 0, 1}};

class HP {
public:
    int len, s[501];
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
HP a[8], b[8];


int main() {
    freopen("vans.in", "r", stdin);
    freopen("vans.out", "w", stdout);
    cin >> n;
    b[2] = b[7] = 1;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = 0; j < 8; ++j) a[j] = 0;
        
        for (int j = 0; j < 8; ++j)
         for (int k = 0; k < 8; ++k)
          if (z[j][k] == 1) a[k] = a[k] + b[j];
        
        for (int j = 0; j < 8; ++j) b[j] = a[j];
    }
    
    if (n == 1) {
        cout << 0 << endl;
    } else {
        HP ans = b[2] + b[6];
        ans = ans + ans;
        cout << ans << endl;
    }
    
    return 0;
}
