/*
ID: CHN
PROG: ttwo
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

const int MX[4] = {-1, 0, 1, 0};
const int MY[4] = {0, 1, 0, -1};

bool x[11][11];
set<string> previous;


bool check(pair<int, int> per, int dir) {
    per.first += MX[dir];
    per.second += MY[dir];
    if (per.first < 0 || per.first > 9) return false;
    if (per.second < 0 || per.second > 9) return false;
    if (!x[per.first][per.second]) return false;
    return true;
}


int main() {
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);
    string p;
    pair<int, int> farmer, cow;
    for (int i = 0; i < 10; ++i) {
        cin >> p;
        for (int j = 0; j < 10; ++j)
        switch (p[j]) {
            case '*' : x[i][j] = false; break;
            case '.' : x[i][j] = true;  break;
            case 'C' : x[i][j] = true;  cow = make_pair(i, j); break;
            case 'F' : x[i][j] = true;  farmer = make_pair(i, j); break;
        }
    }
   
    int dirf, dirc;
    dirf = dirc = 0;
   
    int time = 0;
    string temp;
    while (true) {
        if (cow == farmer) break;
        temp = "";
        temp += (char)(farmer.first + '0');
        temp += (char)(farmer.second + '0');
        temp += (char)(cow.first + '0');
        temp += (char)(cow.second + '0');
        temp += (char)(dirf + '0');
        temp += (char)(dirc + '0');
        if (previous.find(temp) != previous.end()) {
            time = 0;
            break;
        }
        previous.insert(temp);
        ++time;
        if (check(cow, dirc)) {
            cow.first += MX[dirc];
            cow.second += MY[dirc];
        } else {
            dirc = (dirc + 1) % 4;
        }
        if (check(farmer, dirf)) {
            farmer.first += MX[dirf];
            farmer.second += MY[dirf];
        } else {
            dirf = (dirf + 1) % 4;
        }
    }
    
    cout << time << endl;
    
    return 0;
}
