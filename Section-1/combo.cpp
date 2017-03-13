/*
ID: CHN
PROG: combo
LANG: C++
*/
#include <cstdio>
#include <iostream>
using namespace std;

int N;

bool same(int a, int b) {
    for (int i = -2; i <= 2; ++i) {
        if (a % N == (b + i + N) % N) return true;
    }
    return false;
}

int main() {
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
    cin >> N;
    int a, b, c, x, y, z, ans = 0;
    cin >> a >> b >> c >> x >> y >> z;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 1; k <= N; ++k) {
                if ((same(i, a) && same(j, b) && same(k, c)) 
                 || (same(i, x) && same(j, y) && same(k, z))) ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
