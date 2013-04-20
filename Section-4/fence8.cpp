/*
ID: CHN
PROG: fence8
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, total;
int x[53], y[1030], sum[1030];


bool dfs(int waste, int a, int b, int now) {
    if (a == 0) return true;
    
    for (int i = b; i <= n; ++i)
     if (x[i] >= y[a]) {
         x[i] -= y[a];
         int temp;
         if (x[i] < y[1]) {
             temp = waste + x[i];
             // If you have already waste too much, pruning
             if (temp + sum[now] > total) {
                 x[i] += y[a];
                 continue;
             }
         } else {
             temp = waste;
         }
         int j;
         // If two rails are of same length, they must keep the order
         if (y[a] == y[a-1]) 
             j = i;
         else 
             j = 1;
             
         if (dfs(temp, a-1, j, now)) {
             x[i] += y[a];
             return true;
         }
         
         x[i] += y[a];
     }
    
    return false;
}


int main() {
    freopen("fence8.in", "r", stdin);
    freopen("fence8.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> y[i];
    sort(x+1, x+n+1);
    sort(y+1, y+m+1);
    
    // Absolutely no solution
    if (y[1] > x[n]) {
        cout << 0 << endl;
        return 0;
    }
    
    // First several boards cannot be used
    while (x[1] < y[1]) {
        for (int j = 1; j < n; ++j) x[j] = x[j+1];
        --n;
    }
    
    // Total length of boards
    for (int i = 1; i <= n; ++i) total += x[i];
    
    // Last few rails cannot be made
    while (y[m] > x[n]) --m;
    
    // Get the sum
    for (int i = 1; i <= m; ++i) sum[i] = sum[i-1] + y[i];
         
    // Last few rails cannot be made
    while (sum[m] > total) --m;
    
    int l = 1, r = m;
    // Something strange happens
    if (r < l) {
        cout << 0 << endl;
        return 0;
    }
    
    int ans = 0;
    // Find the solution by binary search
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (dfs(0, mid, 1, mid)) {
            if (mid > ans) ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
