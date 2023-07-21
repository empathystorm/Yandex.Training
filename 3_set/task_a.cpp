#include "func.h"
#include <iostream>
#include <fstream>
#include <vector>
#define N 10

using namespace std;

//можно использовать set
bool find(vector<vector<int> >& table, int key) {
    for (int i : table[key%10]) {
        if (i == key) return true;
    }
    return false;
}

void add(vector<vector<int> >& table, int key) {
    if (!find(table, key)) {
        table[key%10].push_back(key);
    }
}

void task_a() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    vector<vector<int> > hash_table(N, vector<int>());
    while (input >> n) add(hash_table, n);

    int count = 0;
    for (int i = 0; i < N; i++) {
        while (!hash_table[i].empty()) {
            count++;
            hash_table[i].pop_back();
        }
    }

    output << count;
}