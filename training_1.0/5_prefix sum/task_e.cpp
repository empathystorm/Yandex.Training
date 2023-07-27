#include "func.h"
#include <vector>
#include <map>

using namespace std;

vector<int> find_min_segment(vector<int>& trees, int n, int k) {
    int minSize = n; vector<int> minLR = {0, n-1};
    map<int, int> kinds;
    int r = 0;
    for (int l = 0; l < n; l++) {
        //двигаем правую границу ->, пока не наберуться все виды
        while (r < n && kinds.size() < k) {
            int cur = trees[r];
            if (kinds.count(cur))
                kinds.insert(make_pair(cur, 0));
            kinds[cur]++;
            r++;
        }
        //находим минимальную длину
        if (kinds.size() == k && r - l < minSize) {
            minSize = r - l;
            minLR = {l, r-1};
        }
        //двигаем левую границу на 1 ->
        int cur = trees[l];
        kinds[cur]--;
        if (kinds[cur] == 0)
            kinds.erase(cur);
    }
    return minLR;
}

void task_e(istream& input, ostream& output) {
    int n, k;
    input >> n >> k;

    vector<int> trees(n);
    for (int i = 0; i < n; i++) input >> trees[i];

    vector<int> minSeg = find_min_segment(trees, n, k);
    output << minSeg[0] + 1 << ' ' << minSeg[1] + 1;
}