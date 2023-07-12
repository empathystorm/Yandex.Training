#include "func.h"
#include <iostream>
#include <fstream>

using namespace std;

//Треугольник
void task_b() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int a, b, c;
    input >> a >> b >> c;

    if (a + b > c && a + c > b && b + c > a) {
        output << "YES";
    } else {
        output << "NO";
    }
}