#include "func.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> get_entrance_and_floor(int flatNo, int flatsOnFloor, int floors) {
    int floorsBefore = (flatNo - 1) / flatsOnFloor;
    int entrance = floorsBefore / floors + 1;
    int floor = floorsBefore % floors + 1;
    return {entrance, floor};
}

vector<int> check(int k1, int m, int k2, int p2, int n2, int flatsOnFloor) {
    vector<int> ambulance2 = get_entrance_and_floor(k2, flatsOnFloor, m);
    if (ambulance2[0] == p2 && ambulance2[1] == n2)
        return get_entrance_and_floor(k1, flatsOnFloor, m);
    return {-1, -1};
}

vector<int> search_answer(int k1, int m, int k2, int p2, int n2, int maxVal) {
    int ent = -1;
    int floor = -1;
    bool goodFlag = false;
    for (int flatsOnFloor = 1; flatsOnFloor <= maxVal; flatsOnFloor++) {
        vector<int> nAmbulance = check(k1, m, k2, p2, n2, flatsOnFloor);
        if (nAmbulance[0] != -1) {
            goodFlag = true;
            if (ent == -1) {
                ent = nAmbulance[0];
                floor = nAmbulance[1];
            } else if (ent != nAmbulance[0] && ent != 0) {
                ent = 0;
            } else if (floor != nAmbulance[1] && floor != 0) {
                floor = 0;
            }
        }
    }
    if (goodFlag) return {ent, floor};
    else return {-1, -1};
}

//Скорая помощь
void task_e() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int k1, m, k2, p2, n2;
    input >> k1 >> m >> k2 >> p2 >> n2;

    int maxVal = 1000000;
    vector<int> answer = search_answer(k1, m, k2, p2, n2, maxVal);
    output << answer[0] << ' ' << answer[1];
}