#include "func.h"
#include <iostream>
#include <fstream>

using namespace std;

//Метро
void task_h() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int a, b, n, m;
    input >> a >> b >> n >> m;

    int min1 = a*(n-1) + n;
    int max1 = a*(n-1) + n + 2*a;
    int min2 = b*(m-1) + m;
    int max2 = b*(m-1) + m + 2*b;
    int minAll = max(min1, min2);
    int maxAll = min(max1, max2);

    if (minAll <= maxAll) {
        output << minAll << ' ' << maxAll;
    } else {
        output << -1;
    }
}