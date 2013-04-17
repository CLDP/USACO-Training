/*
ID: CHN
PROG: milk
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<pair<int, int> > p;

int main() {
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        p.push_back(make_pair(a, b));
    }
    sort(p.begin(), p.end());
    int ans = 0, i = 0;
    while (n > 0) {
        if (n > p[i].second) {
            ans += p[i].second * p[i].first;
            n -= p[i].second;
            ++i;
        } else {
            ans += p[i].first * n;
            break;
        }
    }
    cout << ans << endl;
    
    return 0;
}
