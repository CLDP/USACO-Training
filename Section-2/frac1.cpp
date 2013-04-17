/*
ID: CHN
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct node {
    int a, b;
    double val;
};


bool compare(const node &p, const node &q) {
    return p.val < q.val;
}

int gcd(int a, int b) {
    int t;
    while (b > 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}


int main() {
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
    int n;
    cin >> n;
    node q;
    vector<node> ans;
    q.a = 0, q.b = 1, q.val = 0;
    ans.push_back(q);
    q.a = 1, q.b = 1, q.val = 1;
    ans.push_back(q);
    
    for (int i = 2; i <= n; ++i)
     for (int j = 1; j <= i; ++j) {
         if (gcd(i, j) == 1) {
             q.a = j;
             q.b = i;
             q.val =  1.0 * j / i;
             ans.push_back(q);
         }
     }
    
    sort(ans.begin(), ans.end(), compare);
    
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].a << "/" << ans[i].b << endl;
    }
    
    return 0;
}
