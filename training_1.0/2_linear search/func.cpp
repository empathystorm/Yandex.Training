#include "func.h"

//частичная сортировка (исп. в task_g и task_h)
void kth_rearrange(std::vector<long>& arr, int left, int right, int k) {
    while (left < right) {
        long x = arr[(left + right) / 2];
        int eqXFirst = left; //первое число, равное x
        int grtXFirst = left; //первое число, больше чем x
        for (int i = left; i <= right; i++) {
            long now = arr[i];
            if (now == x) {
                arr[i] = arr[grtXFirst];
                arr[grtXFirst] = now;
                grtXFirst++;
            } else if (now < x) {
                arr[i] = arr[grtXFirst];
                arr[grtXFirst] = arr[eqXFirst];
                arr[eqXFirst] = now;
                grtXFirst++;
                eqXFirst++;
            }
        }
        if (k < eqXFirst) right = eqXFirst - 1;
        else if (k >= grtXFirst) left = grtXFirst;
        else return;
    }
}