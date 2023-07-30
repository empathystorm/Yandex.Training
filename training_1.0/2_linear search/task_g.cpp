#include "func.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Наибольшее произведение двух чисел
void task_g() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    long n;
    vector<long> arr;
    while (input >> n) arr.push_back(n);

    int size = arr.size();
    kth_rearrange(arr, 0, size-1, size-2); //используется из func.cpp
    kth_rearrange(arr, 0, size-3, 1);

    if (arr[size-1] * arr[size-2] >= arr[0] * arr[1])
        output << arr[size-2] << ' ' << arr[size-1];
    else
        output << arr[0] << ' ' << arr[1];
}