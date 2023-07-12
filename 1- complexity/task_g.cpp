#include "func.h"
#include <iostream>
#include <fstream>

using namespace std;

//Детали
void task_g() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n, k, m;
    input >> n >> k >> m;

    int details = 0;
    while (n >= k && k >= m) {
        int pieces = n / k;
        int extra = n % k;
        details += k / m * pieces;
        extra += k % m * pieces;
        n = extra;
    }

    output << details;
}