#include "func.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void extend(vector<int>& rect, int d) {
    rect[0] -= d; // min x+y
    rect[1] += d; // max x+y
    rect[2] -= d; // min x-y
    rect[3] += d; // max x-y
}

void intersect(vector<int>& rect1, vector<int>& rect2) {
    rect1[0] = max(rect1[0], rect2[0]);
    rect1[1] = min(rect1[1], rect2[1]);
    rect1[2] = max(rect1[2], rect2[2]);
    rect1[3] = min(rect1[3], rect2[3]);
}

void task_j() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int t, d, n;
    input >> t >> d >> n;

    vector<int> posRect = {0, 0, 0, 0};
    for (int i = 0; i < n; i++) {
        extend(posRect, t);
        int nx, ny;
        input >> nx >> ny;
        vector<int> navRect = {nx + ny, nx + ny, nx - ny, nx - ny};
        extend(navRect, d);
        intersect(posRect, navRect);
    }

    vector<vector<int> > points;
    for (int xPlusY = posRect[0]; xPlusY <= posRect[1]; xPlusY++) {
        for (int xMinusY = posRect[2]; xMinusY <= posRect[3]; xMinusY++) {
            if ((xPlusY + xMinusY) % 2 == 0) {
                int x = (xPlusY + xMinusY) / 2;
                int y = xPlusY - x;
                points.push_back({x, y});
            }
        }
    }

    output << points.size() << '\n';
    for (auto& p : points) {
        output << p[0] << ' ' <<  p[1] << '\n';
    }
}