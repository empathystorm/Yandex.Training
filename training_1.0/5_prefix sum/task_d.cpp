#include "func.h"
#include <vector>

using namespace std;

long count_two_monuments(vector<int>& monuments, int n, int rad) {
    long cntPairs = 0; int r = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && monuments[r] - monuments[l] <= rad) {
            r++;
        }
        cntPairs += n - r;
    }
    return cntPairs;
}

void task_d(istream& input, ostream& output) {
    int n, rad;
    input >> n >> rad;

    vector<int> monuments(n);
    for (int i = 0; i < n; i++) input >> monuments[i];

    output << count_two_monuments(monuments, n, rad);
}