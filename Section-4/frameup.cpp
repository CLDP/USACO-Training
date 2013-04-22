/*
ID: CHN
PROG: frameup
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, nn;
vector<int> z[26];
bool cz[26], tmp[26];
int d[26];
vector<string> anst;

int dfs(int a, string ans) {
    if (a == nn) {
        reverse(ans.begin(), ans.end());
        anst.push_back(ans);
        return 0;
    }
    for (int i = 0; i < 26; ++i)
     if (cz[i] && d[i] == 0 && !tmp[i]) {
         tmp[i] = true;
         for (int j = 0; j < z[i].size(); ++j) --d[z[i][j]];
         dfs(a+1, ans + (char)(i + 'A'));
         for (int j = 0; j < z[i].size(); ++j) ++d[z[i][j]];
         tmp[i] = false;
     }
    return 0;
}


int main() {
    freopen("frameup.in", "r", stdin);
    freopen("frameup.out", "w", stdout);
    cin >> n >> m;
    vector<string> x;
    for (int i = 0; i < n; ++i) {
        string p;
        cin >> p;
        x.push_back(p);
        for (int j = 0; j < m; ++j)
         if (p[j] != '.') cz[p[j] - 'A'] = true;
    }
    
    for (int i = 0; i < 26; ++i) nn += cz[i];
    
    int l, r, a, b;
    for (int i = 0; i < 26; ++i)
     if (cz[i]) {
        l = m, r = -1;
        a = n, b = -1;
        for (int j = 0; j < n; ++j) 
         for (int k = 0; k < m; ++k) 
          if (x[j][k] == (char)('A' + i)) {
              if (k < l) l = k;
              if (k > r) r = k;
              if (j < a) a = j;
              if (j > b) b = j;
          }
        
        for (int j = a; j <= b; ++j) {
            if (x[j][l] != (char)('A' + i)) z[x[j][l] - 'A'].push_back(i);
            if (x[j][r] != (char)('A' + i)) z[x[j][r] - 'A'].push_back(i);
        }
        
        for (int j = l+1; j <= r-1; ++j) {
            if (x[a][j] != (char)('A' + i)) z[x[a][j] - 'A'].push_back(i);
            if (x[b][j] != (char)('A' + i)) z[x[b][j] - 'A'].push_back(i);
        }
    }
    
    for (int i = 0; i < 26; ++i) 
     if (cz[i]) {
        sort(z[i].begin(), z[i].end());
        z[i].erase(unique(z[i].begin(), z[i].end()), z[i].end());
     }
    
    
    for (int i = 0; i < 26; ++i)
     if (cz[i]) {
        for (int j = 0; j < z[i].size(); ++j) ++d[z[i][j]];
     }
    
    dfs(0, "");
    
    sort(anst.begin(), anst.end());
    
    for (int i = 0; i < anst.size(); ++i) cout << anst[i] << endl;
    
    return 0;
}
