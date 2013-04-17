/*
ID: CHN
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;



int main() {
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
    int n, s;
    cin >> n >> s;
    while (n) {
        ++s;
        int pal = 0;
        for (int i = 2; i <= 10; ++i) {
            int temp = s;
            vector<int> p;
            while (temp > 0) {
                p.push_back(temp % i);
                temp /= i;
            }
            bool flag = true;
            for (int j = 0; j < p.size() / 2; ++j)
             flag &= (p[j] == p[p.size() - 1 - j]);
            if (flag) ++pal;
            if (pal == 2) break;
        }
        if (pal == 2) {
            --n;
            cout << s << endl;
        }
    }
    
    return 0;
}
