#include "func.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void kth_rearrange(vector<int>& arr, int left, int right, int k) {
    while (left < right) {
        int x = arr[(left + right) / 2];
        int eqXFirst = left; //первое число, равное x
        int grtXFirst = left; //первое число, больше чем x
        for (int i = left; i <= right; i++) {
            int now = arr[i];
            if (now == x) {
                arr[i] = arr[grtXFirst];
                arr[grtXFirst] = now;
                grtXFirst++;
            } else if (now < x) {
                arr[i] = arr[grtXFirst];
                arr[grtXFirst] = arr[eqXFirst];
                arr[eqXFirst] = now;
                grtXFirst++;
                eqXFirst++;
            }
        }
        if (k < eqXFirst) right = eqXFirst - 1;
        else if (k >= grtXFirst) left = grtXFirst;
        else return;
    }
}

//Наибольшее произведение двух чисел
void task_g() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    vector<int> arr;
    while (input >> n) arr.push_back(n);

    int size = arr.size();
    kth_rearrange(arr, 0, size-1, size-2);
    kth_rearrange(arr, 0, size-3, 1);

    if (arr[size-1] * arr[size-2] >= arr[0] * arr[1])
        output << arr[size-2] << ' ' << arr[size-1];
    else
        output << arr[0] << ' ' << arr[1];
}