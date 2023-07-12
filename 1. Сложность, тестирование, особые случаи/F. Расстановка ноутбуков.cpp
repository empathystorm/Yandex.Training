#include "func.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Расстановка ноутбуков
void task_f() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int a, b, c, d;
    input >> a >> b >> c >> d;

    vector<int> l;
    l.push_back(max(a, c) * (b + d));
    l.push_back(max(a, d) * (b + c));
    l.push_back(max(b, c) * (a + d));
    l.push_back(max(b, d) * (a + c));

    int min_area = *min_element(l.begin(), l.end());

    if (min_area == l[0]) {
        output << max(a, c) << ' ' << b + d;
    } else if (min_area == l[1]) {
        output << max(a, d) << ' ' << b + c;
    } else if (min_area == l[2]) {
        output << max(b, c) << ' ' << a + d;
    } else {
        output << max(b, d) << ' ' << a + c;
    }
}