/*
ID: CHN
PROG: wissqu
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

const int MX[9] = {0, -1, -1, -1, 0, 0, 1, 1, 1};
const int MY[9] = {0, -1, 0, 1, -1, 1, -1, 0, 1};

int ans;
int x[6][6];
int y[6], l[20];
bool z[6][6];
vector<pair<int, int> > p[6];
bool q[6][6][6];


bool check(int a, int b, int t) {
    for (int i = 0; i < 9; ++i)
     if (x[a + MX[i]][b + MY[i]] == t) return false;
    return true;
}


int change(int a, int b, int c, int d) {
    for (int k = 1; k < 9; ++k) {
        int r = a + MX[k], s = b + MY[k];
        if (z[r][s]) continue;
        if (q[r][s][d]) {
            q[r][s][d] = false;
            for (int i = 0; i < p[d].size(); ++i) 
             if (p[d][i].first == r && p[d][i].second == s) {
                 p[d].erase(p[d].begin() + i, p[d].begin() + i + 1);
                 break;
             }
        }
        if (check(r, s, c)) {
            q[r][s][c] = true;
            p[c].push_back(make_pair(0, 0));
            int i;
            for (i = p[c].size() - 2; i >= 0; --i)
             if ((p[c][i].first == r && p[c][i].second < s) || (p[c][i].first < r)) {
                 break;
             } else {
                 p[c][i+1] = p[c][i];
             }
             
            p[c][i+1] = make_pair(r, s);
        }
    }
    return 0;
}


int dfs(int c) {
    if (c == 16) {
        ++ans;
        if (ans == 1) {
            for (int i = 0; i < 16; ++i) {
                int a = l[i] / 10, b = l[i] % 10;
                cout << char(x[a][b] + 'A' - 1) << " " << a << " " << b << endl;
            }
        }
        return 0;
    }
    
    for (int k = 1; k <= 5; ++k) 
     if (y[k] > 0)
      for (int r = 0; r < p[k].size(); ++r) {
          int i = p[k][r].first, j = p[k][r].second;
          if (!q[i][j][k]) continue;
          if (!z[i][j]) {
              --y[k];
              int t = x[i][j];
              x[i][j] = k;
              z[i][j] = true;
              l[c] = i * 10 + j;
              change(i, j, t, k);
              dfs(c + 1);
              ++y[k];
              x[i][j] = t;
              z[i][j] = false;
              change(i, j, k, t);
          }
      }
      
    return 0;
}


int main() {
    freopen("wissqu.in", "r", stdin);
    freopen("wissqu.out", "w", stdout);
    char pp;
    for (int i = 1; i <= 4; ++i) 
     for (int j = 1; j <= 4; ++j) {
         cin >> pp;
         x[i][j] = pp - 'A' + 1;
     }
    
    y[1] = y[2] = y[3] = y[5] = 3;
    y[4] = 4;
    
    for (int i = 0; i <= 5; ++i) z[0][i] = z[5][i] = z[i][0] = z[i][5] = true;
    
    for (int i = 1; i <= 4; ++i)
     for (int j = 1; j <= 4; ++j)
      for (int k = 1; k <= 5; ++k)
       if (check(i, j, k)) {
           p[k].push_back(make_pair(i, j));
           q[i][j][k] = true;
       }
    
    for (int k = 0; k < p[4].size(); ++k) {
        int i = p[4][k].first, j = p[4][k].second;
        --y[4];
        int t = x[i][j];
        x[i][j] = 4;
        z[i][j] = true;
        l[0] = i * 10 + j;
        change(i, j, t, 4);
        dfs(1);
        ++y[4];
        x[i][j] = t;
        z[i][j] = false;
        change(i, j, 4, t);
    }
    
    cout << ans << endl;
    
    return 0;
}
