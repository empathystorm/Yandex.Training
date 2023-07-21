#include "func.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

void output_base(map<string, map<string, long> >& base) {
    ofstream output("output.txt");
    for (auto& i : base) {
        output << i.first << ":\n";
        for (auto& j : i.second) {
            output << j.first << ' ' << j.second << '\n';
        }
    }
}

void task_f() {
    ifstream input("input.txt");

    map<string, map<string, long> > base;

    string name, goods;
    long count;
    while (input >> name >> goods >> count) {
        if (!base.count(name)) {
            base.insert(make_pair(name, map<string, long>()));
        }
        if (!base[name].count(goods))
            base[name].insert(make_pair(goods, 0));
        base[name][goods] += count;
    }

    output_base(base);
}