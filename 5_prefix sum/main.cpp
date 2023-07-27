#include "func.h"
#include <iostream>
#include <fstream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    task_j(input, output);
}
