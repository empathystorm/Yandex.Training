#include "func.h"
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

void task_e() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    set<int> numbers;
    int x, y, z;
    input >> x >> y >> z;
    numbers.insert(x);
    numbers.insert(y);
    numbers.insert(z);

    int n, count = 0;
    input >> n;
    while (n > 0) {
        if (!numbers.count(n%10)) {
            count++;
            numbers.insert(n%10);
        }
        n /= 10;
    }

    output << count;
}