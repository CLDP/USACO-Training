/*
ID: CHN
PROG: window
LANG: C++
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

struct rect {
    int x1, y1, x2, y2, color;
};

map<char, int> z;
int area[62];
vector<rect> x;
vector<rect> y;


bool get_boundary(int x1, int x2, int x3, int x4, int &k1, int &k2) {
    k1 = max(x1, x3);
    k2 = min(x2, x4);
    if (k1 >= k2) return false;
    return true;
}


int add_one(int x1, int y1, int x2, int y2, int color) {
    rect p;
    p.x1 = x1;
    p.y1 = y1;
    p.x2 = x2;
    p.y2 = y2;
    p.color = color;
    x.push_back(p);
    return 0;
}


int add(int a, int b, int c, int d, int color) {
    int j = 0, len = x.size();
    
    while (j < len) {
        int k1, k2, k3, k4;
        if (!get_boundary(x[j].x1, x[j].x2, a, c, k1, k2)) {
            ++j;
            continue;
        }
        
        if (!get_boundary(x[j].y1, x[j].y2, b, d, k3, k4)) {
            ++j;
            continue;
        }
        
        if (x[j].x1 < k1) add_one(x[j].x1, x[j].y1, k1, x[j].y2, x[j].color);
        if (k2 < x[j].x2) add_one(k2, x[j].y1, x[j].x2, x[j].y2, x[j].color);
        if (x[j].y1 < k3) add_one(k1, x[j].y1, k2, k3, x[j].color);
        if (k4 < x[j].y2) add_one(k1, k4, k2, x[j].y2, x[j].color);
        x.erase(x.begin() + j);
        --len;
    }
    
    add_one(a, b, c, d, color);
}


int get(int &j, const string &p) {
    int ans = 0;
    while (p[j] >= '0' && p[j] <= '9') {
        ans = ans * 10 + (p[j] - '0');
        ++j;
    }
    ++j;
    return ans;
}

int main() {
    freopen("window.in", "r", stdin);
    freopen("window.out", "w", stdout);
    for (int i = 0; i < 26; ++i) {
        z[i + 'A'] = i;
        z[i + 'a'] = i + 26;
    }
    for (int i = 0; i < 10; ++i) z[i + '0'] = i + 52;
    
    string pp;
    int a, b, c, d;
    while (getline(cin, pp)) {
        if (pp[0] == 'w') {
            int color = z[pp[2]];
            int j = 4;
            a = get(j, pp);
            b = get(j, pp);
            c = get(j, pp);
            d = get(j, pp);
            if (a > c) swap(a, c);
            if (b > d) swap(b, d);
            
            rect q;
            q.x1 = a;
            q.y1 = b;
            q.x2 = c;
            q.y2 = d;
            q.color = color;
            y.push_back(q);
            add(a, b, c, d, color);
        } else
        if (pp[0] == 't') {
            for (int i = 0; i < y.size(); ++i)
             if (y[i].color == z[pp[2]]) {
                 rect one = y[i];
                 for (int j = i; j < y.size() - 1; ++j) y[j] = y[j+1];
                 y[y.size() - 1] = one;
                 break;
             }
        } else
        if (pp[0] == 'b') {
            for (int i = 0; i < y.size(); ++i)
             if (y[i].color == z[pp[2]]) {
                 rect one = y[i];
                 for (int j = i; j > 0; --j) y[j] = y[j-1];
                 y[0] = one;
                 break;
             }
        } else
        if (pp[0] == 'd') {
            for (int i = 0; i < y.size(); ++i)
             if (y[i].color == z[pp[2]]) {
                 y.erase(y.begin() + i);
                 break;
             }
        } else {
            double ans = 0;
            int color = z[pp[2]];
            for (int i = 0; i < x.size(); ++i) 
             if (x[i].color == color) ans += (x[i].x2 - x[i].x1) * (x[i].y2 - x[i].y1);
            
            for (int i = 0; i < y.size(); ++i)
             if (y[i].color == color) {
                 ans /= (y[i].x2 - y[i].x1) * (y[i].y2 - y[i].y1);
                 break;
             }
            
            ans *= 100;
            printf("%.3lf\n", ans);
        }
        if (pp[0] == 't' || pp[0] == 'b' || pp[0] == 'd') {
            x.clear();
            for (int i = 0; i < y.size(); ++i)
             add(y[i].x1, y[i].y1, y[i].x2, y[i].y2, y[i].color);
        }
    }
    
    return 0;
}
vector<rect> y;


bool get_boundary(int x1, int x2, int x3, int x4, int &k1, int &k2) {
    k1 = max(x1, x3);
    k2 = min(x2, x4);
    if (k1 >= k2) return false;
    return true;
}


int add_one(int x1, int y1, int x2, int y2, int color) {
    rect p;
    p.x1 = x1;
    p.y1 = y1;
    p.x2 = x2;
    p.y2 = y2;
    p.color = color;
    x.push_back(p);
    return 0;
}


int add(int a, int b, int c, int d, int color) {
    int j = 0, len = x.size();
    
    while (j < len) {
        int k1, k2, k3, k4;
        if (!get_boundary(x[j].x1, x[j].x2, a, c, k1, k2)) {
            ++j;
            continue;
        }
        
        if (!get_boundary(x[j].y1, x[j].y2, b, d, k3, k4)) {
            ++j;
            continue;
        }
        
        if (x[j].x1 < k1) add_one(x[j].x1, x[j].y1, k1, x[j].y2, x[j].color);
        if (k2 < x[j].x2) add_one(k2, x[j].y1, x[j].x2, x[j].y2, x[j].color);
        if (x[j].y1 < k3) add_one(k1, x[j].y1, k2, k3, x[j].color);
        if (k4 < x[j].y2) add_one(k1, k4, k2, x[j].y2, x[j].color);
        x.erase(x.begin() + j);
        --len;
    }
    
    add_one(a, b, c, d, color);
}


int get(int &j, const string &p) {
    int ans = 0;
    while (p[j] >= '0' && p[j] <= '9') {
        ans = ans * 10 + (p[j] - '0');
        ++j;
    }
    ++j;
    return ans;
}



int main() {

    freopen("window.in", "r", stdin);

    freopen("window.out", "w", stdout);
    for (int i = 0; i < 26; ++i) {
        z[i + 'A'] = i;
        z[i + 'a'] = i + 26;
    }
    for (int i = 0; i < 10; ++i) z[i + '0'] = i + 52;
    
    string pp;
    int a, b, c, d;
    while (getline(cin, pp)) {
        if (pp[0] == 'w') {
            int color = z[pp[2]];
            int j = 4;
            a = get(j, pp);
            b = get(j, pp);
            c = get(j, pp);
            d = get(j, pp);
            if (a > c) swap(a, c);
            if (b > d) swap(b, d);
            
            rect q;
            q.x1 = a;
            q.y1 = b;
            q.x2 = c;
            q.y2 = d;
            q.color = color;
            y.push_back(q);
            add(a, b, c, d, color);
        } else
        if (pp[0] == 't') {
            for (int i = 0; i < y.size(); ++i)
             if (y[i].color == z[pp[2]]) {
                 rect one = y[i];
                 for (int j = i; j < y.size() - 1; ++j) y[j] = y[j+1];
                 y[y.size() - 1] = one;
                 break;
             }
        } else
        if (pp[0] == 'b') {
            for (int i = 0; i < y.size(); ++i)
             if (y[i].color == z[pp[2]]) {
                 rect one = y[i];
                 for (int j = i; j > 0; --j) y[j] = y[j-1];
                 y[0] = one;
                 break;
             }
        } else
        if (pp[0] == 'd') {
            for (int i = 0; i < y.size(); ++i)
             if (y[i].color == z[pp[2]]) {
                 y.erase(y.begin() + i);
                 break;
             }
        } else {
            double ans = 0;
            int color = z[pp[2]];
            for (int i = 0; i < x.size(); ++i) 
             if (x[i].color == color) ans += (x[i].x2 - x[i].x1) * (x[i].y2 - x[i].y1);
            
            for (int i = 0; i < y.size(); ++i)
             if (y[i].color == color) {
                 ans /= (y[i].x2 - y[i].x1) * (y[i].y2 - y[i].y1);
                 break;
             }
            
            ans *= 100;
            printf("%.3lf\n", ans);
        }
        if (pp[0] == 't' || pp[0] == 'b' || pp[0] == 'd') {
            x.clear();
            for (int i = 0; i < y.size(); ++i)
             add(y[i].x1, y[i].y1, y[i].x2, y[i].y2, y[i].color);
        }
    }

    

    return 0;

}
