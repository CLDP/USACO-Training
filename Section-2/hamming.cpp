/*
ID: CHN
PROG: hamming
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

int n, b, d;
int x[100];


bool dfs(int a, int num) {
    if (num == n) return true;
    if (a == b) return false;
    bool flag = true;
    int diff, temp;
    for (int i = 0; i < num; ++i) {
        diff = 0;
        temp = x[i] ^ a;
        while (temp > 0) {
            ++diff;
            temp &= temp - 1;
        }
        flag &= (diff >= d);
        if (!flag) break;
    }
    if (flag) {
        x[num] = a;
        if (dfs(a+1, num+1)) return true;
    }
    if (dfs(a+1, num)) return true;
    return false;
}


int main() {
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
    cin >> n >> b >> d;
    b = 1 << b;
    
    dfs(0, 0);
    int i = 0;
    while (i < n) {
        cout << x[i];
        for (int j = 1; j < 10; ++j) 
         if (i+j < n) cout << " " << x[i+j];
        cout << endl;
        i += 10;
    }
    
    return 0;
}
