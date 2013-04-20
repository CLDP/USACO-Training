/*
ID: CHN
PROG: camelot
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXR = 32;
const int MAXC = 28;
const int INF = 100000000;
const int KX[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int KY[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int NX[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int NY[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

struct node {
    int x, y, len;
};


int n, m;
int z[MAXR][MAXC];
int d[MAXR][MAXC][MAXR][MAXC];
pair<int, int> king;
vector<pair<int, int> > knight;


bool check(int a, int b) {
    if (a < 1 || a > n) return false;
    if (b < 1 || b > m) return false;
    return true;
}


int main() {
    freopen("camelot.in", "r", stdin);
    freopen("camelot.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
     for (int j = 1; j <= m; ++j) {
         for (int k = 1; k <= n; ++k)
          for (int l = 1; l <= m; ++l) d[i][j][k][l] = INF;
         queue<node> que;
         node temp;
         temp.x = i;
         temp.y = j;
         temp.len = 0;
         que.push(temp);
         memset(z, 0, sizeof(z));
         z[i][j] = true;
         while (!que.empty()) {
             int a = que.front().x, b = que.front().y, c = que.front().len;
             que.pop();
             d[i][j][a][b] = c;
             for (int k = 0; k < 8; ++k) {
                 if (check(a+NX[k], b+NY[k]) && !z[a+NX[k]][b+NY[k]]) {
                     z[a+NX[k]][b+NY[k]] = true;
                     temp.x = a + NX[k];
                     temp.y = b + NY[k];
                     temp.len = c + 1;
                     que.push(temp);
                 }
             }
         }
     }
    
    char p;
    int a;
    cin >> p >> a;
    king = make_pair(a, p - 'A' + 1);
    while (cin >> p >> a) knight.push_back(make_pair(a, p - 'A' + 1));
    
    int size = knight.size(), ans = INF;
    if (size == 0) {
        ans = 0;
    } else {
        for (int k = 1; k <= n; ++k)
         for (int l = 1; l <= m; ++l) {
             int addr = 0;
             for (int s = 0; s < size; ++s)
              addr += d[knight[s].first][knight[s].second][k][l];
              
             for (int r = 0; r < size; ++r) {
                int temp = d[knight[r].first][knight[r].second][king.first][king.second] + 
                           d[king.first][king.second][k][l];
                int tmp;
             
                for (int s = 0; s < 8; ++s) 
                 if (check(king.first + KX[s], king.second + KY[s])) {
                     tmp = d[knight[r].first][knight[r].second][king.first + KX[s]][king.second + KY[s]];
                     tmp += d[king.first + KX[s]][king.second + KY[s]][k][l];
                     tmp += 1;
                     if (tmp < temp) temp = tmp;
                 }
                 
                for (int s1 = 0; s1 < 8; ++s1)
                 for (int s2 = 0; s2 < 8; ++s2)
                  if (king.first + KX[s1] + KX[s2] == knight[r].first &&
                      king.second + KY[s2] + KY[s2] == knight[r].second) {
                      tmp = 2 + d[knight[r].first][knight[r].second][k][l];
                      if (tmp < temp) temp = tmp;
                  }
                
                temp += (addr - d[knight[r].first][knight[r].second][k][l]);
                if (temp < ans) ans = temp; 
             }
         }
    }
    
    cout << ans << endl;
    
    return 0;
}
