#include "func.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

void task_d() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    string s;
    unordered_set<string> words;
    while (input >> s) words.insert(s);
    output << words.size();
}