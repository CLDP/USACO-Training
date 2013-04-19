/*
ID: CHN
PROG: fact4
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


    
int main() {
    freopen("fact4.in", "r", stdin);
    freopen("fact4.out", "w", stdout);
    int n, ans = 1;
    int a = 0, b = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int temp = i;
        while (temp % 5 == 0) {
            temp /= 5;
            ++a;
        }
        while (temp % 2 == 0) {
            temp /= 2;
            ++b;
        }
        ans *= temp;
        ans %= 10;
    }
    
    for (int i = 0; i < b - a; ++i) ans = (ans * 2) % 10;
    
    cout << ans << endl;
    
    return 0;
}
