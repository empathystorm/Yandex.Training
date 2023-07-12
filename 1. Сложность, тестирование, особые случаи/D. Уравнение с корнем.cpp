#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

//Уравнение с корнем
void task_d() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int a, b, c;
    input >> a >> b >> c;

    if (c < 0) {
        output << "NO SOLUTION";
    } else if ((a + b) == c * c && (2*a + b) == c * c) {
        output << "MANY SOLUTIONS";
    } else {
        if (a != 0 && (c * c - b) % a == 0) {
            output << (c * c - b) / a;
        } else {
            output << "NO SOLUTION";
        }
    }
}