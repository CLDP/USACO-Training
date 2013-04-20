/*
ID: CHN
PROG: fence4
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const double EPI = 0.01;

struct node {
    double x, y;
};

int n;
node ob;
node p[401];


bool check(node a, node b, node c, node d, bool one_point) {
    if (one_point) {
        // Touch at one point is cross
        return  (((c.x-b.x)*(b.y-a.y)-(b.x-a.x)*(c.y-b.y)) * 
                 ((d.x-b.x)*(b.y-a.y)-(b.x-a.x)*(d.y-b.y)) <= 0) && 
                (((c.x-a.x)*(c.y-d.y)-(c.x-d.x)*(c.y-a.y)) * 
                 ((c.x-b.x)*(c.y-d.y)-(c.x-d.x)*(c.y-b.y)) <= 0);
    } else {
        return  (((c.x-b.x)*(b.y-a.y)-(b.x-a.x)*(c.y-b.y)) * 
                 ((d.x-b.x)*(b.y-a.y)-(b.x-a.x)*(d.y-b.y)) < 0) && 
                (((c.x-a.x)*(c.y-d.y)-(c.x-d.x)*(c.y-a.y)) * 
                 ((c.x-b.x)*(c.y-d.y)-(c.x-d.x)*(c.y-b.y)) < 0);
    }
}

bool satisfy(const node &a, const node &b, int t) {
    if (abs(b.x - a.x) + abs(b.y - a.y) < EPI) return false;
    for (int i = 0; i < n; ++i)
     if (i != t && check(a, ob, p[i], p[i+1], true) && check(b, ob, p[i], p[i+1], true)) return false;
    
    bool f[3] = {true, true, true};
    node mid;
    mid.x = (a.x + b.x) / 2;
    mid.y = (a.y + b.y) / 2;
    for (int i = 0; i < n; ++i) 
     if (i != t) {
         if (check(a, ob, p[i], p[i+1], true)) f[0] = false;
         if (check(b, ob, p[i], p[i+1], true)) f[1] = false;
         if (check(mid, ob, p[i], p[i+1], true)) f[2] = false;
     }
    
    if (f[0] || f[1] || f[2]) return true;
    
    return satisfy(mid, a, t) || satisfy(mid, b, t);
}


int main() {
    freopen("fence4.in", "r", stdin);
    freopen("fence4.out", "w", stdout);
    cin >> n;
    cin >> ob.x >> ob.y;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
        p[i+n] = p[i];
    }
    
    for (int i = 0; i < n; ++i) 
     for (int j = i+2; j < i+n-1; ++j)
      if (check(p[i], p[i+1], p[j], p[j+1], false)) {
          cout << "NOFENCE" << endl;
          return 0;  
      }   
    
    vector<int> ans;
    for (int i = 0; i < n; ++i) 
     if (satisfy(p[i], p[i+1], i)) ans.push_back(i);
    
    cout << ans.size() << endl;
    if (ans[ans.size() - 1] == n-1) {
        if (ans.size() > 1 && ans[ans.size() - 2] == n-2) {
  	    for (int i = 0; i < ans.size() - 2; ++i) 
		     cout << p[ans[i]].x << " " << p[ans[i]].y << " " 
		          << p[ans[i]+1].x << " " << p[ans[i]+1].y << endl;
		    cout << p[0].x << " " << p[0].y << " " << p[n-1].x << " " << p[n-1].y << endl;
		    cout << p[n-2].x << " " << p[n-2].y << " " << p[n-1].x << " " << p[n-1].y << endl;
        } else { 
		    for (int i = 0; i < ans.size() - 1; ++i) 
		     cout << p[ans[i]].x << " " << p[ans[i]].y << " " 
		          << p[ans[i]+1].x << " " << p[ans[i]+1].y << endl;
		    cout << p[0].x << " " << p[0].y << " " << p[n-1].x << " " << p[n-1].y << endl;
        }
    } else {
        for (int i = 0; i < ans.size(); ++i) 
         cout << p[ans[i]].x << " " << p[ans[i]].y << " " << p[ans[i]+1].x << " " << p[ans[i]+1].y << endl;
    }
    
    return 0;
}
