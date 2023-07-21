#include "func.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

map<char, int> make_dict(string& s) {
    map<char, int> dict;
    for (char& c: s) {
        if (!dict.count(c))
            dict.insert(make_pair(c, 0));
        dict[c]++;
    }
    return dict;
}

int match_dicts(map<char, int>& dict1, map<char, int>& dict2) {
    int matches = 0;
    for (auto& c: dict1) {
        if (dict2.count(c.first) and c.second == dict2[c.first])
            matches += 1;
    }
    return matches;
}

int modify_dict(map<char, int>& wDict, map<char, int>& sDict, char c, int countModifier) {
    int ans = 0;
    if (!sDict.count(c))
        sDict.insert(make_pair(c, 0));
    if (wDict.count(c) && wDict[c] == sDict[c])
        ans = -1;
    sDict[c] += countModifier;
    if (wDict.count(c) && wDict[c] == sDict[c])
        ans = 1;
    return ans;
}

void task_h() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int lenW, lenS;
    input >> lenW >> lenS;

    string w, s;
    input >> w >> s;

    map<char, int> wDict = make_dict(w);
    string sFirst = s.substr(0, lenW);
    map<char, int> sDict = make_dict(sFirst);

    int matchingLetters = match_dicts(wDict, sDict);
    int occurrences = 0;
    if (matchingLetters == wDict.size())
        occurrences++;

    for (int i = lenW; i < lenS; i++) {
        matchingLetters += modify_dict(wDict, sDict, s[i-lenW], -1);
        matchingLetters += modify_dict(wDict, sDict, s[i], +1);
        if (matchingLetters == wDict.size())
            occurrences++;
    }

    output << occurrences;
}