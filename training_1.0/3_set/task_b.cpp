#include "func.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#define N 10

using namespace std;

//можно использовать set
void add_any(vector<vector<int> >& table, int key) {
    table[key%10].push_back(key);
}

void task_b() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    vector<vector<int> > table(N, vector<int>());

    int a;
    istringstream is1 = get_line(input);
    while (is1 >> a) add_any(table, a);

    vector<int> matches;
    istringstream is2 = get_line(input); //get_line() из func.cpp
    while (is2 >> a) {
        if (find(table, a)) matches.push_back(a); //find() из func.cpp
    }
    sort(matches.begin(), matches.end());
    for (int i : matches) output << i << ' ';
}