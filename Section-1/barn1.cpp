/*
ID: CHN
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> cow, diff;

int main() {
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
    int m, s, c, a;
    cin >> m >> s >> c;
    for (int i = 0; i < c; ++i) {
        cin >> a;
        cow.push_back(a);
    }
    sort(cow.begin(), cow.end());
    for (int i = 0; i < cow.size() - 1; ++i) diff.push_back(cow[i+1] - cow[i] - 1);
    sort(diff.begin(), diff.end());
    
    if (m >= c) {
        cout << c << endl;
    } else {
        int ans = cow[c-1] - cow[0] + 1;
        for (int i = 0; i < m-1; ++i) ans -= diff[diff.size() - 1 - i];
        cout << ans << endl;
    }
    
    return 0;
}
