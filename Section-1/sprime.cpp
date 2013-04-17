/*
ID: CHN
PROG: sprime
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

int n;


bool isprime(int a) {
    for (int i = 2; i <= sqrt(a); ++i) {
        if (a % i == 0) return false;
    }
    return true;
}


int dfs(int a, int b) {
    if (!isprime(b)) return 0;

    if (a == n) {
        cout << b << endl; 
        return 0;
    }
    
    if (a != 0) dfs(a+1, b * 10 + 1);
    if (a == 0) dfs(a+1, b * 10 + 2);
    dfs(a+1, b * 10 + 3);
    dfs(a+1, b * 10 + 5);
    dfs(a+1, b * 10 + 7);
    dfs(a+1, b * 10 + 9);
}



int main() {
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
    cin >> n;
    dfs(0, 0);
    
    return 0;
}
