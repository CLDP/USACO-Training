/*
ID: CHN
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    freopen("calfflac.in", "r", stdin);
    freopen("calfflac.out", "w", stdout);
    string p, q, r;
    vector<int> q0;
    while (getline(cin, r)) {
        p += r;
        p += '\n';
    }
    for (int i = 0; i < p.size(); ++i)
     if (p[i] >= 'a' && p[i] <= 'z') {
         q += p[i];
         q0.push_back(i);
     } else
     if (p[i] >= 'A' && p[i] <= 'Z') {
         q += p[i] - 'A' + 'a';
         q0.push_back(i);
     }
    
    int ans = 0, pos;
    for (int i = 0; i < q.size(); ++i) {
        int j = 0;
        while (i - j >= 0 && i + j < q.size()) {
            if (q[i-j] == q[i+j]) 
                ++j;
            else
                break;
        }
        --j;
        if (j * 2 + 1 > ans) {
            ans = j * 2 + 1;
            pos = i;
        }
        
        j = 0;
        while (i - j - 1 >= 0 && i + j < q.size()) {
            if (q[i-j-1] == q[i+j]) 
                ++j;
            else
                break;
        }
        --j;
        if (j * 2 + 2 > ans) {
            ans = j * 2 + 2;
            pos = i;
        }
    }
    
    cout << ans << endl;
    if (ans % 2 == 0) {
        for (int i = q0[pos - (ans / 2)]; i <= q0[pos + (ans / 2) - 1]; ++i) cout << p[i];
    } else {
        for (int i = q0[pos - (ans / 2)]; i <= q0[pos + (ans / 2)]; ++i) cout << p[i];
    }
    cout << endl;
    
    return 0;
}
