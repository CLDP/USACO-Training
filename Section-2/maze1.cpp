/*
ID: CHN
PROG: maze1
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int MX[4] = {-1, 0, 1, 0};
const int MY[4] = {0, 1, 0, -1};


struct node {
    pair<int, int> pos;
    int len;
};


int w, h;
// north, east, south, west
bool x[110][110][4];
bool z[110][110];

int main() {
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);
    cin >> w >> h;
    string p;
    // Get the nonsense end line
    getline(cin, p);
    pair<int, int> out1, out2;
    for (int i = 0; i < 2 * h + 1; ++i) 
     if (i & 1) {
         getline(cin, p);
         // vertical walls
         for (int j = 0; j < 2 * w + 1; ++j) {
             if (j & 1) continue;
             if (p[j] == ' ') {
                 if (j == 0 || j == 2 * w) {
                     out1 = out2;
                     if (j == 0)
                         out2 = make_pair(i / 2, 0);
                     else
                         out2 = make_pair(i / 2, w-1);
                 } else {
                     x[i / 2][j / 2][3] = true;
                     x[i / 2][j / 2 - 1][1] = true;
                 }
             }
         }
     } else {
         getline(cin, p);
         // horizontal walls
         for (int j = 0; j < 2 * w + 1; ++j) {
             if (!(j & 1)) continue;
             if (p[j] == ' ') {
                 if (i == 0 || i == 2 * h) {
                     out1 = out2;
                     if (i == 0)
                         out2 = make_pair(0, j / 2);
                     else
                         out2 = make_pair(h-1, j / 2);
                 } else {
                     x[i / 2][j / 2][0] = true;
                     x[i / 2 - 1][j / 2][2] = true;
                 }
             }
         }
     }
    
    queue<node> que;
    node temp;
    temp.len = 1;
    temp.pos = out1;
    que.push(temp);
    z[out1.first][out1.second] = true;
    temp.pos = out2;
    que.push(temp);
    z[out2.first][out2.second] = true;
    
    int ans = 0;
    while (!que.empty()) {
        temp = que.front();
        que.pop();
        if (temp.len > ans) ans = temp.len;
        for (int i = 0; i < 4; ++i) {
            if (!x[temp.pos.first][temp.pos.second][i]) continue;
            temp.pos.first += MX[i];
            temp.pos.second += MY[i];
            ++temp.len;
            if (!z[temp.pos.first][temp.pos.second]) {
                que.push(temp);
                z[temp.pos.first][temp.pos.second] = true;
            }
            temp.pos.first -= MX[i];
            temp.pos.second -= MY[i];
            --temp.len;
        }
    }
    cout << ans << endl;
    
    return 0;
}
