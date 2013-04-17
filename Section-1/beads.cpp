/*
ID: CHN
PROG: beads
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;


int main() {
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    string p;
    cin >> p;
    
    int l, r, mode;
    for (int i = 0; i < n; ++i) {
        l = 0; r = n-1;
        mode = 0;
        // 0 white, 1 blue, 2 red
        while (l < n) {
            if (mode == 0) {
                if (p[l] == 'b') mode = 1;
                if (p[l] == 'r') mode = 2;
                ++l;
            } else 
            if (mode == 1) {
                if (p[l] == 'r') break;
                ++l;
            } else {
                if (p[l] == 'b') break;
                ++l;
            }
        }
        --l;
        
        mode = 0;
        while (r > l) {
            if (mode == 0) {
                if (p[r] == 'b') mode = 1;
                if (p[r] == 'r') mode = 2;
                --r;
            } else 
            if (mode == 1) {
                if (p[r] == 'r') break;
                --r;
            } else {
                if (p[r] == 'b') break;
                --r;
            }
        }
        ++r;
        
        if (n - (r - l - 1) > ans) ans = n - (r - l - 1);
        
        p = p + p[0];
        p.erase(p.begin(), p.begin() + 1);
    }
    cout << ans << endl;
        
    return 0;
}
