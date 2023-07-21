#include "func.h"
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

void task_e() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;

    map<long, long> pyramid;
    for (int i = 0; i < n; i++) {
        long w, h;
        input >> w >> h;
        if (!pyramid.count(w))
            pyramid.insert(make_pair(w, 0));
        pyramid[w] = max(pyramid[w], h);
    }

    long count = 0;
    for (auto i : pyramid) {
        count += i.second;
    }

    output << count;
}