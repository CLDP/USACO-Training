/*
ID: CHN
PROG: ride
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;


int main() {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    string p, q;
    cin >> p >> q;
    int a, b;
    a = b = 1;
    for (int i = 0; i < p.size(); ++i) a *= (p[i] - 'A' + 1);
    for (int i = 0; i < q.size(); ++i) b *= (q[i] - 'A' + 1);
    if ((a - b) % 47 == 0) 
        cout << "GO" << endl;
    else 
        cout << "STAY" << endl;
        
    return 0;
}
