#include "func.h"
#include <iostream>
#include <fstream>

using namespace std;

//Возрастает ли список?
void task_a() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    bool flag = true;
    int n, n0 = INT32_MIN;
    while (input >> n) {
        if (n <= n0) flag = false;
        n0 = n;
    }

    if (flag) output << "YES";
    else output << "NO";
}