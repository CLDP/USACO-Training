/*
ID: CHN
PROG: ariprog
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

bool z[125100];
vector<pair<int, int> > ans;

int main() {
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= m; ++i)
     for (int j = 0; j <= m; ++j) z[i * i + j * j] = true;
     
    int p = 2 * m * m;
    
    for (int i = 0; i < p; ++i)
     if (z[i]) {
         for (int j = 1; j < p; ++j) {
             if (i + j * (n-1) > p) break;
             if (z[i + j * (n-1)]) {
                 bool flag = true;
                 for (int k = 1; k < n; ++k) {
                     flag &= (z[i + j * k]);
                     if (!flag) break;
                 }
                 if (flag) ans.push_back(make_pair(j, i));
             }
         }
     }
    
    sort(ans.begin(), ans.end());
    if (ans.size() == 0) cout << "NONE" << endl;  
    for (int i = 0; i < ans.size(); ++i) 
     cout << ans[i].second << " " << ans[i].first << endl;
    
    return 0;
}
