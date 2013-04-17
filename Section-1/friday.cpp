/*
ID: CHN
PROG: friday
LANG: C++
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int DAY[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int ans[7];

int main() {
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    int n, today = 1;
    cin >> n;
    for (int i = 1900; i < 1900 + n; ++i) {
        for (int j = 1; j <= 12; ++j) {
            today = (today + 12) % 7;
            ++ans[today];
            today = (today + DAY[j] - 12) % 7;
            if (j == 2 && i % 4 == 0) {
                if (i % 100 == 0) {
                    if (i % 400 == 0) ++today;
                } else {
                    ++today;
                }
            }
        }
    }
    
    cout << ans[6];
    for (int i = 0; i < 6; ++i) cout << " " << ans[i];
    cout << endl;
        
    return 0;
}
