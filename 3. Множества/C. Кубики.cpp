#include "func.h"
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

void output_set(set<int>& colors) {
    cout << colors.size() << '\n';
    if (!colors.empty()) for (int n : colors) cout << n << ' ';
}

void task_c() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int N, M;
    input >> N >> M;

    set<int> colorsN;
    for (int i = 0; i < N; i++) {
        int a;
        input >> a;
        colorsN.insert(a);
    }

    set<int> colorsNM, colorsM;
    for (int i = 0; i < M; i++) {
        int a;
        input >> a;
        if (colorsN.count(a)) {
            colorsN.erase(a);
            colorsNM.insert(a);
        } else
            colorsM.insert(a);
    }

    output_set(colorsNM);
    output_set(colorsN);
    output_set(colorsM);
}