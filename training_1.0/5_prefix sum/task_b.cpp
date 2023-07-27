#include "func.h"
#include <vector>
#define MOVE_RIGHT { l += 1; \
                     sum -= arr[l-1]; } //сдвигаем левую границу вправо, корректируем сумму

using namespace std;

int count_k_sum_ranges(vector<int>& arr, long k) {
    long sum = 0;
    int cntRanges = 0, l = 0;
    for (int r = 0; r < arr.size(); r++) {
        sum += arr[r];
        while (sum > k)
            MOVE_RIGHT
        if (sum == k) {
            cntRanges++;
            MOVE_RIGHT
        }
    }
    return cntRanges;
}

void task_b(istream& input, ostream& output) {
    int n; long k;
    input >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) input >> arr[i];

    output << count_k_sum_ranges(arr, k);
}