/*
ID: CHN
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;



int main() {
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    int n;
    cin >> n;
    
    for (int i = 1; i <= 300; ++i) {
        int a = i * i;
        vector<int> p;
        while (a > 0) {
            p.push_back(a % n);
            a /= n;
        }
        bool flag = true;
        for (int j = 0; j < p.size() / 2; ++j)
         flag &= (p[j] == p[p.size() - 1 - j]);
        if (flag) {
            a = i;
           vector<int> q;
        	while (a > 0) {
            	q.push_back(a % n);
            	a /= n;
        	}
            for (int j = q.size() - 1; j >= 0; --j) {
                if (q[j] < 10) 
                    cout << q[j];
                else
                    cout << char('A' + q[j] - 10);
            }
            cout << " ";
            for (int j = p.size() - 1; j >= 0; --j) {
                if (p[j] < 10) 
                    cout << p[j];
                else
                    cout << char('A' + p[j] - 10);
            }
            cout << endl;
        }
    }
    
    return 0;
}
