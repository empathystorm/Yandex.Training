#include "func.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Наибольшее произведение трёх чисел
void task_h() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    long n;
    vector<long> arr;
    while (input >> n) arr.push_back(n);

    int size = arr.size();
    kth_rearrange(arr, 0, size-1, size-1); //используется из task_g.cpp
    kth_rearrange(arr, 0, size-2, size-2);
    kth_rearrange(arr, 0, size-4, 2);

    if (arr[size-1] * arr[size-2] * arr[size-3] >= arr[size-1] * arr[0] * arr[1])
        output << arr[size-1] << ' ' << arr[size-2] << ' ' << arr[size-3];
    else
        output << arr[size-1] << ' ' << arr[0] << ' ' << arr[1];
}