/*
ID: CHN
PROG: preface
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

const char LETTER[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
const int PAGE[7] = {1, 5, 10, 50, 100, 500, 1000};

int n;
int ans[7];
int f[4000][7];


int dp(int a) {
    if (a >= 1000) {
        f[a][6] = a / 1000;
        for (int i = 0; i < 7; ++i) f[a][i] += f[a % 1000][i];
    } else 
    if (a >= 900) {
        f[a][4] = f[a][6] = 1;
        for (int i = 0; i < 7; ++i) f[a][i] += f[a - 900][i];
    } else
    if (a >= 500) {
        f[a][5] = 1;
        for (int i = 0; i < 7; ++i) f[a][i] += f[a - 500][i];
    } else 
    if (a >= 400) {
        f[a][4] = f[a][5] = 1;
        for (int i = 0; i < 7; ++i) f[a][i] += f[a - 400][i];
    } else 
    if (a >= 100) {
        f[a][4] = a / 100;
        for (int i = 0; i < 7; ++i) f[a][i] += f[a % 100][i];
    } else 
    if (a >= 90) {
        f[a][2] = f[a][4] = 1;
        for (int i = 0; i < 7; ++i) f[a][i] += f[a - 90][i];
    } else 
    if (a >= 50) {
        f[a][3] = 1;
        for (int i = 0; i < 7; ++i) f[a][i] += f[a - 50][i];
    } else
    if (a >= 40) {
        f[a][2] = f[a][3] = 1;
        for (int i = 0; i < 7; ++i) f[a][i] += f[a - 40][i];
    } else 
    if (a >= 10) {
        f[a][2] = a / 10;
        for (int i = 0; i < 7; ++i) f[a][i] += f[a % 10][i];
    } else
    if (a >= 9) {
        f[a][0] = f[a][2] = 1;
        for (int i = 0; i < 7; ++i) f[a][i] += f[a - 9][i];
    } else
    if (a >= 5) {
        f[a][1] = 1;
        for (int i = 0; i < 7; ++i) f[a][i] += f[a - 5][i];
    } else 
    if (a >= 4) {
        f[a][0] = f[a][1] = 1;
        for (int i = 0; i < 7; ++i) f[a][i] += f[a - 4][i];
    } else {
        f[a][0] = a;
    }
    
    for (int i = 0; i < 7; ++i) ans[i] += f[a][i];
}

int main() {
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) dp(i);
    
    for (int i = 0; i < 7; ++i)
     if (ans[i] > 0) cout << LETTER[i] << " " << ans[i] << endl;
    
    return 0;
}
