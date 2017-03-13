/*
ID: CHN
PROG: skidesign
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 1010;
const int INF = 1000000007;

int N;
int X[MAXN];

int sqr(int x) {
    return x * x;
}

int main() {
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> X[i];
    int ans = INF;
    for (int i = 0; i <= 100; ++i) {
        int temp = 0;
        for (int j = 0; j < N; ++j) {
            if (X[j] < i) temp += sqr(i - X[j]);
            if (X[j] > i + 17) temp += sqr(X[j] - i - 17);
        }
        ans = min(ans, temp);
        temp = 0;
        for (int j = 0; j < N; ++j) {
            if (X[j] < i - 17) temp += sqr(i - 17 - X[j]);
            if (X[j] > i) temp += sqr(X[j] - i);
        }
        ans = min(ans, temp);
    }
    cout << ans << endl;
    return 0;
}
