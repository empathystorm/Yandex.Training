#include "func.h"
#include <iostream>
#include <fstream>
#include <set>
#include <vector>

using namespace std;

set<vector<int> > form_turtles(int n) {
    set<vector<int> > turtles;
    for (int i = 0; i < n; i++) {
        turtles.insert({i, n-i-1});
    }
    return turtles;
}

void task_g() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n, count = 0;
    input >> n;
    set<vector<int> > turtles = form_turtles(n);
    for (int i = 0; i < n; i++) {
        int u, d;
        input >> u >> d;
        if (turtles.count({u, d})) {
            count++;
            turtles.erase({u, d});
        }
    }
    output << count;
}