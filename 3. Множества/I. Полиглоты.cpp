#include "func.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void task_i() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int N;
    input >> N;

    map<string, int> languages;

    for (int i = 0; i < N; i++) {
        int m;
        input >> m;
        for (int j = 0; j < m; j++) {
            string lang;
            input >> lang;
            if (!languages.count(lang))
                languages.insert(make_pair(lang, 0));
            languages[lang]++;
        }
    }

    vector<string> languagesAll;
    for (auto& i : languages) {
        if (i.second == N)
            languagesAll.push_back(i.first);
    }

    output << languagesAll.size() << '\n';
    for (auto& i : languagesAll) output << i << '\n';
    output << languages.size() << '\n';
    for (auto& i : languages) output << i.first << '\n';
}