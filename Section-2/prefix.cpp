/*
ID: CHN
PROG: prefix
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct node {
    int next[26];
    bool end;
};

int num = 1;
node tree[3010];
bool f[200100];

int build(const string &p) {
    int pos = 0;
    for (int i = 0; i < p.size(); ++i)
     if (tree[pos].next[p[i] - 'A'] != 0) {
         pos = tree[pos].next[p[i] - 'A'];
     } else {
         tree[pos].next[p[i] - 'A'] = num;
         pos = num++;
     }
    tree[pos].end = true;
    return 0;
}


int main() {
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    string p, q;
    while (cin >> p) {
        if (p == ".") break;
        build(p);
    }
    while (cin >> p) q += p;
    
    int ans = 0;
    f[0] = true;
    for (int i = 0; i < q.size(); ++i) {
        if (!f[i]) continue;
        int pos = 0;
        for (int j = 0; j < 10; ++j) {
            if (i + j >= q.size()) break;
            pos = tree[pos].next[q[i+j] - 'A'];
            if (pos == 0) break;
            if (tree[pos].end) {
                f[i+j+1] = true; 
                if (i + j + 1 > ans) ans = i + j + 1;
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
