#include "func.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void task_j() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;

    double left = 30;
    double right = 4000;
    double prev;
    input >> prev;
    for (int i = 0; i < n; i++) {
        double f;
        string s;
        input >> f >> s;

        if (s == "closer" && f > prev || s == "further" && f < prev)
            left = max(left, (f + prev) / 2);
        else if (s == "closer" && f < prev || s == "further" && f > prev)
            right = min(right, (f + prev) / 2);
        prev = f;
    }

    output << setprecision(7) << left << ' ' << right;
}