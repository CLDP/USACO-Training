/*
ID: CHN
PROG: cowcycle
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const double INF = 1e10;

int n, m, a, b, c, d;
int ans1[11], ans2[11];
int tmp1[11], tmp2[11];
double ans = INF;


int dfs(int x1, int x2, int a1, int c1) {
    if (x2 == m) {
        if (tmp1[n-1] * tmp2[m-1] < 3 * tmp1[0] * tmp2[0]) return 0;
        vector<double> ratio;
        for (int i = 0; i < n; ++i)
         for (int j = 0; j < m; ++j) ratio.push_back(1.0 * tmp1[i] / tmp2[j]);
        sort(ratio.begin(), ratio.end());
        double average = (ratio[ratio.size() - 1] - ratio[0]) / (ratio.size() - 1);
        
        double variance = 0;
        for (int i = 0; i < ratio.size() - 1; ++i) 
            variance += (average - ratio[i+1] + ratio[i]) * (average - ratio[i+1] + ratio[i]);
        variance /= (ratio.size() - 1);
        
        if (variance < ans) {
            ans = variance;
            for (int i = 0; i < n; ++i) ans1[i] = tmp1[i];
            for (int i = 0; i < m; ++i) ans2[i] = tmp2[i];
        }
        return 0;
    }
    
    // The main idea for this problem is: don't worry, brute force!!
    // The test data are much smaller than the range given in problem statement!!
    // Even the standard solution given cannot pass the extreme cases!!
    if (x1 == n) {
        if (x2 == 0) {
            if (tmp1[n-1] * d < 3 * tmp1[0] * c) return 0;
        } else {
            if (tmp1[n-1] * d < 3 * tmp1[0] * tmp2[0]) return 0;
        }
        for (int i = c1; i <= d + 1 - (m - x2); ++i) {
            tmp2[x2] = i;
            dfs(x1, x2 + 1, a1, i + 1);
        }
    } else {
        if (b * d < 3 * tmp1[0] * c) return 0;
        for (int i = a1; i <= b + 1 - (n - x1); ++i) {
            tmp1[x1] = i;
            dfs(x1 + 1, x2, i + 1, c1);
        }
    }
    return 0;
}


int main() {
    freopen("cowcycle.in", "r", stdin);
    freopen("cowcycle.out", "w", stdout);
    cin >> n >> m >> a >> b >> c >> d;
    dfs(0, 0, a, c);
    
    for (int i = 0; i < n-1; ++i) cout << ans1[i] << " ";
    cout << ans1[n-1] << endl;
    for (int i = 0; i < m-1; ++i) cout << ans2[i] << " ";
    cout << ans2[m-1] << endl;
     
    return 0;
}
