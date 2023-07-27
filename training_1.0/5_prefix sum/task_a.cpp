#include "func.h"
#include <vector>
#define DIFF abs(arr1[l1] - arr2[l2])
#define MIN_VALUES {arr1[l1], arr2[l2]}

using namespace std;

vector<int> input_arr(istream& input, int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        input >> arr[i];
    return arr;
}

vector<int> find_min_diff(vector<int>& arr1, vector<int>& arr2, int n, int m) {
    int l1 = 0, l2 = 0;
    int min = DIFF;
    vector<int> minVal = MIN_VALUES;
    while (l1 < n && l2 < m) {
        if (DIFF < min) {
            min = DIFF;
            minVal = MIN_VALUES;
        }
        if (arr1[l1] < arr2[l2]) l1++;
        else l2++;
    }
    return minVal;
}

void task_a(istream& input, ostream& output) {
    int n, m;
    input >> n;
    vector<int> arr1 = input_arr(input, n);
    input >> m;
    vector<int> arr2 = input_arr(input, m);

    vector<int> minVal = find_min_diff(arr1, arr2, n, m);
    output << minVal[0] << ' ' << minVal[1];
}