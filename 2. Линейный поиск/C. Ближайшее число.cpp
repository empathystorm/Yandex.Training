#include "func.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int get_closest(int n1, int n2, int key) {
    if (key - n1 >= n2 - key) return n2;
    else return n1;
}

int find_closest(vector<int>& v, int n, int key) {
    if (key <= v[0]) return v[0];
    if (key >= v[n-1]) return v[n-1];

    int l = 0, r = n, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (v[mid] == key) return v[mid];
        if (key < v[mid]) {
            if (mid > 0 && key > v[mid-1]) return get_closest(v[mid-1], v[mid], key);
            r = mid - 1;
        }
        else {
            if (mid < n-1 && key < v[mid+1]) return get_closest(v[mid], v[mid+1], key);
            l = mid + 1;
        }
    }

    return v[mid];
}

//Ближайшее число
void task_c() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int size, key;
    input >> size;
    vector<int> v(size);
    for (int i = 0; i < size; i++) input >> v[i];
    input >> key;

    sort(v.begin(), v.end());

    output << find_closest(v, size, key);
}