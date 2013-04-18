/*
ID: CHN
PROG: lamps
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

int n, c;
vector<string> ans[16];
vector<int> on, off;
bool lamp[101];

bool check(string s) {
    for (int i = 0; i < on.size(); ++i)
     if (s[on[i]] == '0') return false;
    for (int i = 0; i < off.size(); ++i)
     if (s[off[i]] == '1') return false;
    return true;
}


int main() {
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
    cin >> n >> c;
    for (int i = 0; i < n; ++i) lamp[i] = true;
    int a;
    while (true) {
        cin >> a;
        if (a == -1) break;
        on.push_back(a-1);
    }
    while (true) {
        cin >> a;
        if (a == -1) break;
        off.push_back(a-1);
    }
    
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                // not change 3k+1
                string s;
                for (int p = 0; p < n; ++p)
                 if (lamp[p]) s += '1'; else s += '0';
                
                if (check(s)) ans[i * 8 + j * 4 + k * 2].push_back(s);
                for (int p = 0; p < n; p += 3) lamp[p] = !lamp[p];
                
                // change 3k+1
                s = "";
                for (int p = 0; p < n; ++p)
                 if (lamp[p]) s += '1'; else s += '0';
                if (check(s)) ans[i * 8 + j * 4 + k * 2 + 1].push_back(s);
                for (int p = 0; p < n; p += 3) lamp[p] = !lamp[p];
            
                for (int p = 0; p < n; p += 2) lamp[p] = !lamp[p];
            }
            for (int p = 1; p < n; p += 2) lamp[p] = !lamp[p];
        }
        for (int p = 0; p < n; ++p) lamp[p] = !lamp[p];
    }
    
    vector<string> anst;
    if (c == 0) {
        anst = ans[0];
    } else
    if (c == 1) {
        for (int i = 0; i < ans[1].size(); ++i) anst.push_back(ans[1][i]);
        for (int i = 0; i < ans[2].size(); ++i) anst.push_back(ans[2][i]);
        for (int i = 0; i < ans[4].size(); ++i) anst.push_back(ans[4][i]);
        for (int i = 0; i < ans[8].size(); ++i) anst.push_back(ans[8][i]);
    } else 
    if (c == 2) {
        for (int i = 0; i < ans[0].size(); ++i) anst.push_back(ans[0][i]);
        for (int i = 0; i < ans[3].size(); ++i) anst.push_back(ans[3][i]);
        for (int i = 0; i < ans[5].size(); ++i) anst.push_back(ans[5][i]);
        for (int i = 0; i < ans[6].size(); ++i) anst.push_back(ans[6][i]);
        for (int i = 0; i < ans[9].size(); ++i) anst.push_back(ans[9][i]);
        for (int i = 0; i < ans[10].size(); ++i) anst.push_back(ans[10][i]);
        for (int i = 0; i < ans[12].size(); ++i) anst.push_back(ans[12][i]);
    } else
    if (c % 2 == 1) {
        for (int i = 0; i < ans[1].size(); ++i) anst.push_back(ans[1][i]);
        for (int i = 0; i < ans[2].size(); ++i) anst.push_back(ans[2][i]);
        for (int i = 0; i < ans[4].size(); ++i) anst.push_back(ans[4][i]);
        for (int i = 0; i < ans[8].size(); ++i) anst.push_back(ans[8][i]);
        for (int i = 0; i < ans[7].size(); ++i) anst.push_back(ans[7][i]);
        for (int i = 0; i < ans[11].size(); ++i) anst.push_back(ans[11][i]);
        for (int i = 0; i < ans[13].size(); ++i) anst.push_back(ans[13][i]);
        for (int i = 0; i < ans[14].size(); ++i) anst.push_back(ans[14][i]);
    } else 
    if (c % 2 == 0) {
        for (int i = 0; i < ans[0].size(); ++i) anst.push_back(ans[0][i]);
        for (int i = 0; i < ans[3].size(); ++i) anst.push_back(ans[3][i]);
        for (int i = 0; i < ans[5].size(); ++i) anst.push_back(ans[5][i]);
        for (int i = 0; i < ans[6].size(); ++i) anst.push_back(ans[6][i]);
        for (int i = 0; i < ans[9].size(); ++i) anst.push_back(ans[9][i]);
        for (int i = 0; i < ans[10].size(); ++i) anst.push_back(ans[10][i]);
        for (int i = 0; i < ans[12].size(); ++i) anst.push_back(ans[12][i]);
        for (int i = 0; i < ans[15].size(); ++i) anst.push_back(ans[15][i]);
    } 
    
    sort(anst.begin(), anst.end());
    
    if (anst.size() > 0) {
        for (int i = 0; i < anst.size(); ++i) {
            if (i == 0 || anst[i] != anst[i-1]) cout << anst[i] << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}
