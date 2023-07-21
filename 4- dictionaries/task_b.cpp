#include "func.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

void task_b() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    map<string, int> dictionary;
    string word;
    while (input >> word) {
        if (!dictionary.count(word))
            dictionary.insert(make_pair(word, 0));
        output << dictionary[word] << ' ';
        dictionary[word]++;
    }
}