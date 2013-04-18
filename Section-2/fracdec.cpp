/*
ID: CHN
PROG: fracdec
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int newline;
map<int, int> previous;


int print(char p) {
    cout << p;
    ++newline;
    if (newline == 76) {
        newline = 0;
        cout << endl;
    }
}


int main() {
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    cout << n / d;
    if (n % d == 0) {
        cout << ".0" << endl;
        return 0;
    }
    int temp = n / d;
    if (temp == 0) {
        ++newline;
    } else
    while (temp > 0) {
        ++newline;
        temp /= 10;
    }
    print('.');
    string p;
    n = n % d;
    int pos = 0;
    previous[n % d] = -1;
    while (true) {
        n *= 10;
        if (n == 0) {
            for (int i = 0; i < p.size(); ++i) print(p[i]);
            cout << endl;
            break;
        }
        if (previous.find(n % d) != previous.end()) {
           for (int i = 0; i <= previous[n % d]; ++i) print(p[i]);
           print('(');
           for (int i = previous[n % d]+1; i < p.size(); ++i) print(p[i]);
           print('0' + (n / d));
           print(')');
           cout << endl;
           break;
        }
        p += (char)((n / d) + '0');
        previous[n % d] = pos;
        ++pos;
        n = n % d;
    }
    
    return 0;
}
