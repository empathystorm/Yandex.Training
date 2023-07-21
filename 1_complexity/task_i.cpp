#include "func.h"
#include <iostream>
#include <fstream>

using namespace std;

bool does_fit(int brickX, int brickY, int wallX, int wallY) {
    return (brickX <= wallX && brickY <= wallY) || (brickX <= wallY && brickY <= wallX);
}

//Узник замка Иф
void task_i() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int a, b, c, d, e;
    input >> a >> b >> c >> d >> e;

    if (does_fit(a, b, d, e) || does_fit(b, c, d, e) || does_fit(a, c, d, e)) {
        output << "YES";
    } else {
        output << "NO";
    }
}