/*
ID: CHN
PROG: butter
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 810;
const int INF = 1000000000;

int n, m, p;
int y[MAXN], d[MAXN];
bool z[MAXN];
vector<pair<int, int> > x[MAXN];

int SPFA(int a) {
    for (int i = 1; i <= p; ++i) {
        z[i] = false;
        d[i] = INF;
    }
    queue<int> que;
    que.push(a);
    d[a] = 0;
    z[a] = true;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        z[t] = false;
        for (int i = 0; i < x[t].size(); ++i) 
         if (x[t][i].second + d[t] < d[x[t][i].first]) {
             d[x[t][i].first] = x[t][i].second + d[t];
             if (!z[x[t][i].first]) {
                 z[x[t][i].first] = true;
                 que.push(x[t][i].first);
             }
         }
    }
}


int main() {
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);
    int a, b, c;
    cin >> n >> p >> m;
    for (int i = 0; i < n; ++i) cin >> y[i];
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        x[a].push_back(make_pair(b, c));
        x[b].push_back(make_pair(a, c));
    }
    
    int ans = INF;
    for (int i = 1; i <= p; ++i) {
        SPFA(i);
        int temp = 0;
        for (int j = 0; j < n; ++j) temp += d[y[j]];
        if (temp < ans) ans = temp;
    }
    
    cout << ans << endl;
    
    return 0;
}
