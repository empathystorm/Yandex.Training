#include "func.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void edit_number(string& str) {
    //убрать дефисы
    char to_delete = '-';
    size_t start {str.find(to_delete)};
    while (start != string::npos) {
        str.erase(start, 1);
        start = str.find(to_delete, start + 1);
    }

    //превратить +7 в 8
    if (str[0] == '+') {
        str.replace(0, 2, "8");
    }
    //убрать скобки
    if (str[1] == '(') {
        str.erase(1, 1);
        str.erase(4, 1);
    }
    //короткий номер дополнить
    if (str.length() == 7) {
        str.insert(0, "8495");
    }
}

bool match_numbers(string str1, string str2) {
    edit_number(str1);
    edit_number(str2);
    return str1 == str2;
}

//Телефонные номера
void task_c() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    string mainpn;
    input >> mainpn;

    for (int i = 0; i < 3; i++) {
        string listpn;
        input >> listpn;
        if (match_numbers(mainpn, listpn)) {
            output << "YES\n";
        } else {
            output << "NO\n";
        }
    }
}