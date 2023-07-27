// Робот
#include "func.h"
#include <string>

using namespace std;

long count_methods(string& s, int k) {
    long count = 0;
    int prevLen = 0;
    for (int i = k; i < s.size(); i++) {
        if (s[i] == s[i-k]) {
            prevLen++;
            count += prevLen;
        } else
            prevLen = 0;
    }
    return count;
}

void task_i(istream& input, ostream& output) {
    int k; string s;
    input >> k >> s;
    output << count_methods(s, k);
}
