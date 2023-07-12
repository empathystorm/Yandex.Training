#include "func.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

float count_det(float a, float b, float c, float d) {
    return a*d - b*c;
}

vector<float> solve_system(float a, float b, float c, float d, float e, float f) {
    float delta = count_det(a, b, c, d);
    float deltaX = count_det(e, b, f, d);
    float deltaY = count_det(a, e, c, f);

    if (delta != 0) return {2, deltaX / delta, deltaY / delta};
    if (a == 0 && c == 0) {
        if (b == 0 && d == 0) {
            if (e == 0 && f == 0) return {5};
            else return {0};
        }
        if (e * d != f * b) return {0};
        else {
            float y0;
            if (b != 0) y0 = e / b;
            else y0 = f / d;
            return {4, y0};
        }
    }
    if (b == 0 && d == 0) {
        if (e * c != f * a) return {0};
        else {
            float x0;
            if (a != 0) x0 = e / a;
            else x0 = f / c;
            return {3, x0};
        }
    }
    if (a != 0) {
        float k = c / a;
        if (d - k*b == 0 && f - k*e == 0) return {1, -a / b, e / b};
    } else {
        float k = a / c;
        if (b - k*d == 0 && e - k*f == 0) return {1, -c / d, f / d};
    }
    return {0};
}

//Система линейных уравнений - 2
void task_j() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    float a, b, c, d, e, f;
    input >> a >> b >> c >> d >> e >> f;

    for (float sol : solve_system(a, b, c, d, e, f)) {
        output << setprecision(6) << sol << ' ';
    }
}