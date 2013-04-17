/*
ID: CHN
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<char, vector<char> > change;
vector<string> name;
bool ans = false;
int len, name_pos;


int dfs(const string &p, string now, int pos) {
    if (pos == len) {
        while (name_pos < name.size() && name[name_pos] < now) ++name_pos;
        if (name[name_pos] == now) {
            cout << now << endl;
            ans = true;
        }
        return 0;
    }
    if (p[pos] < '2' || p[pos] > '9') return 0;
    for (int i = 0; i < change[p[pos]].size(); ++i) {
        dfs(p, now + change[p[pos]][i], pos+1);
    }
    return 0;
}


int main() {
  ifstream fin("namenum.in");
  ifstream txt("dict.txt");
    freopen("namenum.out", "w", stdout);
    change['2'].push_back('A');
    change['2'].push_back('B');
    change['2'].push_back('C');
    change['3'].push_back('D');
    change['3'].push_back('E');
    change['3'].push_back('F');
    change['4'].push_back('G');
    change['4'].push_back('H');
    change['4'].push_back('I');
    change['5'].push_back('J');
    change['5'].push_back('K');
    change['5'].push_back('L');
    change['6'].push_back('M');
    change['6'].push_back('N');
    change['6'].push_back('O');
    change['7'].push_back('P');
    change['7'].push_back('R');
    change['7'].push_back('S');
    change['8'].push_back('T');
    change['8'].push_back('U');
    change['8'].push_back('V');
    change['9'].push_back('W');
    change['9'].push_back('X');
    change['9'].push_back('Y');
    
    string p;
    while (txt >> p) name.push_back(p);
    
    fin >> p;
    len = p.size();
    name_pos = 0;
    dfs(p, "", 0);
    
    if (!ans) cout << "NONE" << endl;
    
    return 0;
}
