#include "func.h"
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>

using namespace std;

void task_c() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    map<string, int> dictionary;
    int max = 0;
    set<string> maxWords;
    string word;
    while (input >> word) {
        if (!dictionary.count(word))
            dictionary.insert(make_pair(word, 0));
        dictionary[word]++;
        if (dictionary[word] > max) {
            max = dictionary[word];
            maxWords.clear();
            maxWords.insert(word);
        } else if (dictionary[word] == max)
            maxWords.insert(word);
    }

    output << *maxWords.begin();
}