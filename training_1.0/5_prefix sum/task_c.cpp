#include "func.h"
#include <vector>

using namespace std;

struct xy { int x, y; };

vector<vector<int> > make_prefix_sum(vector<xy>& mntChain, int n) {
    vector<int> prefSumUp(n + 1, 0), prefSumDown(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int h = mntChain[i].y - mntChain[i-1].y;
        prefSumUp[i] = prefSumUp[i - 1] + (h > 0 ? h : 0); //подъём слева направо ->
        prefSumDown[i] = prefSumDown[i - 1] + (h > 0 ? 0 : -h); //подъём справа налево <-
    }
    return {prefSumUp, prefSumDown};
}

int find_sum_rising(vector<vector<int> >& prefSum, int st, int fin) {
    if (st < fin) return prefSum[0][fin-1] - prefSum[0][st-1];
    else return prefSum[1][st-1] - prefSum[1][fin-1];
}

void task_c(istream& input, ostream& output) {
    int n;
    input >> n;
    vector<xy> mntChain(n);
    for (int i = 0; i < n; i++) input >> mntChain[i].x >> mntChain[i].y;

    vector<vector<int> > prefSum = make_prefix_sum(mntChain, n);

    int m;
    input >> m;
    for (int i = 0; i < m; i++) {
        int st, fin;
        input >> st >> fin;
        output << find_sum_rising(prefSum, st, fin) << '\n';
    }
}