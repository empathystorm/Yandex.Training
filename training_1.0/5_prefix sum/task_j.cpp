// Треугольники
#include "func.h"
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct P { int x, y; };

//добавляет соседей к точке, избавляется от вырожденных треугольников
void create_neighbours(vector<long>& neig, long& count, vector<P>& points, int i,  int n) {
    set<vector<long>> usedVectors;
    for (int j = 0; j < n; j++) { //идём по соседним точкам
        long vecx = points[i].x - points[j].x;
        long vecy = points[i].y - points[j].y;
        long veclen = vecx*vecx + vecy*vecy;
        neig.push_back(veclen);
        if (usedVectors.count({vecx, vecy})) count--;
        usedVectors.insert({-vecx, -vecy});
    }
    sort(neig.begin(), neig.end());
}

long count_isosceles_triangles(vector<P>& points, int n) {
    long count = 0;
    for (int i = 0; i < n; i++) { //точка i - начало координат
        vector<long> neig;
        create_neighbours(neig, count, points, i, n);
        int r = 0;
        for (int l = 0; l < neig.size(); l++) {
            while (r < neig.size() && neig[l] == neig[r]) {
                r++;
            }
            count += r - l - 1;
        }
    }
    return count;
}

void task_j(istream& input, ostream& output) {
    int n;
    input >> n;
    vector<P> points;
    for (int i = 0; i < n; i++) {
        int x, y; // <10^9
        input >> x >> y;
        points.push_back({x, y});
    }
    output << count_isosceles_triangles(points, n);
}
