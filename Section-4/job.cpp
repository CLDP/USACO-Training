/*
ID: CHN
PROG: job
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> x, y;
vector<int> ans1, ans2;

bool check(int mid, bool flag) {
    int tmp = 0;
    if (flag) {
        for (int i = 0; i < y.size(); ++i) tmp += mid / y[i];
    } else {
        for (int i = 0; i < x.size(); ++i) tmp += mid / x[i];
    }
    return tmp >= n;
}


int main() {
    freopen("job.in", "r", stdin);
    freopen("job.out", "w", stdout);
    int a, b, c;
    cin >> n >> a >> b;
    for (int i = 0; i < a; ++i) {
        cin >> c;
        x.push_back(c);
    }
    for (int i = 0; i < b; ++i) {
        cin >> c;
        y.push_back(c);
    }
    
    int l = 0, r = 100000;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid, false)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << r << " ";
    
    for (int i = 0; i < x.size(); ++i) {
        int tmp = x[i];
        while (tmp <= r) {
            ans1.push_back(tmp);
            tmp += x[i];
        }
    }
    sort(ans1.begin(), ans1.end());
    
    l = 0, r = 100000;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid, true)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    
    for (int i = 0; i < y.size(); ++i) {
        int tmp = y[i];
        while (tmp <= r) {
            ans2.push_back(tmp);
            tmp += y[i];
        }
    }
    sort(ans2.begin(), ans2.end());
    
    // ans1 or ans2 maybe larger than n
    int ans = 0;
    for (int i = 0; i < n; ++i) 
     if (ans1[i] + ans2[n-i-1] > ans) ans = ans1[i] + ans2[n-i-1];
    
    cout << ans << endl;
    
    return 0;
}
