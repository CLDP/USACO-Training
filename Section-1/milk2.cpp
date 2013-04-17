/*
ID: CHN
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
    int a, b;
};

bool compare(const node &x, const node &y) {
    if (x.a < y.a) return true;
    if (x.a == y.a) return x.b < y.b;
    return false;
}



int main() {
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    int n, ans1 = 0, ans2 = 0;
    cin >> n;
    node p;
    vector<node> time;
    for (int i = 0; i < n; ++i) {
        cin >> p.a >> p.b;
        time.push_back(p);
    }
    
    sort(time.begin(), time.end(), compare);
    
    int l = time[0].a, r = time[0].b;
    ans1 = r - l, ans2 = 0;
    
    for (int i = 1; i < n; ++i) {
        if (r < time[i].a) {
            if (time[i].a - r > ans2) ans2 = time[i].a - r;
            l = time[i].a;
            r = time[i].b;
            if (r - l > ans1) ans1 = r - l;
        } else {
            if (time[i].b > r) r = time[i].b;
            if (r - l > ans1) ans1 = r - l;
        }
    }
    
    cout << ans1 << " " << ans2 << endl;
    
    return 0;
}
