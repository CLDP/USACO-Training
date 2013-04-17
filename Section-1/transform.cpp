/*
ID: CHN
PROG: transform
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;



int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
    int n;
    vector<string> p, q;
    string r;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> r;
        p.push_back(r);
    }
    for (int i = 0; i < n; ++i) {
        cin >> r;
        q.push_back(r);
    }
    
    bool flag;
    
    // No.1
    flag = true;
    for (int i = 0; i < n; ++i) 
     for (int j = 0; j < n; ++j)
      flag &= (p[i][j] == q[j][n-i-1]);
    
    if (flag) {
        cout << 1 << endl;
        return 0;
    }
    
    // No.2
    flag = true;
    for (int i = 0; i < n; ++i) 
     for (int j = 0; j < n; ++j)
      flag &= (p[i][j] == q[n-i-1][n-j-1]);
    
    if (flag) {
        cout << 2 << endl;
        return 0;
    }
    
    // No.3
    flag = true;
    for (int i = 0; i < n; ++i) 
     for (int j = 0; j < n; ++j)
      flag &= (p[i][j] == q[n-j-1][i]);
    
    if (flag) {
        cout << 3 << endl;
        return 0;
    }
    
    // No.4
    for (int i = 0; i < n; ++i) 
     for (int j = 0; j < n / 2; ++j) {
         char t = p[i][j];
         p[i][j] = p[i][n-1-j];
         p[i][n-1-j] = t;
     }
     
    flag = true;
    for (int i = 0; i < n; ++i)
     for (int j = 0; j < n; ++j)
      flag &= (p[i][j] == q[i][j]);
    
    if (flag) {
        cout << 4 << endl;
        return 0;
    }
    
    // No.5 ************************************************************
    
    // No.1
    flag = true;
    for (int i = 0; i < n; ++i) 
     for (int j = 0; j < n; ++j)
      flag &= (p[i][j] == q[j][n-i-1]);
    
    if (flag) {
        cout << 5 << endl;
        return 0;
    }
    
    // No.2
    flag = true;
    for (int i = 0; i < n; ++i) 
     for (int j = 0; j < n; ++j)
      flag &= (p[i][j] == q[n-i-1][n-j-1]);
    
    if (flag) {
        cout << 5 << endl;
        return 0;
    }
    
    // No.3
    flag = true;
    for (int i = 0; i < n; ++i) 
     for (int j = 0; j < n; ++j)
      flag &= (p[i][j] == q[n-j-1][i]);
    
    if (flag) {
        cout << 5 << endl;
        return 0;
    }
    
    // No.5 ends********************************************************
    
    
    // No.6
    for (int i = 0; i < n; ++i) 
     for (int j = 0; j < n / 2; ++j) {
         char t = p[i][j];
         p[i][j] = p[i][n-1-j];
         p[i][n-1-j] = t;
     }
    
    flag = true;
    for (int i = 0; i < n; ++i)
     for (int j = 0; j < n; ++j)
      flag &= (p[i][j] == q[i][j]);
    
    if (flag) {
        cout << 6 << endl;
        return 0;
    }
    
    cout << 7 << endl;
    
    
    return 0;
}
