/*
ID: CHN
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool z[10];

int main() {
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);
    
    int n, a;
    vector<int> p;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        p.push_back(a);
        z[a] = true;
    }
    
    int ans = 0;
    for (int i1 = 0; i1 < n; ++i1)
     for (int i2 = 0; i2 < n; ++i2)
      for (int i3 = 0; i3 < n; ++i3)
       for (int i4 = 0; i4 < n; ++i4)
        for (int i5 = 0; i5 < n; ++i5) {
            int a = 100 * p[i1] + 10 * p[i2] + p[i3];
            int b = a * p[i4];
            if (b > 999) continue;
            bool flag = true;
            while (b > 0) {
                flag &= (z[b % 10]);
                b /= 10;
            }
            if (!flag) continue;
            
            b = a * p[i5];
            if (b > 999) continue;
            flag = true;
            while (b > 0) {
                flag &= (z[b % 10]);
                b /= 10;
            }
            if (!flag) continue;
            
            b = a * (p[i4] * 10 + p[i5]);
            if (b > 9999) continue;
            flag = true;
            while (b > 0) {
                flag &= (z[b % 10]);
                b /= 10;
            }
            if (!flag) continue;
            
            ++ans;
        }
    
    cout << ans << endl;
    
    return 0;
}
