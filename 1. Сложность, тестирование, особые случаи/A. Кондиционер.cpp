#include "func.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int calc_temp(int troom, int tcond, string& mode) {
    if (mode == "freeze") {
        if (troom > tcond) return tcond;
        else return troom;
    } else if (mode == "heat") {
        if (troom < tcond) return tcond;
        else return troom;
    } else if (mode == "auto") return tcond;
    else if (mode == "fan") return troom;
}

//Кондиционер
void task_a() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int troom, tcond;
    input >> troom >> tcond;
    string mode;
    input >> mode;

    output << calc_temp(troom, tcond, mode);
}