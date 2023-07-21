#include "func.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

void task_a() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;
    map<string, string> dictionary;
    for (int i = 0; i < n; i++) {
        string word1, word2;
        input >> word1 >> word2;
        dictionary.insert(make_pair(word1, word2)); //map не добавляет повторяющиеся объекты
        dictionary.insert(make_pair(word2, word1));
    }
    string search_word;
    input >> search_word;

    output << dictionary[search_word];
}