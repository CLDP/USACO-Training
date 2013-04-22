/*
ID: CHN
PROG: race3
LANG: C++
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 51;

bool x[MAXN][MAXN], f[MAXN][MAXN];


int main() {
    freopen("race3.in", "r", stdin);
    freopen("race3.out", "w", stdout);
    int n = 0, a;
    
    cin >> a;
    while (a != -1) {
        while (a != -2) {
            x[n][a] = true;
            cin >> a;
        }
        ++n;
        cin >> a;
    }
    
    for (int i = 0; i < n; ++i) x[i][i] = true;
    
    vector<int> ans;
    
    for (int t = 1; t < n-1; ++t) {
        for (int i = 0; i < n; ++i)
         for (int j = 0; j < n; ++j) f[i][j] = x[i][j];
        
        for (int i = 0; i < n; ++i) f[i][t] = f[t][i] = false;
        
        for (int k = 0; k < n; ++k)
         for (int i = 0; i < n; ++i)
          for (int j = 0; j < n; ++j) 
           if (f[i][k] && f[k][j]) f[i][j] = true;
        
        if (!f[0][n-1]) ans.push_back(t);
    }
    
    cout << ans.size();
    for (int i = 0; i < ans.size(); ++i) cout << " " << ans[i];
    cout << endl;
 
    vector<int> ans2;
    
    for (int tt = 0; tt < ans.size(); ++tt) {
        int t = ans[tt];
        
        for (int i = 0; i < n; ++i)
         for (int j = 0; j < n; ++j) f[i][j] = x[i][j] | x[j][i];
         
        for (int i = 0; i < n; ++i) f[i][t] = f[t][i] = false;
        
        for (int k = 0; k < n; ++k)
         for (int i = 0; i < n; ++i)
          for (int j = 0; j < n; ++j) 
           if (f[i][k] && f[k][j]) f[i][j] = true;
       
        if (f[0][n-1]) continue;
        
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (f[0][i] && x[t][i]) flag = false;
        }
        
        if (!flag) continue;
        
        ans2.push_back(t);
    }
    
    cout << ans2.size();
    for (int i = 0; i < ans2.size(); ++i) cout << " " << ans2[i];
    cout << endl;
    
    return 0;
}
