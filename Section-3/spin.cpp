/*
ID: CHN
PROG: spin
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

struct node {
    int speed, num;
    int l[5], r[5];
};

node x[5];
    
int main() {
    freopen("spin.in", "r", stdin);
    freopen("spin.out", "w", stdout);
    for (int i = 0; i < 5; ++i) {
        cin >> x[i].speed >> x[i].num;
        for (int j = 0; j < x[i].num; ++j) {
            cin >> x[i].l[j] >> x[i].r[j];
            x[i].r[j] = (x[i].r[j] + x[i].l[j]) % 360;
        }
    }
    
    bool flag;
    int f[360];
    for (int time = 0; time < 20000; ++time) {
        memset(f, 0, sizeof(f));
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < x[i].num; ++j) {
                if (x[i].l[j] < x[i].r[j]) {
                    for (int k = x[i].l[j]; k <= x[i].r[j]; ++k) ++f[k];
                } else {
                    for (int k = x[i].l[j]; k < 360; ++k) ++f[k];
                    for (int k = 0; k <= x[i].r[j]; ++k) ++f[k];
                }
            }
        }
        flag = false;
        for (int i = 0; i < 360; ++i) flag |= (f[i] == 5);
        
        if (flag) {
            cout << time << endl;
            return 0;
        }
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < x[i].num; ++j) {
                x[i].l[j] = (x[i].l[j] + x[i].speed) % 360;
                x[i].r[j] = (x[i].r[j] + x[i].speed) % 360;
            }
        }
    }
    
    cout << "none" << endl;
    
    return 0;
}
