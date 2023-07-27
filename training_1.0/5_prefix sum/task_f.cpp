#include "func.h"
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int>& a, vector<int>& b) {
    if (a[1] == b[1]) return a[0] < b[0]; //если цены равны, сортироровать в порядке возрастания мощности
    else return a[1] < b[1]; //иначе в порядке возрастания цены
}

int find_total_cost(vector<int>& classrooms, vector<vector<int> >& conditioners) {
    int pCond = 0, totalCost = 0;
    for (int pClass: classrooms) { //идём по необоходимым мощностям конд. для каждого класса
        while (pCond < conditioners.size() && pClass > conditioners[pCond][0]) { //идём, пока не найдём необходимую мощность
            pCond++;
        }
        totalCost += conditioners[pCond][1];
    }
    return totalCost;
}

void task_f(istream& input, ostream& output) {
    int n;
    input >> n;
    vector<int> classrooms(n);
    for (int i = 0; i < n; i++) input >> classrooms[i];
    sort(classrooms.begin(), classrooms.end());

    int m;
    input >> m;
    vector<vector<int> > conditioners(m, vector<int>(2));
    for (int i = 0; i < m; i++) input >> conditioners[i][0] >> conditioners[i][1];
    sort(conditioners.begin(), conditioners.end(), comp); //интеллектуально сортируем

    output << find_total_cost(classrooms, conditioners);
}