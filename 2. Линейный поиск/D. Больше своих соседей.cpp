#include "func.h"
#include <iostream>
#include <fstream>

using namespace std;

//Больше своих соседей
void task_d() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n0 = INT32_MIN, n1 = INT32_MIN, n2, count = 0;
    while (input >> n2) {
        if (n0 != INT32_MIN && n1 != INT32_MIN && n1 > n0 && n1 > n2) count++;
        n0 = n1;
        n1 = n2;
    }

    output << count;
}