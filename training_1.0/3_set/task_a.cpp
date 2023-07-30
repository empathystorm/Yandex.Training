#include "func.h"
#include <iostream>
#include <fstream>
#include <vector>
#define N 10

using namespace std;

//написана буквальная реализация хэш-таблицы, можно использовать set
void add(vector<vector<int> >& table, int key) {
    if (!find(table, key)) { //find() из func.cpp
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