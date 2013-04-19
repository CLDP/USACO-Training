/*
ID: CHN
PROG: contact
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct node {
    int num;
    string p;
};

int len;
string p, q;
map<string, int> ans;
vector<node> anst;
    
bool compare(const node &a, const node &b) {
    if (a.num > b.num) return true;
    if (a.num == b.num) {
        if (a.p.size() < b.p.size()) return true;
        if (a.p.size() > b.p.size()) return false;
        return a.p < b.p;
    }
    return false; 
}

    
int dfs(int n, string s) {
    if (n == 0) {
        ans[s] = 0;
        return 0;
    } 
    dfs(n-1, s + "0");
    dfs(n-1, s + "1");
    return 0;
}
    
int main() {
    freopen("contact.in", "r", stdin);
    freopen("contact.out", "w", stdout);
    int a, b, n;
    cin >> a >> b >> n;
    while (cin >> q) p = p + q;
    len = p.size();
    
    for (int i = a; i <= b; ++i) dfs(i, "");
    
    for (int i = 0; i < len - a + 1; ++i) {
        string s;
        for (int j = 0; j < a; ++j) {
            if (i+j >= len) break;
            s += p[i+j];
        }
        for (int j = a; j <= b; ++j) {
            ++ans[s];
            if (i+j >= len) break;
            s += p[i+j];
        }
    }
    
    map<string, int>::iterator iter = ans.begin();
    node newn;
    while (iter != ans.end()) {
        newn.num = iter->second;
        newn.p = iter->first;
        anst.push_back(newn);
        ++iter;
    }
    sort(anst.begin(), anst.end(), compare);
    int line = 0;
    for (int i = 0; i < anst.size(); ++i) {
        if (i == 0 || anst[i].num != anst[i-1].num) {
            if (anst[i].num == 0) break;
            if (n == 0) break;
            if (i != 0 && line != 0) cout << endl;
            line = 0;
            cout << anst[i].num << endl;
            cout << anst[i].p;
            ++line;
            --n;
        } else {
            if (line != 0) cout << " ";
            cout << anst[i].p;
            ++line;
            if (line == 6) {
                cout << endl;
                line = 0;
            }
        }
    }
    if (line != 0) cout << endl;
    
    return 0;
}
