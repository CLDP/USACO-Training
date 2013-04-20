/*
ID: CHN
PROG: heritage
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

string dfs(const string &p, const string &q) {
    string ans;
    for (int i = 0; i < q.size(); ++i)
     if (q[i] == p[0]) {
         string a, b;
         for (int j = 0; j < i; ++j) {
             a += p[1+j];
             b += q[j];
         }
         ans += dfs(a, b);
         a = b = "";
         for (int j = 0; j < p.size() - 1 - i; ++j) {
             a += p[1+i+j];
             b += q[1+i+j];
         }
         ans += dfs(a, b);
         ans += p[0];
         break;
     }
    return ans;
}

int main() {
    freopen("heritage.in", "r", stdin);
    freopen("heritage.out", "w", stdout);
    string p, q;
    cin >> p >> q;
    cout << dfs(q, p) << endl;
    
    return 0;
}
