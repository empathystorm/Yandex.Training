#include "func.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void put_numbers_near_bomb(vector<vector<char> >& field, int n, int m, int sizeN, int sizeM) {
    int deltas[][2] = {{-1, -1}, {-1, 0}, {-1, 1},
                       {0, -1},                       {0, 1},
                       {1, -1}, {1, 0},   {1, 1}};
    for (auto& d : deltas) {
        int pn = d[0] + n;
        int pm = d[1] + m;
        if (pn < sizeN && pn >=0 && pm < sizeM && pm >=0 && field[pn][pm] != '*') {
            field[pn][pm] += 1;
        }
    }
}

//Сапёр
void task_i() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int sizeN, sizeM, minesNum;
    input >> sizeN >> sizeM >> minesNum;
    vector<vector<char> > field(sizeN, vector<char>(sizeM, '0'));
    for (int i = 0; i < minesNum; i++) {
        int n, m;
        input >> n >> m;
        field[n-1][m-1]='*';
        put_numbers_near_bomb(field, n-1, m-1, sizeN, sizeM);
    }

    for (int i = 0; i < sizeN; i++) {
        for (int j = 0; j < sizeM; j++) {
            output << field[i][j] << ' ';
        }
        output << '\n';
    }
}