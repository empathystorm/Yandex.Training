#include "func.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

//Чемпионат по метанию коровьих лепешек
void task_e() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) input >> arr[i];

    int res = n-1;
    int winner = arr[0];
    int possibleVasya = 0;
    for (int i = 0; i < n-1; i++) {
        int cur = arr[i];
        if (winner < cur) {
            winner = cur;
            possibleVasya = 0;
        } else if (cur % 10 != 0 and cur % 5 == 0 and possibleVasya < cur and cur > arr[i+1])
            possibleVasya = cur;
    }

    if (winner < arr[n-1] || possibleVasya == 0) res = 0;
    else {
        sort(arr.begin(), arr.end());
        for (int i = n-1; i >= 0; i--) {
            if (arr[i] == possibleVasya) {
                res = n-i;
                break;
            }
        }
    }

    output << res;
}