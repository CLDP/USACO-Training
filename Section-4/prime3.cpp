/*
ID: CHN
PROG: prime3
LANG: C++
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10000;
const int MAXK = 100000;
const int MI[5] = {1, 10, 100, 1000, 10000};

struct node {
    int x[5][5];
    double xx;
};

int n, m;
int z[MAXN][5];
int z1[MAXN][5];              // No even number, no five in every digit
int z2[10][10][100][5];       // Begin with a, end with b, five digit prime
int z3[10][10][100][5];       // The third digit is a, end with b
int zp, z1p;                  // Number of z, z1
int z2p[10][10], z3p[10][10]; // Number of z2, z3
bool x[MAXK], cz[MAXK];       // Used to find prime number
int y[5][5];
vector<node> ans;

// Check whether the sum is the given number
bool check(int a) {
    int k = 0;
    for (int i = 0; i < 5; ++i) {
        k += a % 10;
        a /= 10;
    }
    return k == n;
}

// Check there is no two and five
bool check_no25(int a[]) {
    for (int i = 0; i < 5; ++i) 
     if (a[i] % 2 == 0) return false;
    
    for (int i = 0; i < 5; ++i)
     if (a[i] == 5) return false;
    
    return true;
}

bool check_prime(int a, bool column) {
    int k = 0;
    if (column) {
        for (int i = 0; i < 5; ++i) k = k * 10 + y[i][a];
    } else {
        for (int i = 0; i < 5; ++i) k = k * 10 + y[a][i];
    }
    return x[k];
}

void find_column_mid() {
    y[0][2] = n - y[0][0] - y[0][1] - y[0][3] - y[0][4];
    if (y[0][2] > 9 || y[0][2] < 1) return;
    if (!check_prime(0, false)) return;
    
    int k = y[2][2], l = y[4][2];
    for (int i = 0; i < z3p[k][l]; ++i)
     if (z3[k][l][i][0] == y[0][2]) {
         y[1][2] = z3[k][l][i][1];
         y[3][2] = z3[k][l][i][3];
         y[1][0] = n - y[1][1] - y[1][2] - y[1][3] - y[1][4];
         if (y[1][0] > 9 || y[1][0] < 1) continue;
         if (!check_prime(1, false)) continue;
         
         y[3][0] = n - y[3][1] - y[3][2] - y[3][3] - y[3][4];
         if (y[3][0] > 9 || y[3][0] < 1) continue;
         if (!check_prime(3, false)) continue;
         if (!check_prime(0, true)) continue;
         
         node new_ans;
         new_ans.xx = 0;
         for (int p = 0; p < 5; ++p)
          for (int q = 0; q < 5; ++q) {
              new_ans.x[p][q] = y[p][q];
              new_ans.xx = new_ans.xx * 10 + y[p][q];
          }
         ans.push_back(new_ans);
     }
}

void find_row_first() {
    y[0][1] = n - y[1][1] - y[2][1] - y[3][1] - y[4][1];
    if (y[0][1] > 9 || y[0][1] < 1) return;
    if (!check_prime(1, true)) return;
    y[0][3] = n - y[1][3] - y[2][3] - y[3][3] - y[4][3];
    if (y[0][3] > 9 || y[0][3] < 1) return;
    if (!check_prime(3, true)) return;
    find_column_mid();
}

void find_row_mid() {
    int k = y[2][2], l = y[2][4];
    for (int i = 0; i < z3p[k][l]; ++i) {
        y[2][0] = z3[k][l][i][0];
        y[2][1] = z3[k][l][i][1];
        y[2][3] = z3[k][l][i][3];
        find_row_first();
    }
}

void find_diagonal_second() {
    int k = y[4][0], l = y[0][4];
    for (int i = 0; i < z2p[k][l]; ++i)
     if (z2[k][l][i][2] == y[2][2]) {
         y[3][1] = z2[k][l][i][1];
         y[1][3] = z2[k][l][i][3];
         find_row_mid();
     }
}

void find_diagonal_main() {
    int k = y[4][4];
    for (int i = 0; i < z2p[m][k]; ++i) {
        for (int j = 1; j < 4; ++j) y[j][j] = z2[m][k][i][j];
        find_diagonal_second();
    }
}

void find_column_last() {
    for (int i = 0; i < z1p; ++i) 
     if (z1[i][4] == y[4][4]) {
         for (int j = 0; j < 4; ++j) y[j][4] = z1[i][j];
         find_diagonal_main();
     }
}

void find_row_last() {
    y[0][0] = m;
    for (int i = 0; i < z1p; ++i) {
        for (int j = 0; j < 5; ++j) y[4][j] = z1[i][j];
        find_column_last();
    }
}

bool compare(const node &a, const node &b) {
    return a.xx < b.xx;
}


int main() {
    freopen("prime3.in", "r", stdin);
    freopen("prime3.out", "w", stdout);
    cin >> n >> m;
    
    for (int i = 2; i < MAXK; ++i) {
        if (!cz[i]) {
            x[i] = true;
            cz[i] = true;
            int j = 2;
            while (i * j < MAXK) cz[i * (j++)] = true;
            if (i > 10000) {
                int sum = 0;
                for (int k = 0; k < 5; ++k) {
                    z[zp][k] = (i / MI[4-k]) % 10;
                    sum += z[zp][k];
                }
                
                if (sum != n) continue;
                
                if (check_no25(z[zp])) {
                    for (int k = 0; k < 5; ++k) z1[z1p][k] = z[zp][k];
                    ++z1p;
                }
                
                int j = z[zp][0], k = z[zp][4];
                for (int l = 0; l < 5; ++l) z2[j][k][z2p[j][k]][l] = z[zp][l];
                ++z2p[j][k];
                
                j = z[zp][2];
                for (int l = 0; l < 5; ++l) z3[j][k][z3p[j][k]][l] = z[zp][l];
                ++z3p[j][k];
                
                ++zp;
            }
        }
    }
    
    find_row_last();
    sort(ans.begin(), ans.end(), compare);
    
    for (int k = 0; k < ans.size(); ++k) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) cout << ans[k].x[i][j];
            cout << endl;
        }
        if (k < ans.size() - 1) cout << endl;
    }
    
    if (ans.empty()) cout << "NONE" << endl;
    
    return 0;
}
