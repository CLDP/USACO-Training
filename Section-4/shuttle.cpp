/*
ID: CHN
PROG: shuttle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <set>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct node {
    vector<int> q;
    string p;
};

set<string> hash;

int main() {
    freopen("shuttle.in", "r", stdin);
    freopen("shuttle.out", "w", stdout);
    int n;
    cin >> n;
    string p, q;
    for (int i = 0; i < n; ++i) {
        p += 'W';
        q += 'B';
    }
    p += ' ';
    q += ' ';
    for (int i = 0; i < n; ++i) {
        p += 'B';
        q += 'W';
    }
    
    n = n * 2 + 1;
    node now, next;
    now.p = p;
    hash.insert(p);
    queue<node> que;
    que.push(now);
    
    while (!que.empty()) {
        now = que.front();
        que.pop();
        if (now.p == q) break;
        int i;
        for (i = 0; i < n; ++i)
         if (now.p[i] == ' ') break;
        
        if (i >= 2 && now.p[i-2] == 'W' && now.p[i-1] == 'B') {
            next.p = now.p;
            swap(next.p[i], next.p[i-2]);
            if (hash.find(next.p) == hash.end()) {
                hash.insert(next.p);
                next.q = now.q;
                next.q.push_back(i-2);
                que.push(next);
            }
        }
        
        if (i >= 1 && now.p[i-1] == 'W') {
            next.p = now.p;
            swap(next.p[i], next.p[i-1]);
            if (hash.find(next.p) == hash.end()) {
                hash.insert(next.p);
                next.q = now.q;
                next.q.push_back(i-1);
                que.push(next);
            }
        }
        
        if (i <= n-2 && now.p[i+1] == 'B') {
            next.p = now.p;
            swap(next.p[i], next.p[i+1]);
            if (hash.find(next.p) == hash.end()) {
                hash.insert(next.p);
                next.q = now.q;
                next.q.push_back(i+1);
                que.push(next);
            }
        }
        
        if (i <= n-3 && now.p[i+2] == 'B' && now.p[i+1] == 'W') {
            next.p = now.p;
            swap(next.p[i], next.p[i+2]);
            if (hash.find(next.p) == hash.end()) {
                hash.insert(next.p);
                next.q = now.q;
                next.q.push_back(i+2);
                que.push(next);
            }
        }
    }
    
    int temp = 0;
    for (int i = 0; i < now.q.size(); ++i) {
        if (temp != 0) cout << " ";
        cout << now.q[i] + 1;
        ++temp;
        if (temp == 20) cout << endl;
        temp %= 20;
    }
    if (temp != 0) cout << endl;
    
    return 0;
}
