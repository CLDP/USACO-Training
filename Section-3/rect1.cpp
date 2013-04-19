/*
ID: CHN
PROG: rect1
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct rect {
    int x1, y1, x2, y2, color;
};

vector<rect> x;
int ans[3000];


bool get_boundary(int x1, int x2, int x3, int x4, int &k1, int &k2) {
    k1 = max(x1, x3);
    k2 = min(x2, x4);
    if (k1 >= k2) return false;
    return true;
}


int add(int x1, int y1, int x2, int y2, int color) {
    rect p;
    p.x1 = x1;
    p.x2 = x2;
    p.y1 = y1;
    p.y2 = y2;
    p.color = color;
    x.push_back(p);
    return 0;
}


int main() {
    freopen("rect1.in", "r", stdin);
    freopen("rect1.out", "w", stdout);
    int n, m, k, a, b, c, d, color;
    cin >> n >> m >> k;
    add(0, 0, n, m, 1);
    for (int i = 0; i < k; ++i) {
        cin >> a >> b >> c >> d >> color;
        if (a > c) swap(a, c);
        if (b > d) swap(b, d);
        int j = 0, len = x.size();
        while (j < len) {
            int k1, k2, k3, k4;
            if (!get_boundary(x[j].x1, x[j].x2, a, c, k1, k2)) {
                ++j;
                continue;
            }
            if (!get_boundary(x[j].y1, x[j].y2, b, d, k3, k4)) {
                ++j;
                continue;
            }
            if (x[j].x1 < k1) add(x[j].x1, x[j].y1, k1, x[j].y2, x[j].color);
            if (k2 < x[j].x2) add(k2, x[j].y1, x[j].x2, x[j].y2, x[j].color);
            if (x[j].y1 < k3) add(k1, x[j].y1, k2, k3, x[j].color);
            if (k4 < x[j].y2) add(k1, k4, k2, x[j].y2, x[j].color);
            x.erase(x.begin() + j);
            --len;
        }
        add(a, b, c, d, color);
    }
    
    for (int i = 0; i < x.size(); ++i)
     ans[x[i].color] += (x[i].y2 - x[i].y1) * (x[i].x2 - x[i].x1);
    
    for (int i = 1; i <= 2500; ++i)
     if (ans[i] > 0) cout << i << " " << ans[i] << endl;
    
    return 0;
}
