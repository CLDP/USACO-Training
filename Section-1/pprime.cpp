/*
ID: CHN
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> prime;


bool isprime(int a) {
    int sqr = sqrt(a), len = prime.size();
    for (int i = 0; i < len; ++i) {
        if (prime[i] > sqr) break;
        if (a % prime[i] == 0) return false;
    }
    return true;
}

int get(int a, bool b) {
    vector<int> a0;
    while (a > 0) {
        a0.push_back(a % 10);
        a /= 10;
    }
    int c = 0;
    if (a0[a0.size() - 1] % 2 == 0) return -1;
    for (int i = a0.size()-1; i >= 0; --i) c = c * 10 + a0[i];
    if (b) c = c * 10 + a0[0];
    for (int i = 1; i < a0.size(); ++i) c = c * 10 + a0[i];
    return c;
}


int main() {
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);
    int a, b, c;
    cin >> a >> b;
    vector<int> ans;
    
    for (int i = 2; i <= 100000; ++i) {
        bool flag = true;
        for (int j = 2; j <= sqrt(i); ++j) {
            if (i % j == 0) flag = false;
            if (!flag) continue;
        }
        if (flag) prime.push_back(i);
    }
    
    for (int i = 1; i <= 100000; ++i) {
        c = get(i, false);
        if (c != -1 && isprime(c)) ans.push_back(c);
        c = get(i, true);
        if (c != -1 && isprime(c)) ans.push_back(c);
    }
    
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] > b) break;
        if (ans[i] < a) continue;
        printf("%d\n", ans[i]);
    }
    
    return 0;
}
