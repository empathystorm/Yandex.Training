#include "func.h"

bool find(vector<vector<int> >& table, int key) {
    for (int i : table[key%10]) {
        if (i == key) return true;
    }
    return false;
}

istringstream get_line(istream& input) {
    string s;
    getline(input, s);
    istringstream is(s);
    return is;
}