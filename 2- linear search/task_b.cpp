#include "func.h"
#include <iostream>
#include <fstream>

using namespace std;

//Определить вид последовательности
void task_b() {
    const int EXIT = -2000000000;
    ifstream input("input.txt");
    ofstream output("output.txt");

    bool seqType[] = {true, true, true, true, true};
    int n0 = EXIT;
    do {
        int n;
        input >> n;
        if (n0 != EXIT && n != EXIT) {
            if (n0 != n) seqType[0] = false;
            if (!(n0 < n)) seqType[1] = false;
            if (!(n0 <= n)) seqType[2] = false;
            if (!(n0 > n)) seqType[3] = false;
            if (!(n0 >= n)) seqType[4] = false;
        }
        n0 = n;
    } while (n0 != EXIT);

    if (seqType[0]) output << "CONSTANT";
    else if (seqType[1]) output << "ASCENDING";
    else if (seqType[3]) output << "DESCENDING";
    else if (seqType[2]) output << "WEAKLY ASCENDING";
    else if (seqType[4]) output << "WEAKLY DESCENDING";
    else output << "RANDOM";
}