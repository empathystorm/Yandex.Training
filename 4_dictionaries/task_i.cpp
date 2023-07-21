#include "func.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

string str_to_lower(string s) {
    for (char& c: s) {
        c = (char)tolower(c);
    }
    return s;
}

int count_stresses(string& s) {
    int stresses = 0;
    for (char& c: s) {
        if (isupper(c)) stresses++;
    }
    return stresses;
}

void task_i() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int dictSize;
    input >> dictSize;

    map<string, set<string> > dict;

    for (int i = 0; i < dictSize; i++) {
        string dictWord;
        input >> dictWord;
        string lowerWord = str_to_lower(dictWord);
        if (!dict.count(lowerWord))
            dict.insert(make_pair(lowerWord, set<string>()));
        dict[lowerWord].insert(dictWord);
    }

    int mistakes = 0;
    string word;
    while (input >> word) {
        string lowerWord = str_to_lower(word);
        if (dict.count(lowerWord)) {
            if (!dict[lowerWord].count(word)) mistakes++;
        } else {
            if (count_stresses(word) != 1) mistakes++;
        }
    }

    output << mistakes;
}