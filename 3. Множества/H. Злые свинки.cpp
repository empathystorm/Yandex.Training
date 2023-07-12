#include "func.h"
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

void task_h() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;

    set<int> birdsOnTop;
    for (int i = 0; i < n; i++) {
        int x, y;
        input >> x >> y;
        birdsOnTop.insert(x);
    }
    output << birdsOnTop.size();
}