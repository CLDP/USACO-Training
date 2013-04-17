/*
ID: CHN
PROG: packrec
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

pair<int, int> rec[4], reco[4];
int ans = 1000000;
bool f[2501][2501];

int get() {
    int a, b;
    // 1
    a = b = 0;
    for (int i = 0; i < 4; ++i) {
        a += rec[i].first;
        b = max(b, rec[i].second);
    }
    if (a * b == ans) {
        f[a][b] = true;
        f[b][a] = true;
    }
    if (a * b < ans) ans = a * b;
    
    
    // 2
    a = b = 0;
    for (int i = 0; i < 3; ++i) {
        a += rec[i].first;
        b = max(b, rec[i].second);
    }
    a = max(a, rec[3].first);
    b += rec[3].second;
    if (a * b == ans) {
        f[a][b] = true;
        f[b][a] = true;
    }
    if (a * b < ans) ans = a * b;
    
    // 3
    a = rec[0].first + rec[1].first + rec[2].first;
    a = max(a, rec[3].first + rec[2].first);
    b = max(rec[0].second, rec[1].second);
    b += rec[3].second;
    b = max(b, rec[2].second);
    if (a * b == ans) {
        f[a][b] = true;
        f[b][a] = true;
    }
    if (a * b < ans) ans = a * b;
    
    // 4
    a = rec[0].first + max(rec[1].first, rec[2].first) + rec[3].first;
    b = max(rec[0].second, rec[3].second);
    b = max(b, rec[1].second + rec[2].second);
    if (a * b == ans) {
        f[a][b] = true;
        f[b][a] = true;
    }
    if (a * b < ans) ans = a * b;
    
    // 5
    a = max(rec[0].first + rec[1].first, rec[2].first + rec[3].first);
    a = max(rec[1].first + rec[2].first, a);
    b = max(rec[0].second + rec[2].second, rec[1].second + rec[3].second);
    b = max(rec[0].second + rec[3].second, b);
    if (a * b == ans) {
        f[a][b] = true;
        f[b][a] = true;
    }
    if (a * b < ans) ans = a * b;
}


int main() {
    freopen("packrec.in", "r", stdin);
    freopen("packrec.out", "w", stdout);
    
    for (int i = 0; i < 4; ++i) {
        cin >> rec[i].first >> rec[i].second;
        reco[i] = rec[i];
    }
    
    vector<int> pem;
    pem.push_back(0);
    pem.push_back(1);
    pem.push_back(2);
    pem.push_back(3);
    
    for (int i = 0; i < 24; ++i) {
        rec[0] = reco[pem[0]];
        rec[1] = reco[pem[1]];
        rec[2] = reco[pem[2]];
        rec[3] = reco[pem[3]];
        for (int i0 = 0; i0 < 2; ++i0) {
            for (int i1 = 0; i1 < 2; ++i1) {
                for (int i2 = 0; i2 < 2; ++i2) {
                    for (int i3 = 0; i3 < 2; ++i3) {
                        get();
                        swap(rec[3].first, rec[3].second);
                    }
                    swap(rec[2].first, rec[2].second);
                }
                swap(rec[1].first, rec[1].second);
            }
            swap(rec[0].first, rec[0].second);
        }
        next_permutation(pem.begin(), pem.end());
    }
    
    memset(f, 0, sizeof(f));
    
    for (int i = 0; i < 24; ++i) {
        rec[0] = reco[pem[0]];
        rec[1] = reco[pem[1]];
        rec[2] = reco[pem[2]];
        rec[3] = reco[pem[3]];
        for (int i0 = 0; i0 < 2; ++i0) {
            for (int i1 = 0; i1 < 2; ++i1) {
                for (int i2 = 0; i2 < 2; ++i2) {
                    for (int i3 = 0; i3 < 2; ++i3) {
                        get();
                        swap(rec[3].first, rec[3].second);
                    }
                    swap(rec[2].first, rec[2].second);
                }
                swap(rec[1].first, rec[1].second);
            }
            swap(rec[0].first, rec[0].second);
        }
        next_permutation(pem.begin(), pem.end());
    }
    
    cout << ans << endl;
    for (int i = 1; i <= sqrt(ans) + 0.001; ++i) 
     if (f[i][ans / i]) cout << i << " " << ans / i << endl;
    
    return 0;
}
