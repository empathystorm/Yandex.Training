#include "func.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

bool input_bool(istream& input) {
    string s;
    input >> s;
    if (s == "yes") return true;
    else return false;
}

void only_letter_digit_underscore(string& s) {
    for (char& c: s) {
        if (!isalpha(c) && !isdigit(c) && c != '_')
            c = ' ';
    }
}

bool is_correct_identifier(string& s, bool stDigit) {
    bool isDigits = true;
    for (char c: s) {
        if (!isdigit(c)) {
            isDigits = false;
            break;
        }
    }
    return !isDigits && (stDigit || !isdigit(s[0]));
}

string find_most_common_identifier(map<string, vector<unsigned>>& identifiers) {
    vector<unsigned> maxFirstPos = {0, 0};
    string firstWord;
    for (auto& word: identifiers) {
        if (word.second[0] > maxFirstPos[0] || //кол-во больше максимального
            word.second[0] == maxFirstPos[0] && word.second[1] < maxFirstPos[1]) { //кол-во равно максимальному, но появление раньше
            maxFirstPos = word.second;
            firstWord = word.first;
        }
    }
    return firstWord;
}

void task_j() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int keyCount;
    input >> keyCount;
    bool caseSens = input_bool(input);
    bool stDigit = input_bool(input);

    //ввод ключевых слов
    set<string> keyWords;
    for (int i = 0; i < keyCount; i++) {
        string keyWord;
        input >> keyWord;
        if (!caseSens) keyWord = str_to_lower(keyWord); // str_to_lower() из func.cpp
        keyWords.insert(keyWord);
    }

    //ввод кода
    map<string, vector<unsigned>> identifiers; //1 - слово, 2 - кол-во появлений, 3 - номер слова
    unsigned wordNumber = 0;
    string line;
    while (getline(input, line)) {
        only_letter_digit_underscore(line);
        istringstream sline(line); string word;
        while (sline >> word) {
            //можеть быть идентификатором и ключевым словом
            if (!caseSens) word = str_to_lower(word);
            if (!keyWords.count(word) && is_correct_identifier(word, stDigit)) {
                //является идентификатором
                if (!identifiers.count(word))
                    identifiers.insert(make_pair(word, vector<unsigned>{0, wordNumber}));
                identifiers[word][0]++;
                wordNumber++;
            }
        }
    }

    output << find_most_common_identifier(identifiers);
}