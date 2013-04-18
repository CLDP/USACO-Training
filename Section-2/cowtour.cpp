/*
ID: CHN
PROG: cowtour
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

const double INF = 1e20;

pair<double, double> x[200];
double z[200][200], d[200];


double dist(pair<double, double> a, pair<double, double> b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}


int main() {
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);
    
    int n;
    cin >> n;
    double a, b;
    string p;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        x[i] = make_pair(a, b);
    }
    
    for (int i = 0; i < n; ++i)
     for (int j = 0; j < n; ++j)
      if (i != j) z[i][j] = INF;
    
    for (int i = 0; i < n; ++i) {
        cin >> p;
        for (int j = 0; j < n; ++j)
         if (p[j] == '1') z[i][j] = dist(x[i], x[j]);
    }
    
    for (int k = 0; k < n; ++k)
     for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
       if (z[i][k] + z[k][j] < z[i][j]) z[i][j] = z[i][k] + z[k][j];
   
    for (int i = 0; i < n; ++i)
     for (int j = 0; j < n; ++j) 
      if (z[i][j] > d[i] && z[i][j] != INF) d[i] = z[i][j];
      
    double ans = INF;
    for (int i = 0; i < n; ++i)
     for (int j = i+1; j < n; ++j)
      if (z[i][j] == INF) {
          double temp = d[i] + d[j] + dist(x[i], x[j]);
          for (int i = 0; i < n; ++i) 
           if (d[i] > temp) temp = d[i];
          if (temp < ans) ans = temp;
      }
    
    printf("%.6lf\n", ans);
    
    return 0;
}
