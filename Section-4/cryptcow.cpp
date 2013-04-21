/*
ID: CHN
PROG: cryptcow
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const string KM = "Begin the Escape execution at the Break of Dawn";
const int INF = 35027;

bool hash[INF];


bool ELFhash(const string &p) {
    unsigned int h = 0, g;
    for (int i = 0; i < p.size(); ++i) {
        h = (h << 4) + p[i];
        g = h & 0xf0000000;
        if (g != 0) h ^= (g >> 24);
        h &= ~g;
    }
    h = h % INF;
    if (hash[h]) return true;
    hash[h] = true;
    return false;
}


bool check(const string &p) {
    if (p == KM) return true;
    
    int i = 0, j;
    while (p[i] == KM[i]) ++i;
    // Message from begin to first C must be original message
    if (p[i] != 'C') return false;
    
    i = p.size() - 1, j = 46;
    while (p[i] == KM[j]) {
        --i; 
        --j;
    }
    // Message from last W to end must be original message
    if (p[i] != 'W') return false;
    
    return true;
}



bool dfs(string p) {
    if (!check(p)) return false;
    // Only run for the first time
    if (ELFhash(p)) return false;
    if (p == KM) return true;
    
    int len = p.size();
    vector<int> c, o, w, a;
    a.push_back(-1);
    for (int i = 0; i < len; ++i) {
        if (p[i] == 'C') {
            c.push_back(i);
            a.push_back(i);
        } else
        if (p[i] == 'O') {
            o.push_back(i);
            a.push_back(i);
        } else 
        if (p[i] == 'W') {
            w.push_back(i);
            a.push_back(i);
        }
    }
    
    // Must have same number of COW to decrypt
    if (c.size() != o.size() || o.size() != w.size()) return false;
    
    a.push_back(len);
    
    for (int i = 0; i < a.size()-1; ++i)
     if (a[i] + 1 < a[i+1]) {
         string q;
         for (int j = a[i] + 1; j < a[i+1]; ++j) q += p[j];
         // Message between COW must be plaintext
         if (KM.find(q) == string::npos) return false;
     }
    
    for (int j = 0; j < o.size(); ++j)
     for (int i = 0; i < c.size(); ++i)
      if (c[i] < o[j])
       for (int k = w.size() - 1; k >= 0; --k)
        if (o[j] < w[k]) {
            string q;
            for (int l = 0; l < c[i]; ++l) q += p[l];
            for (int l = o[j] + 1; l < w[k]; ++l) q += p[l];
            for (int l = c[i] + 1; l < o[j]; ++l) q += p[l];
            for (int l = w[k] + 1; l < len; ++l) q += p[l]; 
            
            if (dfs(q)) return true;
        }
    
    return false;
}


int main() {
    freopen("cryptcow.in", "r", stdin);
    freopen("cryptcow.out", "w", stdout);
    string p;
    getline(cin, p);
    if ((p.size() - KM.size()) % 3 != 0) {
        cout << "0 0" << endl;
    } else
    if (dfs(p)) {
        cout << 1 << " " << (p.size() - KM.size()) / 3 << endl;
    } else {
        cout << "0 0" << endl;
    }
    
    return 0;
}
