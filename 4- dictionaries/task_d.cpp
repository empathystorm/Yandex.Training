#include "func.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void task_d() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;

    vector<int> keyboard(n);
    for (int i = 0; i < n; i++) {
        input >> keyboard[i];
    }

    int m;
    input >> m;
    for (int i = 0; i < m; i++) {
        int key;
        input >> key;
        keyboard[key-1]--;
    }

    for (int i = 0; i < n; i++) {
        if (keyboard[i] < 0) output << "YES\n";
        else output << "NO\n";
    }
}