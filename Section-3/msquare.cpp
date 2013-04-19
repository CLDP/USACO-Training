/*
ID: CHN
PROG: msquare
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int x[8], y[8];
set<pair<int, int> > hash;

bool dfs(int a, string p) {
    int val = 0;
    for (int i = 0; i < 7; ++i) val = val * 10 + y[i];
    if (hash.find(make_pair(val, a)) != hash.end()) return false;
    hash.insert(make_pair(val, a));
    
    if (a == 0) {
        bool flag = true;
        for (int i = 0; i < 8; ++i) flag &= (x[i] == y[i]);
        if (flag) {
            cout << p.size() << endl;
            cout << p << endl;
            return true;
        }
        return false;
    }
    
    // Move A
    for (int i = 0; i < 4; ++i) swap(y[i], y[7-i]);
    if (dfs(a-1, p+'A')) return true;
    for (int i = 0; i < 4; ++i) swap(y[i], y[7-i]);
    
    // Move B
    int temp = y[3];
    for (int i = 2; i >= 0; --i) y[i+1] = y[i]; y[0] = temp;
    temp = y[4];
    for (int i = 4; i < 7; ++i) y[i] = y[i+1]; y[7] = temp;
    if (dfs(a-1, p+'B')) return true;
    temp = y[0]; 
    for (int i = 0; i < 3; ++i) y[i] = y[i+1]; y[3] = temp;
    temp = y[7];
    for (int i = 7; i > 4; --i) y[i] = y[i-1]; y[4] = temp;
    
    // Move C
    temp = y[1];
    y[1] = y[6]; y[6] = y[5]; y[5] = y[2]; y[2] = temp;
    if (dfs(a-1, p+'C')) return true;
    temp = y[1];
    y[1] = y[2]; y[2] = y[5]; y[5] = y[6]; y[6] = temp;
    return false;
}

int main() {
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);
    for (int i = 0; i < 8; ++i) {
        cin >> x[i];
        y[i] = i+1;
    }
    
    for (int i = 0; ; ++i) 
     if (dfs(i, "")) break;
    
    return 0;
}
