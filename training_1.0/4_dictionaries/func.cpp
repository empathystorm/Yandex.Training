#include "func.h"

string str_to_lower(string s) {
    for (char& c: s) {
        c = (char)tolower(c);
    }
    return s;
}