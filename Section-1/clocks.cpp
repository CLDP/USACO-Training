/*
ID: CHN
PROG: clocks
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

const int move[9][9] = {{1, 1, 0, 1, 1, 0, 0, 0, 0},
                        {1, 1, 1, 0, 0, 0, 0, 0, 0},
                        {0, 1, 1, 0, 1, 1, 0, 0, 0},
                        {1, 0, 0, 1, 0, 0, 1, 0, 0},
                        {0, 1, 0, 1, 1, 1, 0, 1, 0},
                        {0, 0, 1, 0, 0, 1, 0, 0, 1},
                        {0, 0, 0, 1, 1, 0, 1, 1, 0},
                        {0, 0, 0, 0, 0, 0, 1, 1, 1},
                        {0, 0, 0, 0, 1, 1, 0, 1, 1}};

int x[9];
int ans[9];

bool dfs(int a, int b) {
    bool flag = true;
    for (int i = 0; i < 9; ++i) flag &= (x[i] == 0);
    if (flag) return true;
    if (a >= 9) return false;
    
    if (b < 4) {
        ++ans[a];
        for (int i = 0; i < 9; ++i) 
         if (move[a][i]) x[i] = (x[i] + 3) % 12;
        if (dfs(a, b+1)) return true;
        --ans[a];
        for (int i = 0; i < 9; ++i) 
         if (move[a][i]) x[i] = (x[i] + 9) % 12;
    }
    dfs(a+1, 0);
}


int main() {
    freopen("clocks.in", "r", stdin);
    freopen("clocks.out", "w", stdout);
    
    for (int i = 0; i < 9; ++i) {
        cin >> x[i];
        x[i] %= 12;
    }
    
    dfs(0, 0);
    
    int anst = 0;
    for (int i = 0; i < 9; ++i) {
        if (ans[i] == 4) ans[i] = 0;
        anst += ans[i];
    }
    for (int i = 0; i < 9; ++i) 
     while (ans[i] > 0) {
         cout << i+1;
         --anst;
         --ans[i];
         if (anst > 0) 
             cout << " ";
         else
             cout << endl;
     }
    
    return 0;
}
