/*
ID: CHN
PROG: ditch
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 211;
const int INF = 1000000000;


int n;
vector<pair<int, int> > x[MAXN];
vector<pair<int, int> >::iterator fan[MAXN];
int fa[MAXN], ff[MAXN], h[MAXN], hh[MAXN];


int max_flow(int s, int t) {
    int i = 0, now, ans = 0;
    
    memset(ff, 0, sizeof(ff));
    memset(fa, 0, sizeof(fa));
    memset(h,  0, sizeof(h));
    memset(hh, 0, sizeof(hh));
    hh[0] = n;
    
    i = s;
    now = INF;
    
    while (h[s] < n) {
        ff[i] = now;
        bool flag = false;
        vector<pair<int, int> >::iterator p = x[i].begin();
        while (p != x[i].end()) {
            if (p->second > 0 && h[p->first] + 1 == h[i]) {
                flag = true;
                if (p->second < now) now = p->second;
                fa[p->first] = i;
                fan[p->first] = p;
                i = p->first;
                if (i == t) {
                    ans += now;
                    while (i != s) {
                        int tmp = i;
                        p = fan[i];
                        i = fa[i];
                        p->second -=now;
                        x[tmp].push_back(make_pair(i, now));
                    }
                    now = INF;
                }
                break;
            }
            ++p;
        }
        if (flag) continue;
        
        int min = n-1;
        p = x[i].begin();
        while (p != x[i].end()) {
            if (p->second > 0 && h[p->first] < min) min = h[p->first];
            ++p;
        }
        
        --hh[h[i]];
        if (hh[h[i]] == 0) break;
        h[i] = min + 1;
        ++hh[h[i]];
        if (i != s) {
            i = fa[i];
            now = ff[i];
        }
    }
    
    return ans;
}


int main() {
    freopen("ditch.in", "r", stdin);
    freopen("ditch.out", "w", stdout);
    int a, b, c, m;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        x[a].push_back(make_pair(b, c));
    }
    
    cout << max_flow(1, n) << endl;
    
    return 0;
}
