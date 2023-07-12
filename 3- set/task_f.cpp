#include "func.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

string concatenate_char(char s1, char s2) {
    return string(1, s1) + s2;
}

void task_f() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    map<string, int> genomes;
    istringstream is = get_line(input); //get_line from task B (see func.h file)
    char s0, s;
    is >> s0;
    while (is >> s) {
        string gen = concatenate_char(s0, s);
        if (genomes.count(gen) == 0)
            genomes.insert(make_pair(gen, 0));
        genomes[gen]++;
        s0 = s;
    }

    is = get_line(input);
    is >> s0;
    int count = 0;
    while (is >> s) {
        string gen = concatenate_char(s0, s);
        if (genomes.count(gen)) {
            count += genomes[gen];
            genomes.erase(gen);
        }
        s0 = s;
    }
    output << count;
}