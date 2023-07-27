#include "func.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int check_symmetry(vector<int>& arr, int n) {
    int res = 0, l = 0, r = n-1;
    while (l < r) {
        if (arr[l] != arr[r]) {
            res += 1;
            r = n-1;
            l = res;
        } else {
            l += 1;
            r -= 1;
        }
    }
    return res;
}

//Симметричная последовательность
void task_f() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) input >> arr[i];

    int pos = check_symmetry(arr, n);
    output << pos << '\n';
    if (pos != 0) {
        for (int i = pos-1; i >= 0; i--) {
            output << arr[i] << ' ';
        }
    }
}