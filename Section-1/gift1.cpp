/*
ID: CHN
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
using namespace std;

vector<string> name;
map<string, int> initial;
map<string, int> final;

int main() {
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    int n;
    cin >> n;
    string p, q;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        initial[p] = 0;
        final[p] = 0;
        name.push_back(p);
    }
    
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        cin >> a >> b;
        initial[p] = a;
        if (b == 0)
            final[p] += a;
        else 
            final[p] += a % b;
        for (int j = 0; j < b; ++j) {
            cin >> q;
            final[q] += a / b;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << name[i] << " " << final[name[i]] - initial[name[i]] << endl;
    }
        
    return 0;
}
